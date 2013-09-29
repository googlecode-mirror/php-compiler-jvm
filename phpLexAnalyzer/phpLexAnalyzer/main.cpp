#include <stdio.h>
#include "lex.yy.c"
#include <Windows.h>
#include <fstream>

using namespace std;

int main (int argc,char* argv[]) {
	setlocale(LC_ALL,"rus");
	fstream file(argv[1], ios::in|ios::out|ios::ate);
	file.seekg(-1, ios::end);
	char last;
	file >> last;
	if (last != '\n')
	{
		file.seekp(0, ios::end);
		file << '\n';
	}
	file.close();
	yyin=fopen(argv[1],"r");
	yyout = fopen("result.txt","w");	//сюда будет выводится то что не попало под регулярку
	yylex();
	getch();
}