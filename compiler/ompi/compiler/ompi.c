/*
  OMPi OpenMP Compiler
  == Copyright since 2001 the OMPi Team
  == Dept. of Computer Science & Engineering, University of Ioannina

  This file is part of OMPi.

  OMPi is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  OMPi is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OMPi; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/*
 * 2014/01/07
 *   integrated ptester
 * 2009/05/10
 *   fixed '#include <string.h>' bug
 */

/* ompi.c -- the starting point */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "ompi.h"
#include "ast.h"
#include "ast_free.h"
#include "ast_gv.h"
#include "ast_csource.h"
#include "ast_xform.h"
#include "ast_show.h"
#include "x_types.h"
#include "x_target.h"
#include "cfg.h"
#include "callgraph.h"
#include "str.h"
#include "config.h"
#include "git_version.h"


static aststmt ast;          /* The AST we use as our original */
symtab         stab;         /* Our symbol table */
bool           testingmode;  /* For internal testing only */
char           *filename;    /* The file we parse */
char           advert[256];  /* A string added to the top of generated files */

/* This is for taking care of main() in the parsed code;
 * OMPi generates its own main() and replaces the original one.
 */
char *MAIN_NEWNAME   = "__original_main";  /* Rename the original main */
bool hasMainfunc     = false; /* true if main() function is defined in the file */
bool needMemcpy      = false; /* true if generated code includes memcpy()s */
bool needMalloc      = false; /* true if generated code includes malloc()s */
bool needLimits      = false; /* true if need limits.h constants (min/max) */
bool needFloat       = false; /* true if need float.h constants (min/max) */
bool nonewmain       = false; /* If true, we won't output a new "main()" */
bool processmode     = false; /* If true, turn on process mode */
bool threadmode      = false; /* Will become true by default */
bool enableOpenMP    = true;  /* If false, ignore OpenMP constructs */
bool enableOmpix     = true;  /* Enable OMPi-extensions */
bool enableCodeDup   = true;  /* Duplicate code where appropriate for speed */
bool cppLineNo       = true;  /* Output precompiler line directives (# n) */
bool showdbginfo     = false; /* Allow assorted debugging info on stderr */
int  mainfuncRettype = 0;     /* 0 = int, 1 = void */

bool show_DAG        = false;	//ljr ture to generate DAG

static str modstr;      /* String containing all used module names */
static int usedmods;    /* # used modules */

/* DF-C */
extern int __has_dfc;
extern char* use_for_df_count;
aststmt dfc_all_df_function_tree;
aststmt dfc_main_subtree_for_ad;
aststmt dfc_main_subtree_for_fn;
aststmt dfc_output_ad_node;
//aststmt dfc_include_tree;

char* MakeSureEnoughSpace(char *p , int length, int *size)
{
	// fprintf(stderr,"%s",p);
	// fprintf(stderr,"11111\n");
	// fprintf(stderr,"address=%p\n",&(*p));
	// fprintf(stderr,"size=%d\n",*size);
	
	// fprintf(stderr,"length=%d\n",length);
	// fprintf(stderr,"*size-length=%d\n",*size-length);
	if(*size-length<2048)
	{
		fprintf(stderr,"扩容\n");
		fprintf(stderr, "sizeof%d\n" ,*size);
		fprintf(stderr, "digraphLength%d\n" ,length);	

		p=(char *)realloc(p,(*size)*2);
		// fprintf(stderr, "digraphLength2222%d\n" ,length);
		*size=*size*2;
		// fprintf(stderr,"address=%p\n",&(*p));
					
	}

	
	return p;
}

aststmt dfc_traverse_dfc_all_df_function_tree_for_globals_and_output_ad_and_print_dot()
{
	aststmt dfc_statistics = verbit("\n");
	aststmt original_state;
	int dfc_output_ad_count = 0;
	int dfc_output_ad_memsize=2048;
	char * dfc_output_ad=(char*)malloc(2048);
	dfc_output_ad[0] = '\0';
	int dfc_output_adLength = 0;
	
	int digraph_memsize=2048;
	char * digraph=(char*)malloc(2048);
	int digraphLength = 0;
	snprintf(digraph + digraphLength, 1024, "digraph\n{\n");
	digraphLength = strlen(digraph);

	for (aststmt dfcEntry = dfc_all_df_function_tree; dfcEntry; dfcEntry = dfcEntry->u.next)       //遍历函数节点
	{
		astdecl outParams = dfcEntry->body->u.declaration.decl->decl->u.dfcvars->outParams;           
		for (astdecl outParamEntry = outParams;													//遍历该节点所有输出
				 outParamEntry;
				 )
		{
			int fanout_count = 0;
			// NOTE(luobin): Find out the name.
			char *name;
			name = dfc_get_decl_identifier_name(outParamEntry);

			for (aststmt innerDfcEntry = dfc_all_df_function_tree;								//为了找到该输出所对去到的输入参数， 需要再遍历一次所有函数节点
					 innerDfcEntry;
					 innerDfcEntry = innerDfcEntry->u.next)
			{
				if(strcmp(innerDfcEntry->body->u.declaration.decl->decl->decl->u.id->name,
				          	   dfcEntry->body->u.declaration.decl->decl->decl->u.id->name) == 0)     //跳过同名函数
				{
					continue;
				}
				
				astdecl inParams = innerDfcEntry->body->u.declaration.decl->decl->u.dfcvars->inParams;
				for (astdecl inParamEntry = inParams;											//遍历该函数的所有输入 并且与之前的输出比对
				     inParamEntry;
						 )
				{
					char *in_name;
					in_name = dfc_get_decl_identifier_name(inParamEntry);

					if(strcmp(name, in_name) == 0)//生产dig图
					{
						snprintf(digraph + digraphLength, 1024,
							"  %s -> %s [label=\"%s\"];\n",
							dfc_get_decl_identifier_name(dfcEntry->body->u.declaration.decl),
							dfc_get_decl_identifier_name(innerDfcEntry->body->u.declaration.decl),
							name);
							
						digraphLength = strlen(digraph);

						digraph=MakeSureEnoughSpace(digraph,digraphLength,&digraph_memsize);

						++fanout_count;;
					}
					
					if (inParamEntry->type == DPARAM)
						break;
					inParamEntry = inParamEntry->u.next;
				}
			}
			
			//dfc_statistics = BlockList(verbit("int DF_fanout_%s = %d;\n", 
			//	                              name, fanout_count),
			//	                       dfc_statistics);
			//dfc_statistics = BlockList(verbit("int DF_persize_%s;", name),
			//								dfc_statistics);
			//dfc_statistics = BlockList(verbit("DF_AD DF_AD_%s;", name), dfc_statistics);

			//wcy
			dfc_statistics = BlockList(dfc_statistics,verbit("int DF_fanout_%s = %d;", 
				                              name, fanout_count)
				                       );
			dfc_statistics = BlockList(dfc_statistics,verbit("int DF_persize_%s;", name)
											);
			dfc_statistics = BlockList(dfc_statistics,verbit("DF_AD DF_AD_%s;\n", name));
			
			if(fanout_count == 0)
			{
				++dfc_output_ad_count;
				snprintf(dfc_output_ad + dfc_output_adLength, 1024,
					", &DF_AD_%s", name);
				dfc_output_adLength = strlen(dfc_output_ad);
				dfc_output_ad=MakeSureEnoughSpace(dfc_output_ad,dfc_output_adLength,&dfc_output_ad_memsize);


				snprintf(digraph + digraphLength, 1024,
					"  %s -> %s [label=\"%s\"];\n",
					dfc_get_decl_identifier_name(dfcEntry->body->u.declaration.decl),
					"TERMINATE", name);
				digraphLength = strlen(digraph);
				digraph=MakeSureEnoughSpace(digraph,digraphLength,&digraph_memsize);


				
				//dfc_statistics = BlockList(verbit("DF_AD DF_AD_%s;", name), dfc_statistics);
				 /*     			BlockList((*detail).body, 
	                             (params->type == DPARAM ? 
								 Declaration(params->spec, params->decl) :
				*/		
				//Declaration(params->decl->spec, params->decl->decl)));

				//dfc_statistics = BlockList(dfc_statistics, verbit("%s %s[DF_COUNT];\n",  SPEC_symbols[outParams->spec->subtype]  ,  name  ));
				//wcy
				dfc_statistics= BlockList(dfc_statistics,verbit("%s %s[%s];\n",  use_params_to_get_spec_name(outParams)  ,  name, use_for_df_count  ));

			}
			
			if(outParamEntry->type == DPARAM)
				break;
			outParamEntry = outParamEntry->u.next;
		}	
	}

	//dfc_statistics = BlockList(verbit("\n"), dfc_statistics);
	//wcy
	dfc_statistics = BlockList(dfc_statistics,verbit("\n"));

	for (aststmt dfcEntry = dfc_all_df_function_tree; dfcEntry; dfcEntry = dfcEntry->u.next)
	{
		//dfc_statistics = BlockList(verbit("DF_FN DF_FN_%s;", 
		//                                  dfc_get_decl_identifier_name(
		//									  dfcEntry->body->u.declaration.decl)),
		//                           dfc_statistics);

		//wcy
		dfc_statistics = BlockList(dfc_statistics,verbit("DF_FN DF_FN_%s;", 
		                                  dfc_get_decl_identifier_name(
											  dfcEntry->body->u.declaration.decl))
		                           );
	}

	dfc_statistics = BlockList(dfc_statistics, verbit("DF_TFL DF_TFL_TABLE;\n"));
	//dfc_statistics = BlockList(dfc_statistics, verbit("int DF_count=DF_COUNT;\n")); //ljr

	//ljr
	if(sched_info)
	{
		dfc_statistics = BlockList(dfc_statistics, verbit("FILE *fp_sche = NULL;\n"));
		dfc_statistics = BlockList(dfc_statistics, verbit("pthread_mutex_t sched_info_mutex;\n"));
		dfc_statistics = BlockList(dfc_statistics, verbit("pid_t gettid() { return syscall(SYS_gettid); }\n"));
		dfc_statistics = BlockList(dfc_statistics, verbit("struct timeval program_start;\n"));		
	}



	dfc_output_ad_node = verbit("DF_OutputInit(&DF_TFL_TABLE, %d%s);\n",	//ljr: 什么意思??必不可少
		dfc_output_ad_count, dfc_output_ad);

	snprintf(digraph + digraphLength, 1024, "}\n");

	if(show_DAG)	//ljr: ture to generate DAG
	{
		fprintf(stderr, "%s" "the dataflow graph will be drawed\n");
		FILE *fp = fopen("digraph.gv", "w");
		if(!fp)
		{
			exit_error(68, "file exists!?\n");
		}
		fprintf(fp, "%s", digraph);
		fclose(fp);
		
		system("dot -Tjpeg digraph.gv -o digraph.jpg");
	}



	if(sched_info)
	{
		fprintf(stderr, "%s\n", "the code will recorde the schedule information\n");
	}


	free(digraph);
	fprintf(stderr, "%s\n", "freedigraph\n");
	free(dfc_output_ad);
	fprintf(stderr, "%s\n", "freedfc_output_ad\n");
	return (dfc_statistics);
}
//wcy
void dfc_insert_include_to_head(void)
{
  	aststmt dfc_include_tree=BlockList(verbit("#include<stdlib.h>"),verbit("#include<stdio.h>"));
	dfc_include_tree=BlockList(dfc_include_tree,verbit("#include<dfc.h>"));
	aststmt t=ast;
  	while (t->u.next->type == STATEMENTLIST)
	{
		t = t->u.next;
	}
	t->u.next=BlockList(dfc_include_tree,t->u.next);
}

aststmt dfc_find_the_first_presence_of_df_function(aststmt t)
{
	aststmt target = NULL;
	while (t->type == STATEMENTLIST)
	{
		if(t->body->type == FUNCDEF && t->body->u.declaration.decl->decl->type == DDFCFUNC)
		{
			target = t;
		}
		if(t->u.next)
			t = t->u.next;
		else
			break;
	};
	//wcy
	if(t->u.next->type==FUNCDEF)
		return t;
	else
		return target;
}

// NOTE(luobin): Put the dfc_statistics before _all_ the dfc functions and 
// behind all the headers.
void dfc_place_dfc_globals_before_any_df_functions(aststmt dfc_statistics)
{
	aststmt targetPoint = ast;
	targetPoint = dfc_find_the_first_presence_of_df_function(targetPoint);
	//aststmt targetNext = targetPoint->u.next;
	//targetPoint->u.next = BlockList(targetNext, dfc_statistics);
	//wcy
	if(targetPoint->u.next->type==FUNCDEF)
	{
		targetPoint->u.next=BlockList(dfc_statistics,targetPoint->u.next);
	}
	else
	{
		targetPoint->u.next=BlockList(targetPoint->u.next,dfc_statistics);
	}
}

void append_new_main()
{
	if (!hasMainfunc) return;
	
	if (usedmods == 0)
		modstr = Str(", \"dummy\"");

	A_str_truncate();
	str_printf(strA(),
	           "/* DF-C-generated main() */\n"
	           "int %s(int argc, char **argv)\n{\n",
	           nonewmain ? "__ompi_main" : "main");

	if(__has_dfc)
	{
		  //ljr:添加调度信息输出文件
		if(sched_info)
		{
			str_printf(strA(), 
								"  gettimeofday(&program_start, NULL);\n"
			 					"  fp_sche = fopen(\"./sched_info.txt\", \"w+\");\n"
			 					"  pthread_mutex_init(&sched_info_mutex, NULL);\n");
		}

		for (aststmt code = dfc_main_subtree_for_ad; code != NULL; code = code->u.next)
		{
			str_printf(strA(), "  %s", code->body->u.code);
		}

		str_printf(strA(), "\n");

		for (aststmt code = dfc_main_subtree_for_fn;
				code != NULL;
				code = code->u.next)
		{
			str_printf(strA(), "  %s", code->body->u.code);
		}

		str_printf(strA(), "\n");

		int dfc_source_func_count = 0;
		int dfc_func_count = 0;
		
		int dfc_source_func_memsize=2048;
		int dfc_func_memsize=2048;
		char * dfc_source_func=(char *)malloc(2048);
		char * dfc_func=(char*)malloc(2048);

		dfc_source_func[0] = '\0';
		dfc_func[0] = '\0';

		int dfc_source_func_length = 0;
		int dfc_func_length = 0;

		for (aststmt dfcEntry = dfc_all_df_function_tree;
				dfcEntry;
				dfcEntry = dfcEntry->u.next)
		{
			++dfc_func_count;
			snprintf(dfc_func + dfc_func_length, 1024, ", &DF_FN_%s",
							(decl_getidentifier_symbol(dfcEntry->body->u.declaration.decl))->name);
			dfc_func_length = strlen(dfc_func);
			dfc_func=MakeSureEnoughSpace(dfc_func,dfc_func_length,&dfc_source_func_memsize);

			astdecl inParams = dfcEntry->body->u.declaration.decl->decl->u.dfcvars->inParams;
			if(!inParams)
			{
				++dfc_source_func_count;
				snprintf(dfc_source_func+dfc_source_func_length, 1024, ", &DF_FN_%s", 
								(decl_getidentifier_symbol(dfcEntry->body->u.declaration.decl))->name);
				dfc_source_func_length = strlen(dfc_source_func);
				dfc_source_func=MakeSureEnoughSpace(dfc_source_func,dfc_source_func_length,&dfc_source_func_memsize);
			}
		}

		str_printf(strA(), "  DF_SourceInit(&DF_TFL_TABLE, %d%s);\n", dfc_source_func_count, dfc_source_func);
		str_printf(strA(), "  DF_Init(&DF_TFL_TABLE, %d%s);\n", dfc_func_count, dfc_func);



		str_printf(strA(), "  %s", dfc_output_ad_node->u.code);
		if(mainfuncRettype == 0)
		{
			str_printf(strA(),
								"  int DF_original_main_ret = (int) %s();\n",
								MAIN_NEWNAME);
			//ljr
			if(sched_info)
			{
				str_printf(strA(), "  fclose(fp_sche);\n");
			}

			str_printf(strA(),
								"  void** result = DF_Result(&DF_TFL_TABLE);\n"
								"  return(DF_original_main_ret);\n");
		}
		else
		{
			str_printf(strA(),
								"  %s();\n"
								"  return(0);\n",
								MAIN_NEWNAME);
		}
		free(dfc_func);
		fprintf(stderr, "%s\n", "dfc_func\n");
		free(dfc_source_func);
		fprintf(stderr, "%s\n", "dfc_source_func\n");

	}

	else
	{

		if (mainfuncRettype == 0)
		{
			if (enableOpenMP || testingmode || processmode)
				str_printf(strA(),
									"  int _xval = 0;\n\n"
									"  ort_initialize(&argc, &argv, %d%s);\n"
									"  _xval = (int) %s(argc, argv);\n"
									"  ort_finalize(_xval);\n"
									"  return (_xval);\n",
									usedmods, str_string(modstr), MAIN_NEWNAME);
			else
				str_printf(strA(),
									"  int _xval = 0;\n\n"
									"  _xval = (int) %s(argc, argv);\n"
									"  return (_xval);\n",
									MAIN_NEWNAME);
			}
			else
			{
				if (enableOpenMP || testingmode || processmode)
					str_printf(strA(),
										"  ort_initialize(&argc, &argv, %d%s);\n"
										"  %s(argc, argv);\n"
										"  ort_finalize(0);\n"
										"  return (0);\n",
										usedmods, str_string(modstr), MAIN_NEWNAME);
				else
					str_printf(strA(),
										"  %s(argc, argv);\n"
										"  return (0);\n",
										MAIN_NEWNAME);
			}
	}
	str_printf(strA(), "}\n");

	ast = BlockList(ast, Verbatim(strdup(A_str_string())));
	ast->u.next->parent = ast; /* Parentize correctly */
	ast->body->parent = ast;

}


/*
 * Options
 */


#define OPTNAME(opt)   "-" #opt
#define OPTNAME_L(opt) "--" #opt "="
#define OPTION(opt)    OPT_##opt

typedef enum {
	OPTION(unknown) = -1, /* unknown option */
	OPTION(nomain) = 0,   OPTION(procs),       OPTION(threads),
	OPTION(nomp),         OPTION(nox),         OPTION(nocodedup),
	OPTION(nolineno),     OPTION(showdbginfo), OPTION(usemod),
	OPTION(show_DAG),	  OPTION(sched_info),	//ljr
	OPTION(lastoption)    /* dummy */		 	
} option_t;

char *optnames[] = {
	OPTNAME(nomain),      OPTNAME(procs),       OPTNAME(threads),
	OPTNAME(nomp),        OPTNAME(nox),         OPTNAME(nocodedup),
	OPTNAME(nolineno),    OPTNAME(showdbginfo), OPTNAME_L(usemod),
	OPTNAME(show_DAG),    OPTNAME(sched_info)	//ljr
};


option_t optid(char *arg)
{
	int i;

	for (i = 0; i < OPTION(lastoption); i++)
		if (optnames[i][1] == '-')     /* Long option */
		{
			if (strncmp(optnames[i], arg, strlen(optnames[i])) == 0)
				return ((option_t) i);
		}
		else
			if (strcmp(optnames[i], arg) == 0)
				return ((option_t) i);
	return OPTION(unknown);
}


int getopts(int argc, char *argv[])
{
	int i;

	modstr = Strnew();
	for (i = 0; i < argc; i++)
		switch ( optid(argv[i]) )
		{
			case OPTION(nomain):      nonewmain = true; break;
			case OPTION(procs):       processmode = true; break;
			case OPTION(threads):     threadmode = true; break;
			case OPTION(nomp):        enableOpenMP = false; break;
			case OPTION(nox):         enableOmpix = false; break;
			case OPTION(nocodedup):   enableCodeDup = false; break;
			case OPTION(nolineno):    cppLineNo = false; break;
			case OPTION(showdbginfo): showdbginfo = true; break;
			case OPTION(usemod):
				str_printf(modstr, ", \"%s\"", argv[i]+strlen(OPTNAME_L(usemod)) );
				usedmods++;
			  break;
			 case OPTION(sched_info): sched_info = true; break;	//ljr
			 case OPTION(show_DAG):	  show_DAG = true;	break;
			default:
				return (1);
		};
	return (0);
}


static
int privatemode(int argc, char *argv[])
{
	enum { GV_STMT = 0, GV_EXPR, CODE_STMT, CODE_EXPR, CFG_SHOW,
		     CFG_SHOW_VERBOSE, CG_SHOW, PRVCMD_LAST /* dummy */
	} cmd;
	struct { char *name, *info; } privcmds[] = {
		{ "gv_stmt",   "print statement node parse tree" },
		{ "gv_expr",   "print expression node parse tree" },
		{ "code_stmt", "print C code for the tree" },
		{ "code_expr", "print C code for the tree" },
		{ "cfg",       "print the CFG for the tree" },
		{ "cfgv",      "print the CFG for the tree with full details" },
		{ "cg",        "print the call graph of a whole program" },
	};

	char    tmp[256];
	aststmt ast;
	astexpr expr;

	MAIN_NEWNAME = "main";    /* Do NOT change it!! */

	if (argc < 3)
	{
	PRIVATEMODE_FAILURE:
		fprintf(stderr, "Usage: %s __internal__ <command> [ file ]\n"
		        "where <command> is one of the following:\n", argv[0]);
		for (cmd = 0; cmd < PRVCMD_LAST; cmd++)
			fprintf(stderr, "%11s   %s\n", privcmds[cmd].name, privcmds[cmd].info);
		return (1);
	}
	filename = (argc > 3) ? argv[3] : NULL;
	for (cmd = 0; cmd < PRVCMD_LAST; cmd++)
		if (strcmp(argv[2], privcmds[cmd].name) == 0)
			break;
	if (cmd == PRVCMD_LAST)
		goto PRIVATEMODE_FAILURE;

	stab = Symtab();                            /* Create the symbol table */
	symtab_put(stab, Symbol("__builtin_va_list"), TYPENAME);
	symtab_put(stab, Symbol("__extension__"), TYPENAME);
	symtab_put(stab, Symbol("__func__"), IDNAME);

	/* Read the file into a string */
	if (1)
	{
		char s[1024];
		FILE *fp;

		if (filename)
		{
			if ((fp = fopen(filename, "r")) == NULL)
				goto PRIVATEMODE_FAILURE;
			A_str_truncate();
			for (; fgets(s, 1024, fp);)
				str_printf(strA(), "%s", s);
			fclose(fp);
		}
		else
		{
			fprintf(stderr, "Enter %s:\n", (cmd == GV_EXPR || cmd == CODE_EXPR) ?
			                "expression" : "statement");
			if (!fgets(s, 1024, stdin))
				exit_error(1, "fgets failed\n");
			str_printf(strA(), "%s", s);
		}
	}

	switch (cmd)
	{
		case GV_STMT:
			ast = parse_blocklist_string(A_str_string());
			if (ast != NULL)
				ast_stmt_gviz_doc(ast, A_str_string());
			break;
		case GV_EXPR:
			expr = parse_expression_string(A_str_string());
			if (expr != NULL)
				ast_expr_gviz_doc(expr, A_str_string());
			break;
		case CODE_STMT:
			ast = parse_blocklist_string(A_str_string());
			if (ast != NULL)
			{
				ast_stmt_csource(ast);
				printf("\n");
			}
			break;
		case CODE_EXPR:
			expr = parse_expression_string(A_str_string());
			if (expr != NULL)
			{
				ast_expr_csource(expr);
				printf("\n");
			}
			break;
		case CFG_SHOW:
		case CFG_SHOW_VERBOSE:
			ast = parse_blocklist_string(A_str_string());
			if (ast != NULL)
			{
				//        if (ast->type == COMPOUND)
				//          linearize(ast->body);
				cfg_test(ast, (cmd == CFG_SHOW) ? 0 : 1);
			}
			break;
		case CG_SHOW:
			ast = parse_transunit_string(A_str_string());
			if (ast != NULL)
				call_graph_test(ast);
			break;
	}
	return (0);
}


#include "ort.defs"


int main(int argc, char *argv[])
{
	time_t  now;
	int     r, includes_omph;
	bool    knowMemcpy, knowSize_t, knowMalloc; /* flag if def'ed in user code */
	aststmt p;

	/*
	 * 1. Preparations
	 */

	if (argc < 2)
	{
	OMPI_FAILURE:
		fprintf(stderr, "** %s should not be run directly; use %scc instead\n",
		        argv[0], argv[0]);
		return (20);
	}

	if (strcmp(argv[1], "__internal__") == 0)
		return (privatemode(argc, argv));
	if (argc < 3)
		goto OMPI_FAILURE;

	if (strcmp(argv[2], "__ompi__") != 0)
	{
		if (strcmp(argv[2], "__intest__") == 0)
			testingmode = 1;
		else
			goto OMPI_FAILURE;
	}
	
	if (argc > 3 && getopts(argc - 3, argv + 3))
		goto OMPI_FAILURE;
		
	filename = argv[1];
	if (!processmode) threadmode = true;  /* By default */

	stab = Symtab();                            /* Create the symbol table */

	/* Take care of GCC */
	symtab_put(stab, Symbol("__builtin_va_list"), TYPENAME);
	symtab_put(stab, Symbol("__extension__"), TYPENAME);

	/* This is a reserved identifier in C99; it is actually supposed to be
	 * "declared" at the top of each function; we simply insert it
	 * @ global scope so it is visible everywhere.
	 */
	symtab_put(stab, Symbol("__func__"), IDNAME);

	/*
	 * 2. Parse & get the AST
	 */

	//ljr: 增加接口参数sche_info
	ast = parse_file(filename, &r);
	if (r) return (r);
	if (ast == NULL)        /* Cannot open file */
	{
		fprintf(stderr, "Error opening file %s for reading!\n", filename);
		return (30);
	}

	if ((!__has_omp || !enableOpenMP) && (!__has_ompix || !enableOmpix)
	    && !hasMainfunc && !testingmode && !processmode)
		return (33);          /* Leave it as is */

	/*
	 * 3. Transform & output
	 */

	/* The parser has left the symbol table at global scope; we must drain it */
	includes_omph = (symtab_get(stab, Symbol("omp_lock_t"), TYPENAME) != NULL);
	knowMemcpy = (symtab_get(stab, Symbol("memcpy"), FUNCNAME) != NULL);
	knowSize_t = (symtab_get(stab, Symbol("size_t"), TYPENAME) != NULL);
	knowMalloc = (symtab_get(stab, Symbol("malloc"), FUNCNAME) != NULL);
	symtab_drain(stab);


	if(!__has_dfc)
	{
		if (hasMainfunc && (enableOpenMP || testingmode || processmode))
		{
			/* Need to declare the ort init/finalize functions */
			p = parse_and_declare_blocklist_string(rtlib_onoff);
			assert(p != NULL);
			if (cppLineNo)
				ast = BlockList(verbit("# 1 \"ort.onoff.defs\""), BlockList(p, ast));
			else
				ast = BlockList(p, ast);
		}

		if ((__has_omp  && enableOpenMP) ||
				(__has_ompix && enableOmpix) || testingmode || processmode)
		{
			aststmt prepend = NULL;

			/* Runtime library definitions */
			if (__has_omp && enableOpenMP)
			{
				/* If <omp.h> was not included, then we must define a few things */
				if (includes_omph)
					p = NULL;
				else
				{
					p = parse_and_declare_blocklist_string(
								"typedef void *omp_nest_lock_t;"   /* The only stuff we needed */
								"typedef void *omp_lock_t; "       /* from <omp.h> */
								"typedef enum omp_sched_t { omp_sched_static = 1,"
								"omp_sched_dynamic = 2,omp_sched_guided = 3,omp_sched_auto = 4"
								" } omp_sched_t;"
								"int omp_in_parallel(void); "
								"int omp_get_thread_num(void); "
								"int omp_get_num_threads(void); "
								"int omp_in_final(void); "         /* 3.1 */
							);
					assert(p != NULL);
					if (cppLineNo) p = BlockList(verbit("# 1 \"omp.mindefs\""), p);
				}

				/* Notice here that any types in omp.h will be defined *after* this */
				prepend = parse_and_declare_blocklist_string(rtlib_defs);
				assert(prepend != NULL);
				if (cppLineNo)
					prepend = BlockList(verbit("# 1 \"ort.defs\""), prepend);
				if (p)
					prepend = BlockList(p, prepend);
				if (__has_affinitysched)
					prepend = BlockList(prepend,
															parse_and_declare_blocklist_string(
																"int ort_affine_iteration(int *);"
															));

				ast = BlockList(prepend, ast);
			}

			if (cppLineNo) ast = BlockList(verbit("# 1 \"%s\"", filename), ast);
			ast = BlockList(ast, verbit("\n"));    /* Dummy node @ bottom */
			ast->file = Symbol(filename);

			ast_parentize(ast);    /* Parentize */
			symtab_drain(stab);    /* Empty it; new globals will be traversed again */

			ast_xform(&ast);       /* The transformation phase */

			time(&now);  /* Advertise us */
			sprintf(advert, "/* File generated from [%s] by %s %s, %s"
											"$OMPi__nfo:%d\n*/",
											filename, PACKAGE_NAME, GIT_VERSION, ctime(&now),
											targetnum);
			p = verbit(advert);    /* Comment @ top & other stuff */

			if (needLimits)
				p = BlockList(p, verbit("#include <limits.h>"));
			if (needFloat)
				p = BlockList(p, verbit("#include <float.h>"));
			if (needMemcpy && !knowMemcpy)
				p = BlockList(
							p,
							verbit("#if _WIN64 || __amd64__ || __X86_64__\n"
										"   extern void *memcpy(void*,const void*,unsigned long int);\n"
										"#else\n"
										"   extern void *memcpy(void*,const void*,unsigned int);\n"
										"#endif"
										)
						);

			ast = BlockList(p, ast);
		}
	}
	
	if(__has_dfc)
	{
		aststmt dfc_statistics = 
			dfc_traverse_dfc_all_df_function_tree_for_globals_and_output_ad_and_print_dot();
			dfc_place_dfc_globals_before_any_df_functions(dfc_statistics);
		//wcy
		dfc_insert_include_to_head();
	}

	append_new_main();

	/* here would be a good place to call e.g. call_graph(); */
	ast_show(ast);

	if (usedmods)             /* No need otherwise */
		produce_target_files(); /* IMPORTANT: global scope is still alive! */

	if (testingmode)
	{
		/* Clean up (not needed actually; we do it only when testing)  */
		ast_free(ast);
		symtab_drain(stab);
		symbols_allfree();
		xt_free_retired();
	}
	return (0);
}


void exit_error(int exitvalue, char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	exit(exitvalue);
}


void warning(char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
}
