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


extern YYSTYPE yylval;
