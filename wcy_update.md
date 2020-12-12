####一.新增功能
1.增添可以通过参数节点返回参数类型的功能。

#####parser.y
```c
  for(int Counter = 0; Counter < detail->out_params_count; ++Counter, params = params->u.next)
  {
    char *name;
    //ljr
  	name = dfc_get_decl_identifier_name(params);
  	dfc_main_subtree_for_ad = BlockList(dfc_main_subtree_for_ad, 
                                          verbit("DF_ADInit(&DF_AD_%s, sizeof(%s), DF_fanout_%s);\n",
                                                 dfc_get_decl_identifier_name(params),
                                                 //wcy
                                                 (params->type == DPARAM) ? use_params_to_get_spec_name(params) :use_params_to_get_spec_name(params->decl) ,
                                                 dfc_get_decl_identifier_name(params)));
  }  

```
```c
//wcy
char* use_params_to_get_spec_name(astdecl params)
{
  char* name=(char *)malloc(200);
  char* tmp_name;
  if(params->spec!=NULL)
  {
    tmp_name=SPEC_symbols[params->spec->subtype];
  }

  //SPEC
  if(params->spec->type==1)
  {
    strcat(name,tmp_name);
    if(params->spec->subtype==16)
    {
    }
    /*
    else if
    ...
    */
    else//一些常见子类型
    {
    }
  }

  //其他五大类
  else
  {
    //SUE
    if(params->spec->type==4)
    {
      strcat(name,tmp_name);
      if(params->spec->subtype==SPEC_struct)//类型为struct的情况
      {
        char* sub_name=params->spec->name->name;
        strcat(name," ");
        strcat(name,sub_name);
      }
    }

    //SPECLIST
    if(params->spec->type==6)
    {
      astspec tmp_spec=params->spec;
      strcat(name,SPEC_symbols[tmp_spec->body->subtype]);
      strcat(name," ");//spec链的情况下空格放在后面

      astdecl tmp_decl=ParamDecl(tmp_spec->u.next,NULL);
      strcat(name,use_decl_to_get_spec_name(tmp_decl));

      //while(tmp_spec->u.next!=NULL)
      //{
      //  tmp_spec=tmp_spec->u.next; 
      //  char* sub_name=SPEC_symbols[tmp_spec->subtype];
      //  strcat(name," ");
      //  strcat(name,sub_name);
      //}
    }

  }

  /*需要考虑一些子结点不存在的情况*/
  if(params->decl!=NULL&&params->decl->spec!=NULL&&params->decl->spec->subtype==SPEC_star)//类型为指针的情况
  {
    char* sub_name=SPEC_symbols[params->decl->spec->subtype];
    strcat(name," ");
    strcat(name,sub_name);
  }


  if(name==NULL)
  {
    return "NULL";
  }
  return name;
}
```

# 
2.取消了在预编译之前链接头文件，改为在之后的编译过程中链接，新增自动添加头文件(增加的原因是#的相关行会在预编译过程中消失)。

#####ompicc.c
>下面代码完成了取消链接过程
```c
void ompicc_compile(char *fname)
{
	
//...
	if (verbose)
		fprintf(stderr, "====> Preprocessing file (%s.c)\n  [ %s ]\n", noext, cmd);
	//wcy,注释掉下面两行
	//if ((res = system(cmd)) != 0)
		//_exit(res);

//...
	/* Transform
	 */
	 //wcy,将一开始的%s.pc改为%s.c
	sprintf(cmd, "%s%s%s \"%s.c\" __ompi__%s%s%s%s%s%s%s%s%s %s > \"%s\"%s",
	        usegdb ? "gdb " : "", /* Run gdb instead of running _ompi directly */
	        RealOmpiName,
	        usegdb ? " -ex 'set args" : "", /* Pass the arguments */
	        noext,
	        strstr(CFLAGS, "OMPI_MAIN=LIB") ? " -nomain " : "",
	        strstr(CFLAGS, "OMPI_MEMMODEL=PROC") == NULL ? "" :
	        strstr(CFLAGS, "OMPI_MEMMODEL=THR") ? " -procs -threads " :
	        " -procs ",
	        disableOpenMP ? " -nomp " : "",
	        disableOmpix ? " -nox " : "",
	        disableCodeDuplication ? " -nocodedup " : "",
	        cppLineNo ? " -nolineno " : "",
	        showdbginfo ? " -showdbginfo" : "",
	        show_DAG ? " -show_DAG" : "",
	        sched_info ? " -sched_info" : "",
	        modules_to_ompi(modulestring),
	        outfile,
	        usegdb ? "'" : "");
	if (verbose)
		fprintf(stderr, "====> Transforming file (%s.c)\n  [ %s ]\n", noext, cmd);
	if ((res = system(cmd)) > 0)
		res = WEXITSTATUS(res);
	if (keep < 2)
	{
		//wcy，注释掉下面一行
		//sprintf(cmd, "%s.pc", noext);               /* remove preprocessed file */
		unlink(cmd);
	}
//...
```

#####ompi.c
```c
int main(int argc, char *argv[])
{
//...
	if(__has_dfc)
	{
		aststmt dfc_statistics = 
			dfc_traverse_dfc_all_df_function_tree_for_globals_and_output_ad_and_print_dot();
			dfc_place_dfc_globals_before_any_df_functions(dfc_statistics);
		//wcy
		dfc_insert_include_to_head();
	}
//...
}
```
```c
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
```

#
3.新增获取itemindex函数，并通过修改编译在函数内部调用使得DF_Source_Stop扩充的DF_FN_itemindex有值

#####dfc.c
```c
//wcy
int use_funcname_to_get_item_index(DF_TFL *table,char* funcname)
{
	for(int i=0;i<table->Num;i++)
	{
		if(strcmp(table->source_list[i].F->Name,funcname)==0)
			return i;
	}
	return -1;
}
```
#####parser.y
```c
//wcy
void dfc_insert_get_item_index(struct dfc_insert_detail *detail,char* name)
{
  (*detail).body = BlockList((*detail).body, verbit("int DF_FN_item_index=use_funcname_to_get_item_index(&DF_TFL_TABLE,\"%s\");"
                ,name));
}
```
# 
4.新增DF_Run有参数(参数是次数)时，扩充的DF_Run的参数会包含此参数

#####parser.y
```c
  | IDENTIFIER '(' argument_expression_list ')'
    {
      //wcy
      if(strcmp($1, "DF_Run") == 0)
      {
        $$ = FunctionCall(IdentName($1), 
                        CommaList(UnaryOperator(UOP_addr, 
                              IdentName("DF_TFL_TABLE")), 
                                      $3));
                                      break;
      }
      /* Catch calls to "main()" (unlikely but possible) */
      $$ = strcmp($1, "main") ?
             FunctionCall(IdentName($1), $3) :
             FunctionCall(IdentName(MAIN_NEWNAME), $3);
    }
```
# 
5.新增对类似int DF_output_A[];的语句进行次数(上述DF_Run里的参数)扩充

>use_for_df_count是char*类型
#####parser.y
```c
      //wcy
      if(strcmp($1, "DF_Run") == 0)
      {
        $$ = FunctionCall(IdentName($1), 
                        CommaList(UnaryOperator(UOP_addr, 
                              IdentName("DF_TFL_TABLE")), 
                                      $3));
                                      //wcy
                                      use_for_df_count=$3->u.str;
                                      break;
      }
```

#####ompi.c
```c
aststmt dfc_traverse_dfc_all_df_function_tree_for_globals_and_output_ad_and_print_dot()
{
//...
				//wcy
				dfc_statistics= BlockList(dfc_statistics,verbit("%s %s[%s];\n",  use_params_to_get_spec_name(outParams)  ,  name, use_for_df_count  ));
//...
}
```
# 
# 
# 
####二.修改错误
1.修正dfc_traverse_dfc_all_df_function_tree_for_globals_and_output_ad_and_print_dot()里Blocklist函数的错误用法

>下面代码中被注释掉的部分是原来的代码，很明显是弄反了Blocklist函数里的两个参数的作用(前一个是节点的u.next，后一个是节点的body)
#####ompi.c
```c
aststmt dfc_traverse_dfc_all_df_function_tree_for_globals_and_output_ad_and_print_dot()
{
//...
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
				dfc_statistics= BlockList(dfc_statistics,verbit("%s %s[DF_COUNT];\n",  SPEC_symbols[outParams->spec->subtype]  ,  name  ));

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
//...
}
```
# 
2.修正了如果#include下面就是函数的话，插入全局变量位置错误的bug

>问题出在原作者弄错了ast树里list的存放方式，list的最后一个是不会被像是STATEMENTLIST，SPECLIST之类的类型的节点给包裹，而是裸露的，所以如果像代码里那样查找的话，如果最后一个节点是函数节点的话，它指向的会是前一个函数节点，从而错误。
#####ompi.c
```c
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
```
```c
aststmt dfc_find_the_first_presence_of_df_function(aststmt t)
{
	aststmt target = NULL;
	while (t->type == STATEMENTLIST)
	{
                //wcy
		if(t->body->type == FUNCDEF) //&& t->body->u.declaration.decl->decl->type == DDFCFUNC)
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
```
# 
3.修正在ompi.c里进行调用use_params_to_get_spec_name函数时，一开始的name会有残留乱码字符的bug

#####parser.y
```c
//wcy
char* use_params_to_get_spec_name(astdecl params)
{
  char* name=(char *)malloc(200);
  //wcy
  memset(name,0,200); 
//...
}
``` 

# 
4.在非源函数里插入int DF_FN_item_index=use_funcname_to_get_item_index(&DF_TFL_TABLE,"FUNS");类似的语句会出错，修正在非源函数里不会插入这样的语句

>加个判断条件
#####parser.y
```c
//wcy
void dfc_insert_get_item_index(struct dfc_insert_detail *detail,char* name)
{
  //wcy
  if(detail->inParams==NULL)
  	(*detail).body = BlockList((*detail).body, verbit("int DF_FN_item_index=use_funcname_to_get_item_index(&DF_TFL_TABLE,\"%s\");"
                ,name));
}

```
# 
# 
# 
####结果
>编译前
```c
void SOURCEA(;int DF_Source_A)
{
        DF_Source_A = DF_count;
        if (DF_count == 9)
        {
            DF_Source_Stop();
        }
}
void SOURCEB(;int DF_Source_B)
{
        DF_Source_B = 100 - DF_count;
        if (DF_count == 9)
        {
            DF_Source_Stop();
        }
}
void FUNS(int DF_Source_A, int DF_Source_B; int DF_output_A)
{
        DF_output_A = DF_Source_A + DF_Source_B;
        printf("total: -- %d\n", DF_output_A);
}
int main()
{
        DF_Run(10);
        return 0;
}
```

# 
>编译后
```c
#include<stdlib.h>
#include<stdio.h>
#include<dfc.h>


int DF_fanout_DF_output_A = 0;
int DF_persize_DF_output_A;
DF_AD DF_AD_DF_output_A;

int DF_output_A[10];

int DF_fanout_DF_Source_B = 1;
int DF_persize_DF_Source_B;
DF_AD DF_AD_DF_Source_B;

int DF_fanout_DF_Source_A = 1;
int DF_persize_DF_Source_A;
DF_AD DF_AD_DF_Source_A;



DF_FN DF_FN_FUNS;
DF_FN DF_FN_SOURCEB;
DF_FN DF_FN_SOURCEA;
DF_TFL DF_TFL_TABLE;


void SOURCEA(/* DF-C function */)
{
  int DF_count;

int DF_Source_A;

  DF_persize_DF_Source_A = sizeof(DF_Source_A);
  DF_SOURCE_Get_And_Update(&DF_FN_SOURCEA, &DF_count);
int DF_FN_item_index=use_funcname_to_get_item_index(&DF_TFL_TABLE,"SOURCEA");
{
  DF_Source_A = DF_count;
  if (DF_count == 9)
    {
      DF_Source_Stop(&DF_TFL_TABLE, DF_FN_item_index);
    }
}
  DF_AD_UpData(DF_count,&DF_TFL_TABLE, &DF_FN_SOURCEA, &DF_Source_A, DF_persize_DF_Source_A);

}


void SOURCEB(/* DF-C function */)
{
  int DF_count;

int DF_Source_B;

  DF_persize_DF_Source_B = sizeof(DF_Source_B);
  DF_SOURCE_Get_And_Update(&DF_FN_SOURCEB, &DF_count);
int DF_FN_item_index=use_funcname_to_get_item_index(&DF_TFL_TABLE,"SOURCEB");
{
  DF_Source_B = 100 - DF_count;
  if (DF_count == 9)
    {
      DF_Source_Stop(&DF_TFL_TABLE, DF_FN_item_index);
    }
}
  DF_AD_UpData(DF_count,&DF_TFL_TABLE, &DF_FN_SOURCEB, &DF_Source_B, DF_persize_DF_Source_B);

}


void FUNS(/* DF-C function */)
{
int DF_Source_B;

  DF_persize_DF_Source_B = sizeof(DF_Source_B);
int DF_Source_A;

  DF_persize_DF_Source_A = sizeof(DF_Source_A);
int DF_output_A;

  DF_persize_DF_output_A = sizeof(DF_output_A);
  int DF_count = DF_AD_GetData(&DF_FN_FUNS, &DF_Source_B, DF_persize_DF_Source_B, &DF_Source_A, DF_persize_DF_Source_A);
{
  DF_output_A = DF_Source_A + DF_Source_B;
  printf("total: -- %d\n", DF_output_A);
}
  DF_AD_UpData(DF_count,&DF_TFL_TABLE, &DF_FN_FUNS, &DF_output_A, DF_persize_DF_output_A);

}


int __original_main()
{
  DF_Run(&DF_TFL_TABLE, 10);
  return (0);
}

/* DF-C-generated main() */
int main(int argc, char **argv)
{
  DF_ADInit(&DF_AD_DF_output_A, sizeof(int), DF_fanout_DF_output_A);
  DF_ADInit(&DF_AD_DF_Source_B, sizeof(int), DF_fanout_DF_Source_B);
  DF_ADInit(&DF_AD_DF_Source_A, sizeof(int), DF_fanout_DF_Source_A);

  DF_FNInit1(&DF_FN_FUNS, &FUNS, "FUNS", 2, &DF_AD_DF_Source_B, &DF_AD_DF_Source_A);
  DF_FNInit2(&DF_FN_FUNS, 1, &DF_AD_DF_output_A);
  DF_FNInit1(&DF_FN_SOURCEB, &SOURCEB, "SOURCEB", 0);
  DF_FNInit2(&DF_FN_SOURCEB, 1, &DF_AD_DF_Source_B);
  DF_FNInit1(&DF_FN_SOURCEA, &SOURCEA, "SOURCEA", 0);
  DF_FNInit2(&DF_FN_SOURCEA, 1, &DF_AD_DF_Source_A);

  DF_SourceInit(&DF_TFL_TABLE, 2, &DF_FN_SOURCEB, &DF_FN_SOURCEA);
  DF_Init(&DF_TFL_TABLE, 3, &DF_FN_FUNS, &DF_FN_SOURCEB, &DF_FN_SOURCEA);
  DF_OutputInit(&DF_TFL_TABLE, 1, &DF_AD_DF_output_A);
  int DF_original_main_ret = (int) __original_main();
  void** result = DF_Result(&DF_TFL_TABLE);
  return(DF_original_main_ret);
}
```

# 
>运行结果
```c
root@aegis-virtual-machine:/mnt/hgfs/dfc/dfc-new/dfc运行库/test# ./a_dfc
total: -- 100
total: -- 100
total: -- 100
total: -- 100
total: -- 100
total: -- 100
total: -- 100
total: -- 100
root@aegis-virtual-machine:/mnt/hgfs/dfc/dfc-new/dfc运行库/test# 
```