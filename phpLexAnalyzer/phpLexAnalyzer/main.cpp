#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "parser_structs.h"
//#include "lexer.c"
#include <windows.h>

//extern "C" union YYSTYPE yylval;
extern "C" FILE* yyin;
extern "C" int yyparse(void);

int main(int argc,char* argv[])
{
	setlocale(LC_ALL,"rus");

	printf("%s\n", argv[1]);

	if(argc>1)
	{
		yyin=fopen(argv[1],"r");
		if (yyin == NULL)
			printf("error\n");
	}
	yyparse();

    //tree_print();

    getch();
}