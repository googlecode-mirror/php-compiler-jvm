#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
//#include "parser_structs.h"
//#include "parser.h"
#include "parser.c"
//#include "lexer.c"
#include <windows.h>


extern int yyparse(void);

extern "C" FILE* yyin;


int main(int argc,char* argv[])
{

	setlocale(LC_ALL,"rus");

	printf("1.%s\n", argv[1]);

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

