%{
#include "bison_input_structs.c"

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
%}

/*==================================================================================================================*/
%union { //yylval
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
}

%type <ConstValueUnion>const_value
%type <ExprUnion>expr
%type <ExprListUnion>expr_list_ne
%type <ExprListUnion>expr_list
%type <ExprListUnion>expr_e
%type <StringUnion>string
%type <VarElementUnion>variable_element
%type <VarElementListUnion>variable_element_list_ne
%type <VarElementListUnion>variable_element_list
%type <VarUnion>variable
%type <VarListElementUnion>var_list_element
%type <VarListUnion>var_list
%type <ArrayElementUnion>array_element
%type <ArrayUnion>array_ne
%type <ArrayUnion>array
%type <IfStmtUnion>if_stmt
%type <IfStmtUnion>else_if_stmt
%type <CaseUnion>case_stmt
%type <CaseStmtListUnion>case_stmt_list
%type <SwitchStmtUnion>switch_stmt
%type <ForStmtUnion>for_stmt
%type <WhileStmtUnion>do_while_stmt
%type <WhileStmtUnion>while_stmt
%type <ForeachStmtUnion>foreach_stmt
%type <StmtUnion>stmt
%type <StmtListUnion>stmt_list_ne
%type <StmtListUnion>stmt_list
%type <FuncDefUnion>function_declaration
%type <FieldUnion>field_name
%type <ClassBodyElementUnion>class_body_element
%type <ClassBodyElementsListUnion>class_body_ne
%type <ClassBodyElementsListUnion>class_body
%type <ClassDefUnion>class_def
%type <MainStmtUnion>main_stmt
%type <MainStmtListUnion>main_stmt_list
%type <ProgramStmtUnion>program_stmt
%type <ProgramStmtListUnion>program_stmt_list
%type <ProgramUnion>program

%token <intConstUnionType>INT_CONST
%token <intConstUnionType>BOOL_CONST
%token <charConstUnionType>CHAR_CONST
%token <htmlUnionType>HTML
%token ARRAY
%token IF ELSE ELSEIF SWITCH CASE BREAK DEFAULT
%token FOR FOREACH AS DO WHILE
%token NEW CLASS THIS EXTENDS PUBLIC PRIVATE PROTECTED STATIC PARENT	//TO DO реализовать NEW, THIS, STATIC, PARENT (':' мб)
%token FUNCTION RETURN
%token ECHO
%token <idUnionType>ID
%token <idUnionType>VARNAME
%token <idUnionType>VARNAME_IN_STR
%token SETVALUE ARROW SCOPEOP											//TO DO реализовать SCOPEOP
%token COR CAND POR PAND
%token PLUSAS MINUSAS MULTAS DIVAS MODAS 								//TO DO добавить оператор точку и точку_равно
%token INC DEC
%token EQ NEQ GEQ LEQ TEQ TNEQ

%left ','
%right '=' PLUSAS MINUSAS MULTAS DIVAS MODAS
%left COR CAND POR PAND
%nonassoc EQ NEQ TEQ TNEQ
%nonassoc '>' '<' GEQ LEQ
%left '+' '-' '.'
%left '*' '/' '%'
%nonassoc '!' UPLUS UMINUS
%left INC DEC ')' ']' '[' ARROW 

/*
	=>	SETVALUE
	->	ARROW
	::	SCOPEOP
	||	COR		С выполняет операнды лишь по необходимости (может не выполнять правые операнды)
	&&	CAND
	or	POR		pascal выполняет все операнды
	and	PAND
	+=	PLUSAS
	-=	MINUSAS
	*=	MULTAS
	/=	DIVAS
	%=	MODAS
*/

%%

/* =============== PROGRAM =============== */
program:
	program_stmt_list							{$$ = root = createProgram($1);}
;

program_stmt_list:
	program_stmt								{$$ = createProgramStmtList($1);}
|	program_stmt_list program_stmt				{$$ = addProgramStmtToProgramStmtList($1, $2);}
;

program_stmt:
	main_stmt_list								{$$ = createProgramStmtMainStmtList($1);}
|	HTML										{$$ = createProgramStmtHtml($1);}
;

main_stmt_list:
	main_stmt									{$$ = createMainStmtList($1);}
|	main_stmt_list main_stmt					{$$ = addMainStmtToMainStmtList($1, $2);}
;

main_stmt:
	class_def									{$$ = createMainStmtClass($1);}
|	stmt										{$$ = createMainStmt($1);}
;

/* =============== CONST_VALUE =============== */
const_value:
	INT_CONST									{$$ = createConst($1, t_int);}
|	BOOL_CONST									{$$ = createConst($1, t_bool);}
|	CHAR_CONST									{$$ = createCharConst($1);}
;

/* =============== EXPR =============== */
expr:
	const_value									{$$ = createConstExpr($1);}
|	'(' expr ')'								{$$ = $2}
|	expr '<' expr								{$$ = createExpr($1, $3, t_less);}
|	expr LEQ expr								{$$ = createExpr($1, $3, t_leq);}
|	expr '>' expr								{$$ = createExpr($1, $3, t_greater);}
|	expr GEQ expr								{$$ = createExpr($1, $3, t_geq);}
|	expr EQ expr								{$$ = createExpr($1, $3, t_eq);}
|	expr NEQ expr								{$$ = createExpr($1, $3, t_neq);}
|	expr TEQ expr								{$$ = createExpr($1, $3, t_teq);}
|	expr TNEQ expr								{$$ = createExpr($1, $3, t_tneq);}
|	'!' expr									{$$ = createUExpr($2, t_not);}
|	expr COR expr								{$$ = createExpr($1, $3, t_cor);}
|	expr CAND expr								{$$ = createExpr($1, $3, t_cand);}
|	expr POR expr								{$$ = createExpr($1, $3, t_por);}
|	expr PAND expr								{$$ = createExpr($1, $3, t_pand);}
|	expr '+' expr								{$$ = createExpr($1, $3, t_plus);}
|	expr '-' expr								{$$ = createExpr($1, $3, t_minus);}
|	expr '*' expr								{$$ = createExpr($1, $3, t_mult);}
|	expr '/' expr								{$$ = createExpr($1, $3, t_div);}
|	expr '%' expr								{$$ = createExpr($1, $3, t_mod);}
|	'+' expr %prec UPLUS						{$$ = createUExpr($2, t_uplus);}
|	'-' expr %prec UMINUS						{$$ = createUExpr($2, t_uminus);}
|	expr '=' expr								{$$ = createExpr($1, $3, t_assign);}
|	expr PLUSAS expr							{$$ = createExpr($1, $3, t_plusas);}
|	expr MINUSAS expr							{$$ = createExpr($1, $3, t_minusas);}
|	expr MULTAS expr							{$$ = createExpr($1, $3, t_mulas);}
|	expr DIVAS expr								{$$ = createExpr($1, $3, t_divas);}
|	expr MODAS expr								{$$ = createExpr($1, $3, t_modas);}
|	expr INC									{$$ = createUExpr($1, t_post_inc);}
|	expr DEC									{$$ = createUExpr($1, t_post_dec);}
|	INC expr									{$$ = createUExpr($2, t_pre_inc);}
|	DEC expr									{$$ = createUExpr($2, t_pre_dec);}
|	variable									{$$ = createVarExpr($1);}
|	string										{$$ = createStrExpr($1);}
|	ARRAY '(' array ')'							{$$ = createArrayExpr($3);}
|	ID '(' expr_list ')'						{$$ = createFuncCallExpr($1, $3);}
;

expr_list_ne:
	expr										{$$ = createExprList($1);}
|	expr_list_ne ',' expr						{$$ = addExprToExprList($1, $3);}
;

expr_list:
	/*empty*/									{$$ = 0;}
|	expr_list_ne								{$$ = $1;}
;

expr_e:
	/*empty*/									{$$ = 0;}
|	expr										{$$ = $1;}
;

/* =============== STRING =============== */
string:
	CHAR_CONST VARNAME_IN_STR CHAR_CONST		{$$ = createString($1, $2, $3);}
|	string VARNAME_IN_STR CHAR_CONST			{$$ = addElementToString($1, $2, $3);}
;

/* =============== VARNAME/VARIABLE =============== */
variable_element:
	ARROW ID									{$$ = createVariableFieldElement($2);}
|	ARROW ID '(' expr_list ')'					{$$ = createVariableMethodElement($2, $4);}
// |	ARROW variable
// |	ARROW '{' string '}'
|	'[' expr ']'								{$$ = createVariableIndexElement($2);}
;

variable_element_list_ne:
	variable_element							{$$ = createElementsList($1);}
|	variable_element_list_ne variable_element	{$$ = addElementToElementsList($1, $2);}
;

variable_element_list:
	/*empty*/									{$$ = 0;}
|	variable_element_list_ne					{$$ = $1;}
;

variable:
	VARNAME variable_element_list				{$$ = createVariable($1, $2);}
;

var_list_element:
	VARNAME										{$$ = createVarListElement($1);}
|	VARNAME '=' expr							{$$ = createVarListElementWithValue($1, $3);}
;

var_list:
	var_list_element							{$$ = createVarList($1);}
|	var_list ',' var_list_element				{$$ = addElementToVarList($1, $3);}
;

/* =============== ARRAY =============== */
array_element:
	expr										{$$ = createArrayElement($1);}
|	expr SETVALUE expr							{$$ = createArrayElementWithValue($1, $3);}
;

array_ne:
	array_element								{$$ = createArrayElementsList($1);}
|	array_ne ',' array_element					{$$ = addElementToArrayElementsList($1, $3);}
;

array:
	/*empty*/									{$$ = 0;}
|	array_ne									{$$ = $1;}
;

/* =============== IF/ELSEIF/CASE/CASE_LIST/SWITCH =============== */
if_stmt:
	IF '(' expr ')' stmt						{$$ = createIfStmt($3, $5);}
|	IF '(' expr ')' stmt ELSE stmt				{$$ = createIfElseStmt($3, $5, $7);}
|	IF '(' expr ')' stmt else_if_stmt			{$$ = createIfElseIfStmt($3, $5, $6);}
;

else_if_stmt:
	ELSEIF '(' expr ')' stmt					{$$ = createIfStmt($3, $5);}
|	ELSEIF '(' expr ')' stmt ELSE stmt			{$$ = createIfElseStmt($3, $5, $7);}
| 	ELSEIF '(' expr ')' stmt else_if_stmt		{$$ = createIfElseIfStmt($3, $5, $6);}
;

case_stmt:
	CASE expr ':' stmt_list						{$$ = createCaseStmt($2, $4);}
;

case_stmt_list:
	case_stmt									{$$ = createCaseStmtList($1);}
|	case_stmt_list case_stmt					{$$ = addCaseStmtToCaseStmtList($1, $2);}
;

switch_stmt:
	SWITCH '(' expr ')' '{' case_stmt_list '}'						{$$ = createSwitchStmt($3, $6);}
|	SWITCH '(' expr ')' '{' case_stmt_list DEFAULT ':' stmt_list	{$$ = createSwitchStmtWithDefault($3, $6, $9);}
;

/* =============== FOR/DO/WHILE/FOREACH =============== */
for_stmt:
	FOR '(' expr_e ';' expr_e ';' expr_e ')' stmt					{$$ = createForStmt($3, $5, $7, $9);}
;

do_while_stmt:
	DO '{' stmt '}' WHILE '(' expr ')' ';'		{$$ = createWhileStmt($7, $3, t_do_while);}
;

while_stmt:
	WHILE '(' expr ')' stmt						{$$ = createWhileStmt($3, $5, t_while);}
;

foreach_stmt:
	FOREACH '(' expr AS VARNAME ')' stmt							{$$ = createForeachStmt($3, $5, $7);}
|	FOREACH '(' expr AS VARNAME SETVALUE VARNAME ')' stmt			{$$ = createForeachStmtWithKey($3, $5, $7, $9);}
;

/* =============== STMT =============== */
stmt:
	expr ';'									{$$ = createStmtExpr($1);}
|	if_stmt										{$$ = createStmtIf($1);}
|	switch_stmt									{$$ = createStmtSwitch($1);}
|	for_stmt									{$$ = createStmtFor($1);}
|	do_while_stmt								{$$ = createStmtWhile($1);}
|	while_stmt									{$$ = createStmtWhile($1);}
|	foreach_stmt								{$$ = createStmtForeach($1);}
|	function_declaration						{$$ = createStmtFuncDef($1);}
|	ECHO expr									{$$ = createStmtEcho($2);}
|	BREAK ';'									{$$ = createStmtBreak();}
|	RETURN expr_e ';'							{$$ = createStmtReturn($2);}
|	'{' stmt_list '}'							{$$ = createStmtStmtlist($2);}
|	';'											{$$ = createStmtVoid();}
;

stmt_list_ne:
	stmt										{$$ = createStmtList($1);}
|	stmt_list_ne stmt							{$$ = addStmtToStmtList($1, $2);}
;

stmt_list:
	/*empty*/									{$$ = 0;}
|	stmt_list_ne								{$$ = $1}
;

/* =============== FUNCTION =============== */
function_declaration:
	FUNCTION ID '(' var_list ')' '{' stmt_list '}'					{$$ = createFuncDef($2, $4, $7);}
;

/* =============== CLASS =============== */
field_name:
	PUBLIC VARNAME								{$$ = createField($2, t_public);}
|	PRIVATE VARNAME								{$$ = createField($2, t_private);}
|	PROTECTED VARNAME							{$$ = createField($2, t_protected);}
;

class_body_element:
	field_name ';'								{$$ = createFieldElement($1);}
|	field_name '=' const_value ';'				{$$ = createFieldWithValue($1, $3);} //TODO: перенести это в филд
|	function_declaration						{$$ = createMethod($1, t_public);}
| 	PUBLIC function_declaration					{$$ = createMethod($2, t_public);}
|	PRIVATE function_declaration				{$$ = createMethod($2, t_private);}
|	PROTECTED function_declaration				{$$ = createMethod($2, t_protected);}
;

class_body_ne:
	class_body_element							{$$ = createBody($1);}
|	class_body_ne class_body_element			{$$ = addElementToBody($1, $2);}
;

class_body:
	/*can be empty*/							{$$ = 0;}
|	class_body_ne								{$$ = $1;}
;

class_def:
	CLASS ID '{' class_body '}'					{$$ = createClass($2, $4);}
|	CLASS ID EXTENDS ID '{' class_body '}'		{$$ = createExtendedClass($2, $4, $6);}
;

%%

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