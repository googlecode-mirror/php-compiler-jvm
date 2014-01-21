#include <locale.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

extern "C"  {
#include "parser.h"
#include "parser.c"
//#include "parser_structs.h"
	}
//#include "lexer.c"
#include <windows.h>

extern "C" FILE* yyin;
extern "C" int yyparse();
extern "C" struct ProgramStruct* root;

int main(int argc,char* argv[])
{
	setlocale(LC_ALL,"rus");

	printf("1.%s\n", argv[1]);

	if(argc>1)
	{
		yyin=fopen(argv[1],"r");
		if (yyin == NULL)
			printf("error\n");
		else
		{
			yyparse();
			/*if (root->info->first->type == t_html)
				printf(root->info->first->html);*/
		}
	}

    //tree_print();

    getch();
}
