
/*  A Bison parser, made from grammar.c with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	INT_CONST	258
#define	BOOL_CONST	259
#define	CHAR_CONST	260
#define	HTML	261
#define	ARRAY	262
#define	IF	263
#define	ELSE	264
#define	ELSEIF	265
#define	SWITCH	266
#define	CASE	267
#define	BREAK	268
#define	DEFAULT	269
#define	FOR	270
#define	FOREACH	271
#define	AS	272
#define	DO	273
#define	WHILE	274
#define	NEW	275
#define	CLASS	276
#define	THIS	277
#define	EXTENDS	278
#define	PUBLIC	279
#define	PRIVATE	280
#define	PROTECTED	281
#define	STATIC	282
#define	PARENT	283
#define	FUNCTION	284
#define	RETURN	285
#define	ECHO	286
#define	ID	287
#define	VARNAME	288
#define	VARNAME_IN_STR	289
#define	SETVALUE	290
#define	ARROW	291
#define	SCOPEOP	292
#define	COR	293
#define	CAND	294
#define	POR	295
#define	PAND	296
#define	PLUSAS	297
#define	MINUSAS	298
#define	MULTAS	299
#define	DIVAS	300
#define	MODAS	301
#define	INC	302
#define	DEC	303
#define	EQ	304
#define	NEQ	305
#define	GEQ	306
#define	LEQ	307
#define	TEQ	308
#define	TNEQ	309
#define	UPLUS	310
#define	UMINUS	311

#line 1 "grammar.c"

#include "parser_structs.h"
#include <stdio.h>
#include <malloc.h>

void yyerror(char const *s);
extern int yylex(void);

struct ProgramStruct* root;

struct ConstValueStruct* createConst(int new_const, enum ConstValueType type);
struct ConstValueStruct* createCharConst(char* new_const);
struct ExprStruct* createConstExpr(struct ConstValueStruct* new_const_value);
struct ExprStruct* createExpr(struct ExprStruct* left, struct ExprStruct* right, enum ExprType type);
struct ExprStruct* createUExpr(struct ExprStruct* left, enum ExprType type);
struct ExprStruct* createVarExpr(struct VarStruct* new_var);
struct ExprStruct* createStrExpr(struct StringStruct* new_str);
struct ExprStruct* createArrayExpr(struct ArrayStruct* new_array);
struct ExprStruct* createFuncCallExpr(char* new_id, struct ExprListStruct* new_list);
struct ExprListStruct* createExprList(struct ExprStruct* new_expr);
struct ExprListStruct* addExprToExprList(struct ExprListStruct* expr_list, struct ExprStruct* new_expr);
struct StringStruct* createString(char* first_char_const, char* first_varname, char* second_char_const);
struct StringStruct* addElementToString(struct StringStruct* current_string, char* varname, char* char_const);
struct VarElementStruct* createVariableFieldElement(char* new_member);
struct VarElementStruct* createVariableMethodElement(char* new_member, struct ExprListStruct* new_params);
struct VarElementStruct* createVariableIndexElement(struct ExprStruct* new_index);
struct VarElementListStruct* createElementsList(struct VarElementStruct* new_element);
struct VarElementListStruct* addElementToElementsList(struct VarElementListStruct* current_list, struct VarElementStruct* new_element);
struct VarStruct* createVariable(char* new_id, struct VarElementListStruct* new_list);
struct VarListElementStruct* createVarListElement(char* new_id);
struct VarListElementStruct* createVarListElementWithValue(char* new_id, struct ExprStruct* new_value);
struct VarListStruct* createVarList(struct VarListElementStruct* new_element);
struct VarListStruct* addElementToVarList(struct VarListStruct* current_list, struct VarListElementStruct* new_element);
struct ArrayElementStruct* createArrayElement(struct ExprStruct* new_value);
struct ArrayElementStruct* createArrayElementWithValue(struct ExprStruct* new_key, struct ExprStruct* new_value);
struct ArrayStruct* createArrayElementsList(struct ArrayElementStruct* new_element);
struct ArrayStruct* addElementToArrayElementsList(struct ArrayStruct* current_list, struct ArrayElementStruct* new_element);
struct IfStmtStruct* createIfStmt(struct ExprStruct* new_condition, struct StmtStruct* new_stmt);
struct IfStmtStruct* createIfElseStmt(struct ExprStruct* new_condition, struct StmtStruct* new_stmt, struct StmtStruct* new_else_stmt);
struct IfStmtStruct* createIfElseIfStmt(struct ExprStruct* new_condition, struct StmtStruct* new_stmt, struct IfStmtStruct* new_elseif_stmt);
struct CaseStruct* createCaseStmt(struct ExprStruct* new_expr, struct StmtListStruct* new_stmt_list);
struct CaseStmtListStruct* createCaseStmtList(struct CaseStruct* new_element);
struct CaseStmtListStruct* addCaseStmtToCaseStmtList(struct CaseStmtListStruct* current_list, struct CaseStruct* new_element);
struct SwitchStmtStruct* createSwitchStmt(struct ExprStruct* new_expr, struct CaseStmtListStruct* new_case_list);
struct SwitchStmtStruct* createSwitchStmtWithDefault(struct ExprStruct* new_expr, struct CaseStmtListStruct* new_case_list, struct StmtListStruct* new_default_stmt);
struct ForStmtStruct* createForStmt(struct ExprStruct* new_start_expr, struct ExprStruct* new_condition, struct ExprStruct* new_end_action, struct StmtListStruct* new_stmt);
struct WhileStmtStruct* createWhileStmt(struct ExprStruct* new_condition, struct StmtListStruct* new_stmt, enum WhileType new_type);
struct ForeachStmtStruct* createForeachStmt(struct ExprStruct* new_array, char* new_value, struct StmtListStruct* new_stmt);
struct ForeachStmtStruct* createForeachStmtWithKey(struct ExprStruct* new_array, char* new_key, char* new_value, struct StmtListStruct* new_stmt);
struct StmtStruct* createStmtExpr(struct ExprStruct* new_expr);
struct StmtStruct* createStmtIf(struct IfStmtStruct* new_if_stmt);
struct StmtStruct* createStmtSwitch(struct SwitchStmtStruct* new_switch_stmt);
struct StmtStruct* createStmtFor(struct ForStmtStruct* new_for_stmt);
struct StmtStruct* createStmtWhile(struct WhileStmtStruct* new_while_stmt);
struct StmtStruct* createStmtForeach(struct ForeachStmtStruct* new_foreach_stmt);
struct StmtStruct* createStmtFuncDef(struct FuncDefStruct* new_func_def);
struct StmtStruct* createStmtEcho(struct ExprStruct* new_expr);
struct StmtStruct* createStmtBreak();
struct StmtStruct* createStmtReturn(struct ExprStruct* new_expr);
struct StmtStruct* createStmtStmtlist(struct StmtListStruct* new_list);
struct StmtStruct* createStmtVoid();
struct StmtListStruct* createStmtList(struct StmtStruct* new_element);
struct StmtListStruct* addStmtToStmtList(struct StmtListStruct* current_list, struct StmtStruct* new_element);
struct FuncDefStruct* createFuncDef(char* new_id, struct VarListStruct* new_var_list, struct StmtListStruct* new_stmt_list);
struct FieldStruct* createField(char* new_id, enum ProtectionType new_protection_type);
struct ClassBodyElementStruct* createFieldElement(struct FieldStruct* new_field);
struct ClassBodyElementStruct* createFieldWithValue(struct FieldStruct* new_field, struct ConstValueStruct* new_const_value);
struct ClassBodyElementStruct* createMethod(struct FuncDefStruct* new_func, enum ProtectionType new_protection_type);
struct ClassBodyElementsListStruct* createBody(struct ClassBodyElementStruct* new_element);
struct ClassBodyElementsListStruct* addElementToBody(struct ClassBodyElementsListStruct* current_list, struct ClassBodyElementStruct* new_element);
struct ClassDefStruct* createClass(char* new_id, struct ClassBodyElementsListStruct* new_body);
struct ClassDefStruct* createExtendedClass(char* new_id, char* new_parentId, struct ClassBodyElementsListStruct* new_body);
struct MainStmtStruct* createMainStmtClass(struct ClassDefStruct* new_class_def);
struct MainStmtStruct* createMainStmt(struct ClassDefStruct* new_stmt);
struct MainStmtListStruct* createMainStmtList(struct MainStmtStruct* new_element);
struct MainStmtListStruct* addMainStmtToMainStmtList(struct MainStmtListStruct* current_list, struct MainStmtStruct* new_element);
struct ProgramStmtStruct* createProgramStmtMainStmtList(struct MainStmtListStruct* new_main_stmt_list);
struct ProgramStmtStruct* createProgramStmtHtml(char* new_html);
struct ProgramStmtListStruct* createProgramStmtList(struct ProgramStmtStruct* new_element);
struct ProgramStmtListStruct* addProgramStmtToProgramStmtList(struct ProgramStmtListStruct* current_list, struct ProgramStmtStruct* new_element);
struct ProgramStruct* createProgram(struct ProgramStmtListStruct* new_info);

#line 85 "grammar.c"
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union { //yylval
	int intConstUnionType;
	char* charConstUnionType;
	char* idUnionType;
	char* htmlUnionType;
	
	struct ConstValueStruct* ConstValueUnion;
	struct ExprStruct* ExprUnion;
	struct ExprListStruct* ExprListUnion;
	struct StringStruct* StringUnion;
	struct VarElementStruct* VarElementUnion;
	struct VarElementListStruct* VarElementListUnion;
	struct VarStruct* VarUnion;
	struct VarListElementStruct* VarListElementUnion;
	struct VarListStruct* VarListUnion;
	struct ArrayElementStruct* ArrayElementUnion;
	struct ArrayStruct* ArrayUnion;
	struct IfStmtStruct* IfStmtUnion;
	struct CaseStruct* CaseUnion;
	struct CaseStmtListStruct* CaseStmtListUnion;
	struct SwitchStmtStruct* SwitchStmtUnion;
	struct ForStmtStruct* ForStmtUnion;
	struct WhileStmtStruct* WhileStmtUnion;
	struct ForeachStmtStruct* ForeachStmtUnion;
	struct StmtStruct* StmtUnion;
	struct StmtListStruct* StmtListUnion;
	struct FuncDefStruct* FuncDefUnion;
	struct FieldStruct* FieldUnion;
	struct ClassBodyElementStruct* ClassBodyElementUnion;
	struct ClassBodyElementsListStruct* ClassBodyElementsListUnion;
	struct ClassDefStruct* ClassDefUnion;
	struct MainStmtStruct* MainStmtUnion;
	struct MainStmtListStruct* MainStmtListUnion;
	struct ProgramStmtStruct* ProgramStmtUnion;
	struct ProgramStmtListStruct* ProgramStmtListUnion;
	struct ProgramStruct* ProgramUnion;
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		248
#define	YYFLAG		-32768
#define	YYNTBASE	76

#define YYTRANSLATE(x) ((unsigned)(x) <= 311 ? yytranslate[x] : 114)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    65,     2,     2,     2,    64,     2,     2,    71,
    68,    62,    59,    55,    60,    61,    63,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    72,    75,    58,
    56,    57,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    70,     2,    69,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    73,     2,    74,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    66,
    67
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    13,    16,    18,    20,
    22,    24,    26,    28,    32,    36,    40,    44,    48,    52,
    56,    60,    64,    67,    71,    75,    79,    83,    87,    91,
    95,    99,   103,   106,   109,   113,   117,   121,   125,   129,
   133,   136,   139,   142,   145,   147,   149,   154,   159,   161,
   165,   166,   168,   169,   171,   175,   179,   182,   188,   192,
   194,   197,   198,   200,   203,   205,   209,   211,   215,   217,
   221,   223,   227,   228,   230,   236,   244,   251,   257,   265,
   272,   277,   279,   282,   290,   300,   310,   320,   326,   334,
   344,   347,   349,   351,   353,   355,   357,   359,   361,   364,
   367,   371,   375,   377,   379,   382,   383,   385,   394,   397,
   400,   403,   406,   411,   413,   416,   419,   422,   424,   427,
   428,   430,   436
};

static const short yyrhs[] = {    77,
     0,    78,     0,    77,    78,     0,    79,     0,     6,     0,
    80,     0,    79,    80,     0,   113,     0,   105,     0,     3,
     0,     4,     0,     5,     0,    81,     0,    71,    82,    68,
     0,    82,    58,    82,     0,    82,    52,    82,     0,    82,
    57,    82,     0,    82,    51,    82,     0,    82,    49,    82,
     0,    82,    50,    82,     0,    82,    53,    82,     0,    82,
    54,    82,     0,    65,    82,     0,    82,    38,    82,     0,
    82,    39,    82,     0,    82,    40,    82,     0,    82,    41,
    82,     0,    82,    59,    82,     0,    82,    60,    82,     0,
    82,    62,    82,     0,    82,    63,    82,     0,    82,    64,
    82,     0,    59,    82,     0,    60,    82,     0,    82,    56,
    82,     0,    82,    42,    82,     0,    82,    43,    82,     0,
    82,    44,    82,     0,    82,    45,    82,     0,    82,    46,
    82,     0,    82,    47,     0,    82,    48,     0,    47,    82,
     0,    48,    82,     0,    90,     0,    86,     0,     7,    71,
    95,    68,     0,    32,    71,    84,    68,     0,    82,     0,
    83,    55,    82,     0,     0,    83,     0,     0,    82,     0,
     5,    34,     5,     0,    86,    34,     5,     0,    36,    32,
     0,    36,    32,    71,    84,    68,     0,    70,    82,    69,
     0,    87,     0,    88,    87,     0,     0,    88,     0,    33,
    89,     0,    33,     0,    33,    56,    82,     0,    91,     0,
    92,    55,    91,     0,    82,     0,    82,    35,    82,     0,
    93,     0,    94,    55,    93,     0,     0,    94,     0,     8,
    71,    82,    68,   105,     0,     8,    71,    82,    68,   105,
     9,   105,     0,     8,    71,    82,    68,   105,    97,     0,
    10,    71,    82,    68,   105,     0,    10,    71,    82,    68,
   105,     9,   105,     0,    10,    71,    82,    68,   105,    97,
     0,    12,    82,    72,   107,     0,    98,     0,    99,    98,
     0,    11,    71,    82,    68,    73,    99,    74,     0,    11,
    71,    82,    68,    73,    99,    14,    72,   107,     0,    15,
    71,    85,    75,    85,    75,    85,    68,   105,     0,    18,
    73,   105,    74,    19,    71,    82,    68,    75,     0,    19,
    71,    82,    68,   105,     0,    16,    71,    82,    17,    33,
    68,   105,     0,    16,    71,    82,    17,    33,    35,    33,
    68,   105,     0,    82,    75,     0,    96,     0,   100,     0,
   101,     0,   102,     0,   103,     0,   104,     0,   108,     0,
    31,    82,     0,    13,    75,     0,    30,    85,    75,     0,
    73,   107,    74,     0,    75,     0,   105,     0,   106,   105,
     0,     0,   106,     0,    29,    32,    71,    92,    68,    73,
   107,    74,     0,    24,    33,     0,    25,    33,     0,    26,
    33,     0,   109,    75,     0,   109,    56,    81,    75,     0,
   108,     0,    24,   108,     0,    25,   108,     0,    26,   108,
     0,   110,     0,   111,   110,     0,     0,   111,     0,    21,
    32,    73,   112,    74,     0,    21,    32,    23,    32,    73,
   112,    74,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   209,   213,   215,   218,   220,   223,   225,   228,   230,   234,
   236,   237,   241,   243,   244,   245,   246,   247,   248,   249,
   250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
   260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
   270,   271,   272,   273,   274,   275,   276,   277,   280,   282,
   285,   287,   290,   292,   296,   298,   302,   304,   307,   310,
   312,   315,   317,   320,   324,   326,   329,   331,   335,   337,
   340,   342,   345,   347,   351,   353,   354,   357,   359,   360,
   363,   367,   369,   372,   374,   378,   382,   386,   390,   392,
   396,   398,   399,   400,   401,   402,   403,   404,   405,   406,
   407,   408,   409,   412,   414,   417,   419,   423,   428,   430,
   431,   434,   436,   437,   438,   439,   440,   443,   445,   448,
   450,   453,   455
};

static const char * const yytname[] = {   "$","error","$undefined.","INT_CONST",
"BOOL_CONST","CHAR_CONST","HTML","ARRAY","IF","ELSE","ELSEIF","SWITCH","CASE",
"BREAK","DEFAULT","FOR","FOREACH","AS","DO","WHILE","NEW","CLASS","THIS","EXTENDS",
"PUBLIC","PRIVATE","PROTECTED","STATIC","PARENT","FUNCTION","RETURN","ECHO",
"ID","VARNAME","VARNAME_IN_STR","SETVALUE","ARROW","SCOPEOP","COR","CAND","POR",
"PAND","PLUSAS","MINUSAS","MULTAS","DIVAS","MODAS","INC","DEC","EQ","NEQ","GEQ",
"LEQ","TEQ","TNEQ","','","'='","'>'","'<'","'+'","'-'","'.'","'*'","'/'","'%'",
"'!'","UPLUS","UMINUS","')'","']'","'['","'('","':'","'{'","'}'","';'","program",
"program_stmt_list","program_stmt","main_stmt_list","main_stmt","const_value",
"expr","expr_list_ne","expr_list","expr_e","string","variable_element","variable_element_list_ne",
"variable_element_list","variable","var_list_element","var_list","array_element",
"array_ne","array","if_stmt","else_if_stmt","case_stmt","case_stmt_list","switch_stmt",
"for_stmt","do_while_stmt","while_stmt","foreach_stmt","stmt","stmt_list_ne",
"stmt_list","function_declaration","field_name","class_body_element","class_body_ne",
"class_body","class_def",""
};
#endif

static const short yyr1[] = {     0,
    76,    77,    77,    78,    78,    79,    79,    80,    80,    81,
    81,    81,    82,    82,    82,    82,    82,    82,    82,    82,
    82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
    82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
    82,    82,    82,    82,    82,    82,    82,    82,    83,    83,
    84,    84,    85,    85,    86,    86,    87,    87,    87,    88,
    88,    89,    89,    90,    91,    91,    92,    92,    93,    93,
    94,    94,    95,    95,    96,    96,    96,    97,    97,    97,
    98,    99,    99,   100,   100,   101,   102,   103,   104,   104,
   105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
   105,   105,   105,   106,   106,   107,   107,   108,   109,   109,
   109,   110,   110,   110,   110,   110,   110,   111,   111,   112,
   112,   113,   113
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     1,     2,     1,     1,     1,
     1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     2,     2,     3,     3,     3,     3,     3,     3,
     2,     2,     2,     2,     1,     1,     4,     4,     1,     3,
     0,     1,     0,     1,     3,     3,     2,     5,     3,     1,
     2,     0,     1,     2,     1,     3,     1,     3,     1,     3,
     1,     3,     0,     1,     5,     7,     6,     5,     7,     6,
     4,     1,     2,     7,     9,     9,     9,     5,     7,     9,
     2,     1,     1,     1,     1,     1,     1,     1,     2,     2,
     3,     3,     1,     1,     2,     0,     1,     8,     2,     2,
     2,     2,     4,     1,     2,     2,     2,     1,     2,     0,
     1,     5,     7
};

static const short yydefact[] = {     0,
    10,    11,    12,     5,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    53,     0,     0,    62,     0,     0,
     0,     0,     0,     0,   106,   103,     1,     2,     4,     6,
    13,     0,    46,    45,    92,    93,    94,    95,    96,    97,
     9,    98,     8,     0,    73,     0,     0,   100,    53,     0,
     0,     0,     0,     0,    54,     0,    99,    51,     0,     0,
    60,    63,    64,    43,    44,    33,    34,    23,     0,   104,
   107,     0,     3,     7,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    41,    42,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    91,
     0,    55,    69,    71,    74,     0,     0,     0,     0,     0,
     0,     0,     0,   120,     0,   101,    49,    52,     0,    57,
     0,    61,    14,   105,   102,    24,    25,    26,    27,    36,
    37,    38,    39,    40,    19,    20,    18,    16,    21,    22,
    35,    17,    15,    28,    29,    30,    31,    32,    56,     0,
     0,    47,     0,     0,    53,     0,     0,     0,     0,     0,
     0,     0,   114,     0,   118,   121,     0,    65,    67,     0,
     0,    48,    51,    59,    70,    72,    75,     0,     0,     0,
     0,    88,   120,   109,   115,   110,   116,   111,   117,     0,
   112,   119,   122,     0,     0,     0,    50,     0,     0,     0,
    77,     0,    82,     0,    53,     0,     0,     0,     0,    12,
     0,    66,    68,   106,    58,    76,     0,     0,     0,    84,
    83,     0,     0,    89,     0,   123,   113,     0,     0,   106,
   106,     0,     0,     0,   108,     0,    81,    85,    86,    90,
    87,    78,     0,    80,    79,     0,     0,     0
};

static const short yydefgoto[] = {   246,
    27,    28,    29,    30,    31,    32,   118,   119,    56,    33,
    61,    62,    63,    34,   169,   170,   104,   105,   106,    35,
   201,   203,   204,    36,    37,    38,    39,    40,    70,    71,
    72,    42,   164,   165,   166,   167,    43
};

static const short yypact[] = {    96,
-32768,-32768,     3,-32768,   -58,   -43,   -28,   -15,    -1,    21,
    17,    22,    62,    63,   256,   256,    25,   -25,   256,   256,
   256,   256,   256,   256,   266,-32768,    96,-32768,   193,-32768,
-32768,   332,    64,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,    92,   256,   256,   256,-32768,   256,   256,
   266,   256,   -20,    34,   650,    31,   650,   256,    76,   256,
-32768,   -25,-32768,-32768,-32768,   -26,   -26,   -26,   437,-32768,
   266,    39,-32768,-32768,   256,   256,   256,   256,   256,   256,
   256,   256,   256,-32768,-32768,   256,   256,   256,   256,   256,
   256,   256,   256,   256,   256,   256,   256,   256,   256,-32768,
   113,-32768,   623,-32768,    65,    51,   468,   499,    46,   305,
    48,   530,    91,    -6,    97,-32768,   650,    69,    66,    60,
   405,-32768,-32768,-32768,-32768,   668,   668,   668,   668,   650,
   650,   650,   650,   650,   686,   686,   187,   187,   686,   686,
   650,   187,   187,    -8,    -8,   -26,   -26,   -26,-32768,   256,
   256,-32768,   266,    59,   256,   100,   116,   266,    67,   -17,
    19,    58,-32768,   -41,-32768,    -6,    68,    82,-32768,   -38,
   256,-32768,   256,-32768,   650,-32768,    40,   127,    70,   -21,
    75,-32768,    -6,-32768,-32768,-32768,-32768,-32768,-32768,    54,
-32768,-32768,-32768,   256,    97,    74,   650,    80,   266,    78,
-32768,   256,-32768,    12,   256,   117,   266,   256,    77,-32768,
    90,   650,-32768,   266,-32768,-32768,   256,   370,    94,-32768,
-32768,    84,    86,-32768,   561,-32768,-32768,    98,   592,   266,
   266,   266,   266,    95,-32768,   266,-32768,-32768,-32768,-32768,
-32768,    79,   266,-32768,-32768,   173,   174,-32768
};

static const short yypgoto[] = {-32768,
-32768,   148,-32768,   147,   -13,   -14,-32768,     5,   -45,-32768,
   119,-32768,-32768,-32768,   -16,-32768,    32,-32768,-32768,-32768,
   -60,   -18,-32768,-32768,-32768,-32768,-32768,-32768,     0,-32768,
  -189,     2,-32768,    18,-32768,     4,-32768
};


#define	YYLAST		750


static const short yytable[] = {    41,
    55,    57,   113,   109,    64,    65,    66,    67,    68,    69,
    59,    14,    45,   206,   190,   184,   195,   160,   161,   162,
    84,    85,    14,   202,   228,   219,    41,    46,    41,   196,
   103,   107,   108,   191,    55,   110,    44,   112,    84,    85,
   237,   238,    47,   117,    60,   121,   207,    14,   199,   200,
   111,   186,   114,    97,    98,    99,     1,     2,   210,    48,
   126,   127,   128,   129,   130,   131,   132,   133,   134,    49,
   124,   135,   136,   137,   138,   139,   140,   141,   142,   143,
   144,   145,   146,   147,   148,   220,    14,   243,   200,    51,
   188,    50,    52,    53,    54,    58,   102,   101,     1,     2,
     3,     4,     5,     6,   115,   116,     7,   120,     8,   179,
     9,    10,   125,    11,    12,   163,    13,   149,   152,   151,
   155,   157,   159,   171,    14,    15,    16,    17,    18,   168,
   173,   178,   180,   172,   181,   175,   103,   194,   202,   183,
    55,   193,    19,    20,   205,   208,   214,   215,   217,   223,
   226,   232,   177,   233,    21,    22,   197,   182,   117,   222,
    23,   185,   187,   189,   227,   231,    24,   163,    25,   241,
    26,   235,   247,   248,    73,    74,   211,   198,   213,   212,
   122,   244,   176,   192,   163,   221,   209,   218,     0,     0,
    55,     0,     0,   225,     0,     1,     2,     3,   216,     5,
     6,     0,   229,     7,     0,     8,   224,     9,    10,     0,
    11,    12,     0,    13,     0,     0,     0,     0,     0,     0,
     0,    14,    15,    16,    17,    18,     0,     0,     0,     0,
     0,   239,   240,    84,    85,   242,     0,-32768,-32768,    19,
    20,     0,   245,-32768,-32768,    95,    96,     0,    97,    98,
    99,    21,    22,     0,     0,     0,     0,    23,     1,     2,
     3,     0,     5,    24,     0,    25,     0,    26,     1,     2,
     3,     0,     5,     6,     0,     0,     7,     0,     8,     0,
     9,    10,     0,    11,    12,     0,     0,    17,    18,     0,
     0,     0,     0,     0,    14,    15,    16,    17,    18,     0,
     0,     0,    19,    20,     0,     0,     0,     0,     0,     0,
     0,     0,    19,    20,    21,    22,     0,     0,     0,     0,
    23,   156,     0,     0,    21,    22,    24,     0,     0,     0,
    23,     0,     0,     0,     0,     0,    24,     0,    25,     0,
    26,     0,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
    92,    93,    94,    95,    96,     0,    97,    98,    99,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,     0,    92,    93,    94,
    95,    96,     0,    97,    98,    99,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   100,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,     0,    92,    93,    94,    95,    96,
     0,    97,    98,    99,     0,     0,     0,     0,     0,     0,
     0,   230,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
    92,    93,    94,    95,    96,     0,    97,    98,    99,     0,
     0,     0,     0,   174,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,     0,    92,    93,    94,    95,    96,     0,    97,    98,
    99,     0,     0,     0,   123,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,     0,    92,    93,    94,    95,    96,     0,    97,
    98,    99,     0,     0,     0,   153,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,     0,    92,    93,    94,    95,    96,     0,
    97,    98,    99,     0,     0,     0,   154,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,     0,    92,    93,    94,    95,    96,
     0,    97,    98,    99,     0,     0,     0,   158,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    89,    90,    91,     0,    92,    93,    94,    95,
    96,     0,    97,    98,    99,     0,     0,     0,   234,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,     0,    92,    93,    94,
    95,    96,     0,    97,    98,    99,     0,   150,     0,   236,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,     0,    92,    93,
    94,    95,    96,     0,    97,    98,    99,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,     0,    92,    93,    94,    95,    96,
     0,    97,    98,    99,    84,    85,    86,    87,    88,    89,
    90,    91,     0,     0,    93,    94,    95,    96,     0,    97,
    98,    99,    84,    85,-32768,-32768,    88,    89,-32768,-32768,
     0,     0,    93,    94,    95,    96,     0,    97,    98,    99
};

static const short yycheck[] = {     0,
    15,    16,    23,    49,    19,    20,    21,    22,    23,    24,
    36,    29,    71,    35,    56,    33,    55,    24,    25,    26,
    47,    48,    29,    12,   214,    14,    27,    71,    29,    68,
    45,    46,    47,    75,    49,    50,    34,    52,    47,    48,
   230,   231,    71,    58,    70,    60,    68,    29,     9,    10,
    51,    33,    73,    62,    63,    64,     3,     4,     5,    75,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    71,
    71,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,    74,    29,     9,    10,    73,
    33,    71,    71,    32,    32,    71,     5,    34,     3,     4,
     5,     6,     7,     8,    71,    75,    11,    32,    13,   155,
    15,    16,    74,    18,    19,   114,    21,     5,    68,    55,
    75,    74,    32,    55,    29,    30,    31,    32,    33,    33,
    71,    73,    33,    68,    19,   150,   151,    56,    12,    73,
   155,    74,    47,    48,    75,    71,    73,    68,    71,    33,
    74,    68,   153,    68,    59,    60,   171,   158,   173,   205,
    65,   160,   161,   162,    75,    72,    71,   166,    73,    75,
    75,    74,     0,     0,    27,    29,   190,   173,   195,   194,
    62,   242,   151,   166,   183,   204,   183,   202,    -1,    -1,
   205,    -1,    -1,   208,    -1,     3,     4,     5,   199,     7,
     8,    -1,   217,    11,    -1,    13,   207,    15,    16,    -1,
    18,    19,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
    -1,   232,   233,    47,    48,   236,    -1,    51,    52,    47,
    48,    -1,   243,    57,    58,    59,    60,    -1,    62,    63,
    64,    59,    60,    -1,    -1,    -1,    -1,    65,     3,     4,
     5,    -1,     7,    71,    -1,    73,    -1,    75,     3,     4,
     5,    -1,     7,     8,    -1,    -1,    11,    -1,    13,    -1,
    15,    16,    -1,    18,    19,    -1,    -1,    32,    33,    -1,
    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,
    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    47,    48,    59,    60,    -1,    -1,    -1,    -1,
    65,    17,    -1,    -1,    59,    60,    71,    -1,    -1,    -1,
    65,    -1,    -1,    -1,    -1,    -1,    71,    -1,    73,    -1,
    75,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
    56,    57,    58,    59,    60,    -1,    62,    63,    64,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
    59,    60,    -1,    62,    63,    64,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    75,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
    -1,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    72,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
    56,    57,    58,    59,    60,    -1,    62,    63,    64,    -1,
    -1,    -1,    -1,    69,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    -1,    56,    57,    58,    59,    60,    -1,    62,    63,
    64,    -1,    -1,    -1,    68,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    -1,    56,    57,    58,    59,    60,    -1,    62,
    63,    64,    -1,    -1,    -1,    68,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    -1,    56,    57,    58,    59,    60,    -1,
    62,    63,    64,    -1,    -1,    -1,    68,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
    -1,    62,    63,    64,    -1,    -1,    -1,    68,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
    60,    -1,    62,    63,    64,    -1,    -1,    -1,    68,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
    59,    60,    -1,    62,    63,    64,    -1,    35,    -1,    68,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
    58,    59,    60,    -1,    62,    63,    64,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
    -1,    62,    63,    64,    47,    48,    49,    50,    51,    52,
    53,    54,    -1,    -1,    57,    58,    59,    60,    -1,    62,
    63,    64,    47,    48,    49,    50,    51,    52,    53,    54,
    -1,    -1,    57,    58,    59,    60,    -1,    62,    63,    64
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 210 "grammar.c"
{yyval.ProgramUnion = root = createProgram(yyvsp[0].ProgramStmtListUnion);;
    break;}
case 2:
#line 214 "grammar.c"
{yyval.ProgramStmtListUnion = createProgramStmtList(yyvsp[0].ProgramStmtUnion);;
    break;}
case 3:
#line 215 "grammar.c"
{yyval.ProgramStmtListUnion = addProgramStmtToProgramStmtList(yyvsp[-1].ProgramStmtListUnion, yyvsp[0].ProgramStmtUnion);;
    break;}
case 4:
#line 219 "grammar.c"
{yyval.ProgramStmtUnion = createProgramStmtMainStmtList(yyvsp[0].MainStmtListUnion);;
    break;}
case 5:
#line 220 "grammar.c"
{yyval.ProgramStmtUnion = createProgramStmtHtml(yyvsp[0].htmlUnionType);;
    break;}
case 6:
#line 224 "grammar.c"
{yyval.MainStmtListUnion = createMainStmtList(yyvsp[0].MainStmtUnion);;
    break;}
case 7:
#line 225 "grammar.c"
{yyval.MainStmtListUnion = addMainStmtToMainStmtList(yyvsp[-1].MainStmtListUnion, yyvsp[0].MainStmtUnion);;
    break;}
case 8:
#line 229 "grammar.c"
{yyval.MainStmtUnion = createMainStmtClass(yyvsp[0].ClassDefUnion);;
    break;}
case 9:
#line 230 "grammar.c"
{yyval.MainStmtUnion = createMainStmt(yyvsp[0].StmtUnion);;
    break;}
case 10:
#line 235 "grammar.c"
{yyval.ConstValueUnion = createConst(yyvsp[0].intConstUnionType, t_int);;
    break;}
case 11:
#line 236 "grammar.c"
{yyval.ConstValueUnion = createConst(yyvsp[0].intConstUnionType, t_bool);;
    break;}
case 12:
#line 237 "grammar.c"
{yyval.ConstValueUnion = createCharConst(yyvsp[0].charConstUnionType);;
    break;}
case 13:
#line 242 "grammar.c"
{yyval.ExprUnion = createConstExpr(yyvsp[0].ConstValueUnion);;
    break;}
case 14:
#line 243 "grammar.c"
{yyval.ExprUnion = yyvsp[-1].ExprUnion;
    break;}
case 15:
#line 244 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_less);;
    break;}
case 16:
#line 245 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_leq);;
    break;}
case 17:
#line 246 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_greater);;
    break;}
case 18:
#line 247 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_geq);;
    break;}
case 19:
#line 248 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_eq);;
    break;}
case 20:
#line 249 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_neq);;
    break;}
case 21:
#line 250 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_teq);;
    break;}
case 22:
#line 251 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_tneq);;
    break;}
case 23:
#line 252 "grammar.c"
{yyval.ExprUnion = createUExpr(yyvsp[0].ExprUnion, t_not);;
    break;}
case 24:
#line 253 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_cor);;
    break;}
case 25:
#line 254 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_cand);;
    break;}
case 26:
#line 255 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_por);;
    break;}
case 27:
#line 256 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_pand);;
    break;}
case 28:
#line 257 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_plus);;
    break;}
case 29:
#line 258 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_minus);;
    break;}
case 30:
#line 259 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_mult);;
    break;}
case 31:
#line 260 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_div);;
    break;}
case 32:
#line 261 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_mod);;
    break;}
case 33:
#line 262 "grammar.c"
{yyval.ExprUnion = createUExpr(yyvsp[0].ExprUnion, t_uplus);;
    break;}
case 34:
#line 263 "grammar.c"
{yyval.ExprUnion = createUExpr(yyvsp[0].ExprUnion, t_uminus);;
    break;}
case 35:
#line 264 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_assign);;
    break;}
case 36:
#line 265 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_plusas);;
    break;}
case 37:
#line 266 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_minusas);;
    break;}
case 38:
#line 267 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_mulas);;
    break;}
case 39:
#line 268 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_divas);;
    break;}
case 40:
#line 269 "grammar.c"
{yyval.ExprUnion = createExpr(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion, t_modas);;
    break;}
case 41:
#line 270 "grammar.c"
{yyval.ExprUnion = createUExpr(yyvsp[-1].ExprUnion, t_post_inc);;
    break;}
case 42:
#line 271 "grammar.c"
{yyval.ExprUnion = createUExpr(yyvsp[-1].ExprUnion, t_post_dec);;
    break;}
case 43:
#line 272 "grammar.c"
{yyval.ExprUnion = createUExpr(yyvsp[0].ExprUnion, t_pre_inc);;
    break;}
case 44:
#line 273 "grammar.c"
{yyval.ExprUnion = createUExpr(yyvsp[0].ExprUnion, t_pre_dec);;
    break;}
case 45:
#line 274 "grammar.c"
{yyval.ExprUnion = createVarExpr(yyvsp[0].VarUnion);;
    break;}
case 46:
#line 275 "grammar.c"
{yyval.ExprUnion = createStrExpr(yyvsp[0].StringUnion);;
    break;}
case 47:
#line 276 "grammar.c"
{yyval.ExprUnion = createArrayExpr(yyvsp[-1].ArrayUnion);;
    break;}
case 48:
#line 277 "grammar.c"
{yyval.ExprUnion = createFuncCallExpr(yyvsp[-3].idUnionType, yyvsp[-1].ExprListUnion);;
    break;}
case 49:
#line 281 "grammar.c"
{yyval.ExprListUnion = createExprList(yyvsp[0].ExprUnion);;
    break;}
case 50:
#line 282 "grammar.c"
{yyval.ExprListUnion = addExprToExprList(yyvsp[-2].ExprListUnion, yyvsp[0].ExprUnion);;
    break;}
case 51:
#line 286 "grammar.c"
{yyval.ExprListUnion = 0;;
    break;}
case 52:
#line 287 "grammar.c"
{yyval.ExprListUnion = yyvsp[0].ExprListUnion;;
    break;}
case 53:
#line 291 "grammar.c"
{yyval.ExprUnion = 0;;
    break;}
case 54:
#line 292 "grammar.c"
{yyval.ExprUnion = yyvsp[0].ExprUnion;;
    break;}
case 55:
#line 297 "grammar.c"
{yyval.StringUnion = createString(yyvsp[-2].charConstUnionType, yyvsp[-1].idUnionType, yyvsp[0].charConstUnionType);;
    break;}
case 56:
#line 298 "grammar.c"
{yyval.StringUnion = addElementToString(yyvsp[-2].StringUnion, yyvsp[-1].idUnionType, yyvsp[0].charConstUnionType);;
    break;}
case 57:
#line 303 "grammar.c"
{yyval.VarElementUnion = createVariableFieldElement(yyvsp[0].idUnionType);;
    break;}
case 58:
#line 304 "grammar.c"
{yyval.VarElementUnion = createVariableMethodElement(yyvsp[-3].idUnionType, yyvsp[-1].ExprListUnion);;
    break;}
case 59:
#line 307 "grammar.c"
{yyval.VarElementUnion = createVariableIndexElement(yyvsp[-1].ExprUnion);;
    break;}
case 60:
#line 311 "grammar.c"
{yyval.VarElementListUnion = createElementsList(yyvsp[0].VarElementUnion);;
    break;}
case 61:
#line 312 "grammar.c"
{yyval.VarElementListUnion = addElementToElementsList(yyvsp[-1].VarElementListUnion, yyvsp[0].VarElementUnion);;
    break;}
case 62:
#line 316 "grammar.c"
{yyval.VarElementListUnion = 0;;
    break;}
case 63:
#line 317 "grammar.c"
{yyval.VarElementListUnion = yyvsp[0].VarElementListUnion;;
    break;}
case 64:
#line 321 "grammar.c"
{yyval.VarUnion = createVariable(yyvsp[-1].idUnionType, yyvsp[0].VarElementListUnion);;
    break;}
case 65:
#line 325 "grammar.c"
{yyval.VarListElementUnion = createVarListElement(yyvsp[0].idUnionType);;
    break;}
case 66:
#line 326 "grammar.c"
{yyval.VarListElementUnion = createVarListElementWithValue(yyvsp[-2].idUnionType, yyvsp[0].ExprUnion);;
    break;}
case 67:
#line 330 "grammar.c"
{yyval.VarListUnion = createVarList(yyvsp[0].VarListElementUnion);;
    break;}
case 68:
#line 331 "grammar.c"
{yyval.VarListUnion = addElementToVarList(yyvsp[-2].VarListUnion, yyvsp[0].VarListElementUnion);;
    break;}
case 69:
#line 336 "grammar.c"
{yyval.ArrayElementUnion = createArrayElement(yyvsp[0].ExprUnion);;
    break;}
case 70:
#line 337 "grammar.c"
{yyval.ArrayElementUnion = createArrayElementWithValue(yyvsp[-2].ExprUnion, yyvsp[0].ExprUnion);;
    break;}
case 71:
#line 341 "grammar.c"
{yyval.ArrayUnion = createArrayElementsList(yyvsp[0].ArrayElementUnion);;
    break;}
case 72:
#line 342 "grammar.c"
{yyval.ArrayUnion = addElementToArrayElementsList(yyvsp[-2].ArrayUnion, yyvsp[0].ArrayElementUnion);;
    break;}
case 73:
#line 346 "grammar.c"
{yyval.ArrayUnion = 0;;
    break;}
case 74:
#line 347 "grammar.c"
{yyval.ArrayUnion = yyvsp[0].ArrayUnion;;
    break;}
case 75:
#line 352 "grammar.c"
{yyval.IfStmtUnion = createIfStmt(yyvsp[-2].ExprUnion, yyvsp[0].StmtUnion);;
    break;}
case 76:
#line 353 "grammar.c"
{yyval.IfStmtUnion = createIfElseStmt(yyvsp[-4].ExprUnion, yyvsp[-2].StmtUnion, yyvsp[0].StmtUnion);;
    break;}
case 77:
#line 354 "grammar.c"
{yyval.IfStmtUnion = createIfElseIfStmt(yyvsp[-3].ExprUnion, yyvsp[-1].StmtUnion, yyvsp[0].IfStmtUnion);;
    break;}
case 78:
#line 358 "grammar.c"
{yyval.IfStmtUnion = createIfStmt(yyvsp[-2].ExprUnion, yyvsp[0].StmtUnion);;
    break;}
case 79:
#line 359 "grammar.c"
{yyval.IfStmtUnion = createIfElseStmt(yyvsp[-4].ExprUnion, yyvsp[-2].StmtUnion, yyvsp[0].StmtUnion);;
    break;}
case 80:
#line 360 "grammar.c"
{yyval.IfStmtUnion = createIfElseIfStmt(yyvsp[-3].ExprUnion, yyvsp[-1].StmtUnion, yyvsp[0].IfStmtUnion);;
    break;}
case 81:
#line 364 "grammar.c"
{yyval.CaseUnion = createCaseStmt(yyvsp[-2].ExprUnion, yyvsp[0].StmtListUnion);;
    break;}
case 82:
#line 368 "grammar.c"
{yyval.CaseStmtListUnion = createCaseStmtList(yyvsp[0].CaseUnion);;
    break;}
case 83:
#line 369 "grammar.c"
{yyval.CaseStmtListUnion = addCaseStmtToCaseStmtList(yyvsp[-1].CaseStmtListUnion, yyvsp[0].CaseUnion);;
    break;}
case 84:
#line 373 "grammar.c"
{yyval.SwitchStmtUnion = createSwitchStmt(yyvsp[-4].ExprUnion, yyvsp[-1].CaseStmtListUnion);;
    break;}
case 85:
#line 374 "grammar.c"
{yyval.SwitchStmtUnion = createSwitchStmtWithDefault(yyvsp[-6].ExprUnion, yyvsp[-3].CaseStmtListUnion, yyvsp[0].StmtListUnion);;
    break;}
case 86:
#line 379 "grammar.c"
{yyval.ForStmtUnion = createForStmt(yyvsp[-6].ExprUnion, yyvsp[-4].ExprUnion, yyvsp[-2].ExprUnion, yyvsp[0].StmtUnion);;
    break;}
case 87:
#line 383 "grammar.c"
{yyval.WhileStmtUnion = createWhileStmt(yyvsp[-2].ExprUnion, yyvsp[-6].StmtUnion, t_do_while);;
    break;}
case 88:
#line 387 "grammar.c"
{yyval.WhileStmtUnion = createWhileStmt(yyvsp[-2].ExprUnion, yyvsp[0].StmtUnion, t_while);;
    break;}
case 89:
#line 391 "grammar.c"
{yyval.ForeachStmtUnion = createForeachStmt(yyvsp[-4].ExprUnion, yyvsp[-2].idUnionType, yyvsp[0].StmtUnion);;
    break;}
case 90:
#line 392 "grammar.c"
{yyval.ForeachStmtUnion = createForeachStmtWithKey(yyvsp[-6].ExprUnion, yyvsp[-4].idUnionType, yyvsp[-2].idUnionType, yyvsp[0].StmtUnion);;
    break;}
case 91:
#line 397 "grammar.c"
{yyval.StmtUnion = createStmtExpr(yyvsp[-1].ExprUnion);;
    break;}
case 92:
#line 398 "grammar.c"
{yyval.StmtUnion = createStmtIf(yyvsp[0].IfStmtUnion);;
    break;}
case 93:
#line 399 "grammar.c"
{yyval.StmtUnion = createStmtSwitch(yyvsp[0].SwitchStmtUnion);;
    break;}
case 94:
#line 400 "grammar.c"
{yyval.StmtUnion = createStmtFor(yyvsp[0].ForStmtUnion);;
    break;}
case 95:
#line 401 "grammar.c"
{yyval.StmtUnion = createStmtWhile(yyvsp[0].WhileStmtUnion);;
    break;}
case 96:
#line 402 "grammar.c"
{yyval.StmtUnion = createStmtWhile(yyvsp[0].WhileStmtUnion);;
    break;}
case 97:
#line 403 "grammar.c"
{yyval.StmtUnion = createStmtForeach(yyvsp[0].ForeachStmtUnion);;
    break;}
case 98:
#line 404 "grammar.c"
{yyval.StmtUnion = createStmtFuncDef(yyvsp[0].FuncDefUnion);;
    break;}
case 99:
#line 405 "grammar.c"
{yyval.StmtUnion = createStmtEcho(yyvsp[0].ExprUnion);;
    break;}
case 100:
#line 406 "grammar.c"
{yyval.StmtUnion = createStmtBreak();;
    break;}
case 101:
#line 407 "grammar.c"
{yyval.StmtUnion = createStmtReturn(yyvsp[-1].ExprUnion);;
    break;}
case 102:
#line 408 "grammar.c"
{yyval.StmtUnion = createStmtStmtlist(yyvsp[-1].StmtListUnion);;
    break;}
case 103:
#line 409 "grammar.c"
{yyval.StmtUnion = createStmtVoid();;
    break;}
case 104:
#line 413 "grammar.c"
{yyval.StmtListUnion = createStmtList(yyvsp[0].StmtUnion);;
    break;}
case 105:
#line 414 "grammar.c"
{yyval.StmtListUnion = addStmtToStmtList(yyvsp[-1].StmtListUnion, yyvsp[0].StmtUnion);;
    break;}
case 106:
#line 418 "grammar.c"
{yyval.StmtListUnion = 0;;
    break;}
case 107:
#line 419 "grammar.c"
{yyval.StmtListUnion = yyvsp[0].StmtListUnion;
    break;}
case 108:
#line 424 "grammar.c"
{yyval.FuncDefUnion = createFuncDef(yyvsp[-6].idUnionType, yyvsp[-4].VarListUnion, yyvsp[-1].StmtListUnion);;
    break;}
case 109:
#line 429 "grammar.c"
{yyval.FieldUnion = createField(yyvsp[0].idUnionType, t_public);;
    break;}
case 110:
#line 430 "grammar.c"
{yyval.FieldUnion = createField(yyvsp[0].idUnionType, t_private);;
    break;}
case 111:
#line 431 "grammar.c"
{yyval.FieldUnion = createField(yyvsp[0].idUnionType, t_protected);;
    break;}
case 112:
#line 435 "grammar.c"
{yyval.ClassBodyElementUnion = createFieldElement(yyvsp[-1].FieldUnion);;
    break;}
case 113:
#line 436 "grammar.c"
{yyval.ClassBodyElementUnion = createFieldWithValue(yyvsp[-3].FieldUnion, yyvsp[-1].ConstValueUnion);;
    break;}
case 114:
#line 437 "grammar.c"
{yyval.ClassBodyElementUnion = createMethod(yyvsp[0].FuncDefUnion, t_public);;
    break;}
case 115:
#line 438 "grammar.c"
{yyval.ClassBodyElementUnion = createMethod(yyvsp[0].FuncDefUnion, t_public);;
    break;}
case 116:
#line 439 "grammar.c"
{yyval.ClassBodyElementUnion = createMethod(yyvsp[0].FuncDefUnion, t_private);;
    break;}
case 117:
#line 440 "grammar.c"
{yyval.ClassBodyElementUnion = createMethod(yyvsp[0].FuncDefUnion, t_protected);;
    break;}
case 118:
#line 444 "grammar.c"
{yyval.ClassBodyElementsListUnion = createBody(yyvsp[0].ClassBodyElementUnion);;
    break;}
case 119:
#line 445 "grammar.c"
{yyval.ClassBodyElementsListUnion = addElementToBody(yyvsp[-1].ClassBodyElementsListUnion, yyvsp[0].ClassBodyElementUnion);;
    break;}
case 120:
#line 449 "grammar.c"
{yyval.ClassBodyElementsListUnion = 0;;
    break;}
case 121:
#line 450 "grammar.c"
{yyval.ClassBodyElementsListUnion = yyvsp[0].ClassBodyElementsListUnion;;
    break;}
case 122:
#line 454 "grammar.c"
{yyval.ClassDefUnion = createClass(yyvsp[-3].idUnionType, yyvsp[-1].ClassBodyElementsListUnion);;
    break;}
case 123:
#line 455 "grammar.c"
{yyval.ClassDefUnion = createExtendedClass(yyvsp[-5].idUnionType, yyvsp[-3].idUnionType, yyvsp[-1].ClassBodyElementsListUnion);;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 458 "grammar.c"


struct ConstValueStruct* createConst(int new_const, enum ConstValueType type)
{
	struct ConstValueStruct* result = (struct ConstValueStruct*)malloc(sizeof(struct ConstValueStruct));
	result->type = type;
	result->const_int = new_const;
	return result;
}

struct ConstValueStruct* createCharConst(char* new_const)
{
	struct ConstValueStruct* result = (struct ConstValueStruct*)malloc(sizeof(struct ConstValueStruct));
	result->type = t_char_const;
	result->const_char = new_const;
	return result;
}

struct ExprStruct* createConstExpr(struct ConstValueStruct* new_const_value)
{
	struct ExprStruct* result = (struct ExprStruct*)malloc(sizeof(struct ExprStruct));
	result->type = t_const;
	result->const_value = new_const_value;
	return result;
}

struct ExprStruct* createExpr(struct ExprStruct* left, struct ExprStruct* right, enum ExprType type)
{
	struct ExprStruct* result = (struct ExprStruct*)malloc(sizeof(struct ExprStruct));
	result->type = type;
	result->left = left;
	result->right = right;
	return result;
}

struct ExprStruct* createUExpr(struct ExprStruct* left, enum ExprType type)
{
	struct ExprStruct* result = (struct ExprStruct*)malloc(sizeof(struct ExprStruct));
	result->type = type;
	result->left = left;
	return result;
}

struct ExprStruct* createVarExpr(struct VarStruct* new_var)
{
	struct ExprStruct* result = (struct ExprStruct*)malloc(sizeof(struct ExprStruct));
	result->type = t_var;
	result->variable = new_var;
	return result;
}

struct ExprStruct* createStrExpr(struct StringStruct* new_str)
{
	struct ExprStruct* result = (struct ExprStruct*)malloc(sizeof(struct ExprStruct));
	result->type = t_string;
	result->string = new_str;
	return result;
}

struct ExprStruct* createArrayExpr(struct ArrayStruct* new_array)
{
	struct ExprStruct* result = (struct ExprStruct*)malloc(sizeof(struct ExprStruct));
	result->type = t_array;
	result->array = new_array;
	return result;
}

struct ExprStruct* createFuncCallExpr(char* new_id, struct ExprListStruct* new_list)
{
	struct ExprStruct* result = (struct ExprStruct*)malloc(sizeof(struct ExprStruct));
	result->type = t_func_call;
	result->id = new_id;
	result->list = new_list;
	return result;
}

struct ExprListStruct* createExprList(struct ExprStruct* new_expr)
{
	struct ExprListStruct* result = (struct ExprListStruct*)malloc(sizeof(struct ExprListStruct));
	result->first = new_expr;
	result->last = new_expr;
	return result;
}

struct ExprListStruct* addExprToExprList(struct ExprListStruct* expr_list, struct ExprStruct* new_expr)
{
	expr_list->last->next = new_expr;
	expr_list->last = new_expr;
	return expr_list;
}

struct StringStruct* createString(char* first_char_const, char* first_varname, char* second_char_const)
{
	struct StringStruct* result = (struct StringStruct*)malloc(sizeof(struct StringStruct));

	struct StringElementStruct* first_element = (struct StringElementStruct*)malloc(sizeof(struct StringElementStruct));
	first_element->type = t_const_string;
	first_element->const_char = first_char_const;

	struct StringElementStruct* second_element = (struct StringElementStruct*)malloc(sizeof(struct StringElementStruct));
	second_element->type = t_variable;
	second_element->const_char = first_varname;

	struct StringElementStruct* third_element = (struct StringElementStruct*)malloc(sizeof(struct StringElementStruct));
	third_element->type = t_const_string;
	third_element->const_char = second_char_const;

	first_element->next = second_element;
	second_element->next = third_element;

	result->first = first_element;
	result->last = third_element;
	return result;
}

struct StringStruct* addElementToString(struct StringStruct* current_string, char* varname, char* char_const)
{
	struct StringElementStruct* first_element = (struct StringElementStruct*)malloc(sizeof(struct StringElementStruct));
	first_element->type = t_variable;
	first_element->const_char = varname;

	struct StringElementStruct* second_element = (struct StringElementStruct*)malloc(sizeof(struct StringElementStruct));
	second_element->type = t_const_string;
	second_element->const_char = char_const;

	current_string->last->next = first_element;
	first_element->next = second_element;
	current_string->last = second_element;
	return current_string;
}

struct VarElementStruct* createVariableFieldElement(char* new_member)
{
	struct VarElementStruct* result = (struct VarElementStruct*)malloc(sizeof(struct VarElementStruct));
	result->type = t_field_element;
	result->member = new_member;
	return result;
}

struct VarElementStruct* createVariableMethodElement(char* new_member, struct ExprListStruct* new_params)
{
	struct VarElementStruct* result = (struct VarElementStruct*)malloc(sizeof(struct VarElementStruct));
	result->type = t_method_call;
	result->member = new_member;
	result->params = new_params;
	return result;
}

struct VarElementStruct* createVariableIndexElement(struct ExprStruct* new_index)
{
	struct VarElementStruct* result = (struct VarElementStruct*)malloc(sizeof(struct VarElementStruct));
	result->type = t_index;
	result->index = new_index;
	return result;
}

struct VarElementListStruct* createElementsList(struct VarElementStruct* new_element)
{
	struct VarElementListStruct* result = (struct VarElementListStruct*)malloc(sizeof(struct VarElementListStruct));
	result->first = new_element;
	result->last = new_element;
	return result;
}

struct VarElementListStruct* addElementToElementsList(struct VarElementListStruct* current_list, struct VarElementStruct* new_element)
{
	current_list->last->next = new_element;
	current_list->last = new_element;
	return current_list;
}

struct VarStruct* createVariable(char* new_id, struct VarElementListStruct* new_list)
{
	struct VarStruct* result = (struct VarStruct*)malloc(sizeof(struct VarStruct));
	result->id = new_id;
	result->list = new_list;
	return result;
}

struct VarListElementStruct* createVarListElement(char* new_id)
{
	struct VarListElementStruct* result = (struct VarListElementStruct*)malloc(sizeof(struct VarListElementStruct));
	result->id = new_id;
	return result;
}

struct VarListElementStruct* createVarListElementWithValue(char* new_id, struct ExprStruct* new_value)
{
	struct VarListElementStruct* result = (struct VarListElementStruct*)malloc(sizeof(struct VarListElementStruct));
	result->id = new_id;
	result->default_value = new_value;
	return result;
}

struct VarListStruct* createVarList(struct VarListElementStruct* new_element)
{
	struct VarListStruct* result = (struct VarListStruct*)malloc(sizeof(struct VarListStruct));
	result->first = new_element;
	result->last = new_element;
	return result;
}

struct VarListStruct* addElementToVarList(struct VarListStruct* current_list, struct VarListElementStruct* new_element)
{
	current_list->last->next = new_element;
	current_list->last = new_element;
	return current_list;
}

struct ArrayElementStruct* createArrayElement(struct ExprStruct* new_value)
{
	struct ArrayElementStruct* result = (struct ArrayElementStruct*)malloc(sizeof(struct ArrayElementStruct));
	result->value = new_value;
	return result;
}

struct ArrayElementStruct* createArrayElementWithValue(struct ExprStruct* new_key, struct ExprStruct* new_value)
{
	struct ArrayElementStruct* result = (struct ArrayElementStruct*)malloc(sizeof(struct ArrayElementStruct));
	result->key = new_key;
	result->value = new_value;
	return result;
}

struct ArrayStruct* createArrayElementsList(struct ArrayElementStruct* new_element)
{
	struct ArrayStruct* result = (struct ArrayStruct*)malloc(sizeof(struct ArrayStruct));
	result->first = new_element;
	result->last = new_element;
	return result;
}

struct ArrayStruct* addElementToArrayElementsList(struct ArrayStruct* current_list, struct ArrayElementStruct* new_element)
{
	current_list->last->next = new_element;
	current_list->last = new_element;
	return current_list;
}

struct IfStmtStruct* createIfStmt(struct ExprStruct* new_condition, struct StmtStruct* new_stmt)
{
	struct IfStmtStruct* result = (struct IfStmtStruct*)malloc(sizeof(struct IfStmtStruct));
	result->type = t_if;
	result->condition = new_condition;
	result->stmt = new_stmt;
	return result;
}

struct IfStmtStruct* createIfElseStmt(struct ExprStruct* new_condition, struct StmtStruct* new_stmt, struct StmtStruct* new_else_stmt)
{
	struct IfStmtStruct* result = (struct IfStmtStruct*)malloc(sizeof(struct IfStmtStruct));
	result->type = t_if_else;
	result->condition = new_condition;
	result->stmt = new_stmt;
	result->else_stmt = new_else_stmt;
	return result;
}

struct IfStmtStruct* createIfElseIfStmt(struct ExprStruct* new_condition, struct StmtStruct* new_stmt, struct IfStmtStruct* new_elseif_stmt)
{
	struct IfStmtStruct* result = (struct IfStmtStruct*)malloc(sizeof(struct IfStmtStruct));
	result->type = t_if_elseif;
	result->condition = new_condition;
	result->stmt = new_stmt;
	result->elseif_stmt = new_elseif_stmt;
	return result;
}

struct CaseStruct* createCaseStmt(struct ExprStruct* new_expr, struct StmtListStruct* new_stmt_list)
{
	struct CaseStruct* result = (struct CaseStruct*)malloc(sizeof(struct CaseStruct));
	result->expr = new_expr;
	result->stmt_list = new_stmt_list;
	return result;
}

struct CaseStmtListStruct* createCaseStmtList(struct CaseStruct* new_element)
{
	struct CaseStmtListStruct* result = (struct CaseStmtListStruct*)malloc(sizeof(struct CaseStmtListStruct));
	result->first = new_element;
	result->last = new_element;
	return result;
}

struct CaseStmtListStruct* addCaseStmtToCaseStmtList(struct CaseStmtListStruct* current_list, struct CaseStruct* new_element)
{
	current_list->last->next = new_element;
	current_list->last = new_element;
	return current_list;
}

struct SwitchStmtStruct* createSwitchStmt(struct ExprStruct* new_expr, struct CaseStmtListStruct* new_case_list)
{
	struct SwitchStmtStruct* result = (struct SwitchStmtStruct*)malloc(sizeof(struct SwitchStmtStruct));
	result->expr = new_expr;
	result->case_list = new_case_list;
	return result;
}

struct SwitchStmtStruct* createSwitchStmtWithDefault(struct ExprStruct* new_expr, struct CaseStmtListStruct* new_case_list, struct StmtListStruct* new_default_stmt)
{
	struct SwitchStmtStruct* result = (struct SwitchStmtStruct*)malloc(sizeof(struct SwitchStmtStruct));
	result->expr = new_expr;
	result->case_list = new_case_list;
	result->default_stmt = new_default_stmt;
	return result;
}

struct ForStmtStruct* createForStmt(struct ExprStruct* new_start_expr, struct ExprStruct* new_condition, struct ExprStruct* new_end_action, struct StmtListStruct* new_stmt)
{
	struct ForStmtStruct* result = (struct ForStmtStruct*)malloc(sizeof(struct ForStmtStruct));
	result->start_expr = new_start_expr;
	result->condition = new_condition;
	result->end_action = new_end_action;
	result->stmt = new_stmt;
	return result;
}

struct WhileStmtStruct* createWhileStmt(struct ExprStruct* new_condition, struct StmtListStruct* new_stmt, enum WhileType new_type)
{
	struct WhileStmtStruct* result = (struct WhileStmtStruct*)malloc(sizeof(struct WhileStmtStruct));
	result->type = new_type;
	result->condition = new_condition;
	result->stmt = new_stmt;
	return result;
}

struct ForeachStmtStruct* createForeachStmt(struct ExprStruct* new_array, char* new_value, struct StmtListStruct* new_stmt)
{
	struct ForeachStmtStruct* result = (struct ForeachStmtStruct*)malloc(sizeof(struct ForeachStmtStruct));
	result->array = new_array;
	result->value = new_value;
	result->stmt = new_stmt;
	return result;
}

struct ForeachStmtStruct* createForeachStmtWithKey(struct ExprStruct* new_array, char* new_key, char* new_value, struct StmtListStruct* new_stmt)
{
	struct ForeachStmtStruct* result = (struct ForeachStmtStruct*)malloc(sizeof(struct ForeachStmtStruct));
	result->array = new_array;
	result->key = new_key;
	result->value = new_value;
	result->stmt = new_stmt;
	return result;
}

struct StmtStruct* createStmtExpr(struct ExprStruct* new_expr)
{
	struct StmtStruct* result = (struct StmtStruct*)malloc(sizeof(struct StmtStruct));
	result->type = t_expr;
	result->expr = new_expr;
	return result;
}

struct StmtStruct* createStmtIf(struct IfStmtStruct* new_if_stmt)
{
	struct StmtStruct* result = (struct StmtStruct*)malloc(sizeof(struct StmtStruct));
	result->type = t_if_stmt;
	result->if_stmt = new_if_stmt;
	return result;
}

struct StmtStruct* createStmtSwitch(struct SwitchStmtStruct* new_switch_stmt)
{
	struct StmtStruct* result = (struct StmtStruct*)malloc(sizeof(struct StmtStruct));
	result->type = t_switch;
	result->switch_stmt = new_switch_stmt;
	return result;
}

struct StmtStruct* createStmtFor(struct ForStmtStruct* new_for_stmt)
{
	struct StmtStruct* result = (struct StmtStruct*)malloc(sizeof(struct StmtStruct));
	result->type = t_for;
	result->for_stmt = new_for_stmt;
	return result;
}

struct StmtStruct* createStmtWhile(struct WhileStmtStruct* new_while_stmt)
{
	struct StmtStruct* result = (struct StmtStruct*)malloc(sizeof(struct StmtStruct));
	result->type = t_while_do;
	result->while_stmt = new_while_stmt;
	return result;
}

struct StmtStruct* createStmtForeach(struct ForeachStmtStruct* new_foreach_stmt)
{
	struct StmtStruct* result = (struct StmtStruct*)malloc(sizeof(struct StmtStruct));
	result->type = t_foreach;
	result->foreach_stmt = new_foreach_stmt;
	return result;
}

struct StmtStruct* createStmtFuncDef(struct FuncDefStruct* new_func_def)
{
	struct StmtStruct* result = (struct StmtStruct*)malloc(sizeof(struct StmtStruct));
	result->type = t_func_def_stmt;
	result->func_def = new_func_def;
	return result;
}

struct StmtStruct* createStmtEcho(struct ExprStruct* new_expr)
{
	struct StmtStruct* result = (struct StmtStruct*)malloc(sizeof(struct StmtStruct));
	result->type = t_echo;
	result->expr = new_expr;
	return result;
}

struct StmtStruct* createStmtBreak()
{
	struct StmtStruct* result = (struct StmtStruct*)malloc(sizeof(struct StmtStruct));
	result->type = t_break;
	return result;
}

struct StmtStruct* createStmtReturn(struct ExprStruct* new_expr)
{
	struct StmtStruct* result = (struct StmtStruct*)malloc(sizeof(struct StmtStruct));
	result->type = t_return;
	result->expr = new_expr;
	return result;
}

struct StmtStruct* createStmtStmtlist(struct StmtListStruct* new_list)
{
	struct StmtStruct* result = (struct StmtStruct*)malloc(sizeof(struct StmtStruct));
	result->type = t_stmt_list;
	result->list = new_list;
	return result;
}

struct StmtStruct* createStmtVoid()
{
	struct StmtStruct* result = (struct StmtStruct*)malloc(sizeof(struct StmtStruct));
	result->type = t_void;
	return result;
}

struct StmtListStruct* createStmtList(struct StmtStruct* new_element)
{
	struct StmtListStruct* result = (struct StmtListStruct*)malloc(sizeof(struct StmtListStruct));
	result->first = new_element;
	result->last = new_element;
	return result;
}

struct StmtListStruct* addStmtToStmtList(struct StmtListStruct* current_list, struct StmtStruct* new_element)
{
	current_list->last->next = new_element;
	current_list->last = new_element;
	return current_list;
}

struct FuncDefStruct* createFuncDef(char* new_id, struct VarListStruct* new_var_list, struct StmtListStruct* new_stmt_list)
{
	struct FuncDefStruct* result = (struct FuncDefStruct*)malloc(sizeof(struct FuncDefStruct));
	result->id = new_id;
	result->var_list = new_var_list;
	result->stmt_list = new_stmt_list;
	return result;
}

struct FieldStruct* createField(char* new_id, enum ProtectionType new_protection_type)
{
	struct FieldStruct* result = (struct FieldStruct*)malloc(sizeof(struct FieldStruct));
	result->protection_type = new_protection_type;
	result->id = new_id;
	return result;
}

struct ClassBodyElementStruct* createFieldElement(struct FieldStruct* new_field)
{
	struct ClassBodyElementStruct* result = (struct ClassBodyElementStruct*)malloc(sizeof(struct ClassBodyElementStruct));
	result->type = t_field;
	result->field = new_field;
	return result;
}

struct ClassBodyElementStruct* createFieldWithValue(struct FieldStruct* new_field, struct ConstValueStruct* new_const_value)
{
	struct ClassBodyElementStruct* result = (struct ClassBodyElementStruct*)malloc(sizeof(struct ClassBodyElementStruct));
	result->type = t_field;
	result->field = new_field;
	result->const_value = new_const_value;
	return result;
}

struct ClassBodyElementStruct* createMethod(struct FuncDefStruct* new_func, enum ProtectionType new_protection_type)
{
	struct ClassBodyElementStruct* result = (struct ClassBodyElementStruct*)malloc(sizeof(struct ClassBodyElementStruct));
	result->protection_type = new_protection_type;
	result->func = new_func;
	return result;
}

struct ClassBodyElementsListStruct* createBody(struct ClassBodyElementStruct* new_element)
{
	struct ClassBodyElementsListStruct* result = (struct ClassBodyElementsListStruct*)malloc(sizeof(struct ClassBodyElementsListStruct));
	result->first = new_element;
	result->last = new_element;
	return result;
}

struct ClassBodyElementsListStruct* addElementToBody(struct ClassBodyElementsListStruct* current_list, struct ClassBodyElementStruct* new_element)
{
	current_list->last->next = new_element;
	current_list->last = new_element;
	return current_list;
}

struct ClassDefStruct* createClass(char* new_id, struct ClassBodyElementsListStruct* new_body)
{
	struct ClassDefStruct* result = (struct ClassDefStruct*)malloc(sizeof(struct ClassDefStruct));
	result->id = new_id;
	result->body = new_body;
	return result;
}

struct ClassDefStruct* createExtendedClass(char* new_id, char* new_parentId, struct ClassBodyElementsListStruct* new_body)
{
	struct ClassDefStruct* result = (struct ClassDefStruct*)malloc(sizeof(struct ClassDefStruct));
	result->id = new_id;
	result->parentId = new_parentId;
	result->body = new_body;
	return result;
}

struct MainStmtStruct* createMainStmtClass(struct ClassDefStruct* new_class_def)
{
	struct MainStmtStruct* result = (struct MainStmtStruct*)malloc(sizeof(struct MainStmtStruct));
	result->type = t_class_def;
	result->class_def = new_class_def;
	return result;
}

struct MainStmtStruct* createMainStmt(struct ClassDefStruct* new_stmt)
{
	struct MainStmtStruct* result = (struct MainStmtStruct*)malloc(sizeof(struct MainStmtStruct));
	result->type = t_stmt;
	result->stmt = new_stmt;
	return result;
}

struct MainStmtListStruct* createMainStmtList(struct MainStmtStruct* new_element)
{
	struct MainStmtListStruct* result = (struct MainStmtListStruct*)malloc(sizeof(struct MainStmtListStruct));
	result->first = new_element;
	result->last = new_element;
	return result;
}

struct MainStmtListStruct* addMainStmtToMainStmtList(struct MainStmtListStruct* current_list, struct MainStmtStruct* new_element)
{
	current_list->last->next = new_element;
	current_list->last = new_element;
	return current_list;
}

struct ProgramStmtStruct* createProgramStmtMainStmtList(struct MainStmtListStruct* new_main_stmt_list)
{
	struct ProgramStmtStruct* result = (struct ProgramStmtStruct*)malloc(sizeof(struct ProgramStmtStruct));
	result->type = t_main_stmt_list;
	result->main_stmt_list = new_main_stmt_list;
	return result;
}

struct ProgramStmtStruct* createProgramStmtHtml(char* new_html)
{
	struct ProgramStmtStruct* result = (struct ProgramStmtStruct*)malloc(sizeof(struct ProgramStmtStruct));
	result->type = t_html;
	result->html = new_html;
	return result;
}

struct ProgramStmtListStruct* createProgramStmtList(struct ProgramStmtStruct* new_element)
{
	struct ProgramStmtListStruct* result = (struct ProgramStmtListStruct*)malloc(sizeof(struct ProgramStmtListStruct));
	result->first = new_element;
	result->last = new_element;
	return result;
}

struct ProgramStmtListStruct* addProgramStmtToProgramStmtList(struct ProgramStmtListStruct* current_list, struct ProgramStmtStruct* new_element)
{
	current_list->last->next = new_element;
	current_list->last = new_element;
	return current_list;
}

struct ProgramStruct* createProgram(struct ProgramStmtListStruct* new_info)
{
	struct ProgramStruct* result = (struct ProgramStruct*)malloc(sizeof(struct ProgramStruct));
	result->info = new_info;
	return result;
}