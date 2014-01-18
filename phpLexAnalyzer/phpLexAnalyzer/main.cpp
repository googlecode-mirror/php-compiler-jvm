#include <conio.h>
#include <stdio.h>
#include <string.h>
#include "bison_input.yacc_tab.h"
//#include "lex.yy.c"
#include <windows.h>

//extern "C" union YYSTYPE yylval;
extern "C" FILE* yyin;
extern "C" int yyparse(void);

/*
int main(int paramsCount, char ** inparams)
{
	yyout = fopen("result.txt","w");	//сюда будет выводится то что не попало под регулярку
	yyin = fopen("phpCodeToAnalyze.txt","r");
	yylex();
	return 0;
}
*//**/
int main(int argc,char* argv[]) {
		
	//setlocale(LC_ALL,"rus");
    //yyin=fopen(argv[1],"r");	
	//yyout=fopen("result.txt","w");	//сюда будет выводится то что не попало под регулярку
    //yylex();
    //getch();
	

	printf("%s\n", argv[1]);

	if(argc>1)
	{
		yyin=fopen(argv[1],"r");
		if (yyin == NULL)
			printf("error\n");
	}
	yyparse();

    //yyparse();
    //tree_print();

    getch();
}