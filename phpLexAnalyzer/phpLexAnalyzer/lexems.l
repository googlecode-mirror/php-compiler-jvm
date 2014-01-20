%{
    #include <conio.h>
    #include <string.h>
	#include "parser.h"
	
	extern YYSTYPE yylval;

	int start_condition[64];
	int condition_num = 0;
    char docName[64];
    char lexem[256];
	char html[512] = "";
	void beginCondition();
	void changeStartCondition(int condition);
	void addStartCondition(int condition);
	void returnStartCondition();
	void writeIntToUnion(char* num, char* base);
	void writeBinToUnion(char* num);
	void writeCharToUnion(char* const_char);
	void writeIdToUnion(char* id);
	void writeHtmlToUnion(char* uhtml);
	void printLex(char* lexemName, char* txt);
	void getDocName();
	int docNameCheck(char* name, char* txt);
	int strToNumber(char* num, char* base);
	int strToBin(char* num);
	void strcat_code(char* lex, int code);
	void strcat_strcode(char* lex, char* code);
%}
%option noyywrap
%option never-interactive
%option outfile="lexer.c"

OCT_DIGIT [0-7]
HEX_DIGIT [0-9a-fA-F]
DEC_NUM [1-9][0-9]*|0
OCT_NUM 0[0-7]+
HEX_NUM 0[xX][0-9a-fA-F]+
BIN_NUM 0b[01]+
FIRST_SYMBOL [a-zA-Z_\x7f-\xff]
SYMBOL [a-zA-Z0-9_\x7f-\xff]
ID {FIRST_SYMBOL}{SYMBOL}*

%x PHP
%x STR
%x STR_CONST
%x HEREDOC
%x NOWDOC
%x COMMENT
%x VAR_IN_STR

%%

"<?"php {if (strlen(html) != 0) {writeHtmlToUnion(html);} beginCondition(); addStartCondition(PHP); return HTML;}
<PHP>"?>" {returnStartCondition();}

. strcat(html, yytext);
\n strcat(html, yytext);
<INITIAL><<EOF>> {if (strlen(html) != 0) {writeHtmlToUnion(html); return HTML;} yyterminate();}

<PHP>"<<<"{ID}|(\"{ID}\")$ {getDocName(); strcpy(lexem, ""); addStartCondition(HEREDOC);}
<PHP>"<<<"\'{ID}\'$ {getDocName(); strcpy(lexem, ""); addStartCondition(NOWDOC);}
<PHP>\" {strcpy(lexem, ""); addStartCondition(STR);}
<PHP>\' {strcpy(lexem, ""); addStartCondition(STR_CONST);}

<HEREDOC,NOWDOC>^{ID};?$ {if (docNameCheck(docName, yytext)) {writeCharToUnion(lexem); returnStartCondition(); return CHAR_CONST;} else strcat(lexem, yytext);}
<STR>\" {writeCharToUnion(lexem); returnStartCondition(); return CHAR_CONST;}
<STR_CONST>\' {writeCharToUnion(lexem); returnStartCondition(); return CHAR_CONST;}

<HEREDOC,STR>\${ID} {writeCharToUnion(lexem); strcpy(lexem, yytext+1); unput('1'); addStartCondition(VAR_IN_STR); return CHAR_CONST;}
<VAR_IN_STR>. {writeIdToUnion(lexem); returnStartCondition(); return VARNAME_IN_STR;}

<HEREDOC,STR,NOWDOC,STR_CONST>. strcat(lexem, yytext);
<HEREDOC,STR,NOWDOC,STR_CONST>\n strcat(lexem, yytext);
<HEREDOC,STR,STR_CONST>\\\\ strcat(lexem, "\\");
<STR_CONST>\\\' strcat(lexem, "'");
<STR>\\\" strcat(lexem, "\"");
<HEREDOC,STR>\\n strcat(lexem, "\n");
<HEREDOC,STR>\\r strcat(lexem, "\r");
<HEREDOC,STR>\\t strcat(lexem, "\t");
<HEREDOC,STR>\\v strcat(lexem, "\v");
<HEREDOC,STR>\\f strcat(lexem, "\f");
<HEREDOC,STR>\\\$ strcat(lexem, "$");
<HEREDOC,STR>\\e strcat_code(lexem, 27);
<HEREDOC,STR>\\{OCT_DIGIT}{1,3} strcat_strcode(lexem, yytext);
<HEREDOC,STR>\\x{HEX_DIGIT}{1,2} strcat_strcode(lexem, yytext);

<PHP>"//".*

<PHP>"/*" {BEGIN(COMMENT);}
<COMMENT>"*/" {BEGIN(PHP);}
<COMMENT>.
<COMMENT>\n

<PHP>{DEC_NUM} {writeIntToUnion(yytext, "%d"); return INT_CONST;}
<PHP>{OCT_NUM} {writeIntToUnion(yytext, "%o"); return INT_CONST;}
<PHP>{HEX_NUM} {writeIntToUnion(yytext, "%x"); return INT_CONST;}
<PHP>{BIN_NUM} {writeBinToUnion(yytext); return INT_CONST;}

<PHP>true {yylval.intConstUnionType = 1; return BOOL_CONST;}
<PHP>false {yylval.intConstUnionType = 0; return BOOL_CONST;}

<PHP>array {return ARRAY;}

<PHP>if {return IF;}
<PHP>else {return ELSE;}
<PHP>elseif {return ELSEIF;}
<PHP>switch {return SWITCH;}
<PHP>case {return CASE;}
<PHP>break {return BREAK;}
<PHP>default {return DEFAULT;}

<PHP>for {return FOR;}
<PHP>foreach {return FOREACH;}
<PHP>as {return AS;}
<PHP>do {return DO;}
<PHP>while {return WHILE;}

<PHP>new {return NEW;}
<PHP>class {return CLASS;}
<PHP>this {return TTHIS;}
<PHP>extends {return EXTENDS;}
<PHP>var {return PUBLIC;}
<PHP>public {return PUBLIC;}
<PHP>private {return PRIVATE;}
<PHP>protected {return PROTECTED;}
<PHP>static {return STATIC;}
<PHP>parent {return PARENT;}

<PHP>function {return FUNCTION;}
<PHP>return {return RETURN;}

<PHP>echo {return ECHO;}
<PHP>print {return ECHO;}

<PHP>\${ID} {writeIdToUnion(yytext); return VARNAME;}
<PHP>{ID} {writeIdToUnion(yytext); return ID;}

<PHP>\( {return (unsigned char)'(';}
<PHP>\) {return (unsigned char)')';}
<PHP>\[ {return (unsigned char)'[';}
<PHP>\] {return (unsigned char)']';}
<PHP>\{ {return (unsigned char)'{';}
<PHP>\} {return (unsigned char)'}';}

<PHP>=> {return SETVALUE;}
<PHP>-> {return ARROW;}
<PHP>"." {return (unsigned char)'.';}
<PHP>".=" {return DOTAS;}
<PHP>: {return (unsigned char)':';}
<PHP>:: {return SCOPEOP;}

<PHP>, {return (unsigned char)',';}
<PHP>; {return (unsigned char)';';}

<PHP>! {return (unsigned char)'!';}
<PHP>"||" {return COR;}
<PHP>"&&" {return CAND;}
<PHP>or {return POR;}
<PHP>and {return PAND;}

<PHP>"+" {return (unsigned char)'+';}
<PHP>"+=" {return PLUSAS;}
<PHP>"-" {return (unsigned char)'-';}
<PHP>"-=" {return MINUSAS;}
<PHP>"*" {return (unsigned char)'*';}
<PHP>"*=" {return MULTAS;}
<PHP>"/" {return (unsigned char)'/';}
<PHP>"/=" {return DIVAS;}
<PHP>"%" {return (unsigned char)'%';}
<PHP>"%=" {return MODAS;}
<PHP>"++" {return INC;}
<PHP>"--" {return DEC;}

<PHP>"==" {return EQ;}
<PHP>"!=" {return NEQ;}
<PHP>"<>" {return NEQ;}
<PHP>">" {return (unsigned char)'>';}
<PHP>">=" {return GEQ;}
<PHP>"<" {return (unsigned char)'<';}
<PHP>"<=" {return LEQ;}
<PHP>"===" {return TEQ;}
<PHP>"!==" {return TNEQ;}

<PHP>"=" {return (unsigned char)'=';}

<PHP>[[:SPACE:]]+ ;
<PHP>. printf("character_not_found");

%%

void beginCondition()
{
	start_condition[0] = INITIAL;
}

void addStartCondition(int condition)
{
	condition_num++;
	changeStartCondition(condition);
}

void changeStartCondition(int condition)
{
	start_condition[condition_num] = condition;
	BEGIN(condition);
}

void returnStartCondition()
{
	condition_num--;
	BEGIN(start_condition[condition_num]);
}

void writeIntToUnion(char* num, char* base)
{
	yylval.intConstUnionType = strToNumber(num, base);
}

void writeBinToUnion(char* num)
{
	yylval.intConstUnionType = strToBin(num);
}

void writeCharToUnion(char* const_char)
{
	yylval.charConstUnionType = (char*)malloc(sizeof(char)*256);
	strcpy(yylval.charConstUnionType, const_char);
}

void writeIdToUnion(char* id)
{
	yylval.idUnionType = (char*)malloc(sizeof(char)*100);
	strcpy(yylval.idUnionType, id);
}

void writeHtmlToUnion(char* uhtml)
{
	yylval.htmlUnionType = (char*)malloc(sizeof(char)*512);
	strcpy(yylval.htmlUnionType, uhtml);
	strcpy(uhtml, "");
}

void printLex(char* lexemName, char* txt)
{
	printf("%s found: [%s]\n", lexemName, txt);
}

void getDocName()
{
	if ((yytext[3] == '\"') || (yytext[3] == '\''))
	{
		strcpy(docName, yytext+4);
		docName[strlen(docName)-1] = 0;
	}
	else
		strcpy(docName, yytext+3);
}

int docNameCheck(char* name, char* txt)
{
	char dName[65];
	strcpy(dName, name);
	if(!strcmp(dName, txt) || !strcmp(strcat(dName, ";"), txt))
		return 1;
	else
		return 0;
}

int strToNumber(char* num, char* base)
{
	int number;
	sscanf(num, base, &number);
	return number;
}

int strToBin(char* num)
{
	int number = 0;
	int digit = 1;
	int i;
	for (i = strlen(num)-1; i > 1; i--)
	{
		number += (num[i]-48)*digit;
		digit *= 2;
	}
	return number;
}

void strcat_code(char* lex, int code)
{
	char h[2] = {(code%256), 0};
	strcat(lex, h);
}

void strcat_strcode(char* lex, char* code)
{
	int num;
	char copy[5];
	strcpy(copy, code);
	copy[0] = '0';
	if (copy[1] == 'x')
		sscanf(copy, "%x", &num);
	else
		sscanf(copy, "%o", &num);
	strcat_code(lex, num);
}