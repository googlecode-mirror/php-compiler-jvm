#include <stdio.h>
#include "lex.yy.c"
#include <Windows.h>
/*
int main(int paramsCount, char ** inparams)
{
	yyout = fopen("result.txt","w");	//���� ����� ��������� �� ��� �� ������ ��� ���������
	yyin = fopen("phpCodeToAnalyze.txt","r");
	yylex();
	return 0;
}*/int main (int argc,char* argv[]) {
	setlocale(LC_ALL,"rus");

    yyin=fopen(argv[1],"r");
	yyout = fopen("result.txt","w");	//���� ����� ��������� �� ��� �� ������ ��� ���������
    yylex();
    getch();
}