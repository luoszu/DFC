#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void headerinsert(FILE *fp);
void df_funinsert1(FILE *fp,int times);
void df_funinsert2(FILE *fp,int times);
void df_sourcefun(FILE *fp);
void df_mainsert(FILE *fp);
int main()
{
   

   FILE *fp = NULL;
   int times=0;
   scanf("%d",&times);
   fp = fopen("/tmp/test.c", "w+");
   //fprintf(fp, "This is testing for fprintf...\n");
   //fputs("This is testing for fputs...\n", fp);
   headerinsert(fp);
   df_sourcefun(fp);
   df_funinsert1(fp,times);
   df_funinsert2(fp,times);
   df_mainsert(fp);
   fclose(fp);
    return 0;
}

void headerinsert(FILE *fp)
{
    
   /* char temp[]= "#include <time.h>\n\
#include <stdio.h>\n\
#include <stdlib.h>\n\
#include <sys/time.h>\n\
#include \"data.h\" \n";*/
    char temp[] ="#define AA 100\n";

    fprintf(fp,"%s",temp);
}
                 
void df_sourcefun(FILE *fp)
{
    fprintf(fp,"void SOURCE(   ; int data0_0 )\n\
    {\n\
    data0_0=DF_count;\n\
    }\n");
}
void df_funinsert1(FILE *fp,int times)
{
    char temp[] ="void ";
    for(int i=1;i<=times;i++)
    {
        for(int j=0;j<pow(2,i);j++)
        {
            fprintf(fp,"void Node%d_%d (  int data%d_%d  ; int data%d_%d  )\n", i,j ,i-1,j/2 ,i,j );
            fprintf(fp,"{\n\
            data%d_%d=data%d_%d;\n\
            for(int i=0;i<10000;i++)\n\
            {\n\
            data%d_%d++;\n\
            }\n\
            }\n",  i,j ,   i-1,j/2  ,   i, j   );

        }



    }
}

void df_funinsert2(FILE *fp,int times)
{
    for(int i=times+1;i<=times*2;i++)
    {
        for(int j=0;j<pow(2,times*2-i);j++)
        {
            fprintf(fp,"void Node%d_%d (  int data%d_%d  , int data%d_%d; int data%d_%d  )\n", 
                                  i, j,          i-1,j*2,         i-1, j*2+1,     i,j );
            fprintf(fp,"{\n\
            data%d_%d=data%d_%d+data%d_%d;\n\
            for(int i=0;i<10000;i++)\n\
            {\n\
            data%d_%d++;\n\
            }\n\
            }\n",  i,j ,  i-1,j*2,         i-1, j*2+1, i, j   );

        }

    }

}

void df_mainsert(FILE *fp)
{

    fprintf(fp,"void main()");
    fprintf(fp,"{ \n\
    DF_Run();\n\
    }\n");
}