//======================= PROGRAM =======================
struct ProgramStruct
{
	struct ProgramStmtListStruct* info;		//	список элементов программы
};

enum ProgramStmtType						//	тип элемента программы
{
	t_main_stmt_list,						//	код программы
	t_html									//	html
};

struct ProgramStmtStruct						//	элемент программы
{
	enum ProgramStmtType type;					//	тип элемента программы
	struct MainStmtListStruct* main_stmt_list;	//	код программы
	char* html;									//	html
	struct ProgramStmtStruct* next;				//	следующий элемент программы
};

struct ProgramStmtListStruct				//	список элементов программы
{
	struct ProgramStmtStruct* first;
	struct ProgramStmtStruct* last;
};

//======================= MAIN =======================
enum MainStmtType							//	тип элемента кода программы
{
	t_class_def,							//	объявление класса
	t_func_def,								//	объявление функции
	t_stmt									//	оператор
};

struct MainStmtStruct						//	элемент кода программы
{
	enum MainStmtType type;					//	тип элемента кода программы
	struct ClassDefStruct* class_def;		//	объявление класса
	struct FuncDefStruct* func_def;			//	объявление функции
	struct StmtStruct* stmt;				//	оператор
	struct MainStmtStruct* next;			//	следующий элемент кода программы
};

struct MainStmtListStruct					//	код программы
{
	struct MainStmtStruct* first;
	struct MainStmtStruct* last;
};

//======================= CONST =======================
enum ConstValueType
{
	t_int,									//	целочисленная константа
	t_bool,									//	логическая константа
	t_char_const							//	строковая константа
};

struct ConstValueStruct						//	константа
{
	enum ConstValueType type;				//	тип константы
    int const_int;							//	целочисленная или логическая константа
	char* const_char;						//	строковая константа
};

//======================= EXPR =======================
enum ExprType								//	тип выражениия
{
	t_const,								//	константа
	
	t_less,									//	<
	t_leq,									//	<=
	t_greater,								//	>	
	t_geq,									//	>=	
	t_eq,									//	==
	t_neq,									//	!=
	t_teq,									//	===
	t_tneq,									//	!==
	
	t_not,									//	!
	t_cor,									//	||	
	t_cand,									//	&&
	t_por,									//	or
	t_pand,									//	and
	
	t_plus,									//	+
	t_minus,								//	-
	t_mult,									//	*
	t_div,									//	/
	t_mod,									//	%
	t_uplus,								//	+ унарный
	t_uminus,								//	- унарный
	
	t_assign,								//	=
	t_plusas,								//	+=
	t_minusas,								//	-=
	t_mulas,								//	*-
	t_divas,								//	/=
	t_modas,								//	%=
	
	t_post_inc,								//	++ постфиксный
	t_post_dec,								//	-- постфиксный
	t_pre_inc,								//	++ префиксный
	t_pre_dec,								//	-- префиксный

    t_var,									//	переменная
	t_string,								//	строка
	
	t_array,								//	массив
	t_func_call								//	вызов функции
};

struct ExprStruct							//	выражение
{
	enum ExprType type;						//	тип выражения
    struct ConstValueStruct* const_value;	//	константа
	struct ExprStruct* left;				//	левый (или единственный) операнд
	struct ExprStruct* right;				//	правый операнд
	struct VarStruct* variable;				//	переменная
	struct StringStruct* string;			//	строка
	struct ArrayStruct* array;				//	массив
	char* id;								//	имя функции
	struct ExprListStruct* list;			//	аргументы функции
	struct ExprStruct* next;				//	следующее выражение в списке
};

struct ExprListStruct						//	список выражений
{
    struct ExprStruct* first;
    struct ExprStruct* last;
};

//======================= STRING =======================
enum StringElementType						//	тип элемента строки
{
	t_const_string,							//	строковая константа
	t_variable								//	переменная
};

struct StringElementStruct					//	элемент строки
{
	enum StringElementType type;			//	тип элемента строки
	char* const_char;						//	строковая константа
	struct VarStruct* var;					//	переменная
	struct StringElementStruct* next;		//	следующий элемент строки
};

struct StringStruct							//	строка
{
	struct StringElementStruct* first;
	struct StringElementStruct* last;
};

//======================= VAR =======================
enum VarElementType							//	тип элемента переменной
{
	t_field_element,						//	поле
	t_method_call,							//	вызов метода
	t_index									//	взятие элемента массива по индексу
};

struct VarElementStruct						//	элемент переменной
{
	enum VarElementType type;				//	тип элемента переменной
	char* member;							//	имя поля или метода
	struct ExprListStruct* params;			//	параметры вызова метода
	struct ExprStruct* index;				//	индекс массива
	struct VarElementStruct* next;			//	следующий элемент переменной
};

struct VarElementListStruct
{
	struct VarElementStruct* first;
	struct VarElementStruct* last;
};

struct VarStruct							//	переменная
{
	char* id;								//	имя переменной
	struct VarElementListStruct* list;		//	список элементов переменной
	int const_table_index;
};

struct VarListElementStruct					//	элемент списка переменных
{
	char* id;								//	имя переменной
	struct ExprStruct* default_value;		//	значение переменной по умолчанию
	struct VarListElementStruct* next;		//	следующий элемент списка переменных
};

struct VarListStruct						//	список переменных
{
	struct VarListElementStruct* first;
	struct VarListElementStruct* last;
};

//======================= ARRAY =======================
struct ArrayElementStruct					//	элемент массива
{
	struct ExprStruct* key;					//	ключ
    struct ExprStruct* value;				//	значение
    struct ArrayElementStruct* next;		//	следующий элемент массива
};

struct ArrayStruct							//	массив
{
	struct ArrayElementStruct* first;
	struct ArrayElementStruct* last;
};

//======================= IF =======================
enum IfStmtType								//	тип условного оператора
{
	t_if,
	t_if_else,
	t_if_elseif
};

struct IfStmtStruct							//	условный оператор
{
	enum IfStmtType type;					//	тип условного оператора
	struct ExprStruct* condition;			//	условие
	struct StmtStruct* stmt;				//	действие при выполнении условия
	struct StmtStruct* else_stmt;			//	действие при невыполнении условия
	struct IfStmtStruct* elseif_stmt;		//	условный оператор при невыполнении условия
};

//======================= CASE =======================
struct CaseStruct							//	одна из веток ветвления
{
	struct ExprStruct* expr;				//	вариант ветвления
	struct StmtListStruct* stmt_list;		//	действия при этом варианте ветвления
	struct CaseStruct* next;				//	следующая ветка ветвления
};

struct CaseStmtListStruct					//	список веток ветвления
{
	struct CaseStruct* first;
	struct CaseStruct* last;
};

struct SwitchStmtStruct						//	оператор ветвления
{
	struct ExprStruct* expr;				//	выражение ветвления
	struct CaseStmtListStruct* case_list;	//	ветки ветвления
	struct StmtListStruct* default_stmt;	//	действия при невыполнении всех веток
};

//======================= FOR =======================
struct ForStmtStruct						//	оператор цикла со счетчиком
{
	struct ExprStruct* start_expr;			//	стартовые условия
	struct ExprStruct* condition;			//	условие продолжения цикла
	struct ExprStruct* end_action;			//	действие после итерации цикла
	struct StmtStruct* stmt;				//	итерация цикла
};

//======================= WHILE =======================
enum WhileType								//	тип цикла с условием
{
	t_while,								//	с предусловием
	t_do_while								//	с постусловием
};

struct WhileStmtStruct						//	оператор цикла с условием
{
	enum WhileType type;					//	тип цикла с условием
	struct ExprStruct* condition;			//	условие продолжения цикла
	struct StmtStruct* stmt;				//	итерация цикла
};

//======================= FOREACH =======================
struct ForeachStmtStruct					//	оператор цикла с итератором
{
	struct ExprStruct* array;				//	условие продолжения цикла
	char* key;								//	ключ элемента массива
	char* value;							//	значение элемента массива
	struct StmtStruct* stmt;				//	итерация цикла
};

//======================= STMT =======================
enum StmtType								//	тип оператора
{
    t_expr,									//	выражение
    t_if_stmt,								//	условный оператор
    t_switch,								//	оператор ветвления
    t_for,									//	оператор цикла со счетчиком
    t_while_do,								//	оператор цикла с условием
    t_foreach,								//	оператор цикла с итератором
	t_func_def_stmt,						//	объявление функции
    t_echo,									//	оператор печати
    t_break,								//	оператор прерывания
	t_return,								//	оператор возврата
    t_stmt_list,							//	список операторов
	t_void
};

struct StmtStruct							//	оператор
{
	enum StmtType type;						//	тип оператора
    struct ExprStruct* expr;				//	выражение
    struct IfStmtStruct* if_stmt;			//	условный оператор
    struct SwitchStmtStruct* switch_stmt;	//	оператор ветвления
	struct ForStmtStruct* for_stmt;			//	оператор цикла со счетчиком
	struct WhileStmtStruct* while_stmt;		//	оператор цикла с условием
	struct ForeachStmtStruct* foreach_stmt;	//	оператор цикла с итератором
	struct FuncDefStruct* func_def;			//	объявление функции
	struct StmtListStruct* list;			//	список операторов
	struct StmtStruct* next;				//	следующий оператор
};

struct StmtListStruct						//	список операторов
{
	struct StmtStruct* first;
	struct StmtStruct* last;
};

/* =============== FUNCTION =============== */
struct FuncDefStruct						//	объявление функции
{
	char* id;								//	имя функции
	struct VarListStruct* var_list;			//	список аргументов
	struct StmtListStruct* stmt_list;		//	тело функции
};

//======================= CLASS =======================
enum ProtectionType							//	тип доступа к члену класса
{
	t_public,
	t_private,
	t_protected
};

struct FieldStruct							//	поле класса
{
	enum ProtectionType protection_type;	//	тип доступа к полю класса
	char* id;								//	имя поля
};

enum BodyType								//	тип элемента тела класса
{
	t_field,								//	поле
	t_method								//	метод
};

struct ClassBodyElementStruct				//	элемент тела класса
{
	enum BodyType type;						//	тип элемента тела класса
	struct FieldStruct* field;				//	поле класса
	struct ConstValueStruct* const_value;	//	значение поля по умолчанию
	enum ProtectionType protection_type;	//	тип доступа к методу класса
	struct FuncDefStruct* func;				//	объявление метода класса
	struct ClassBodyElementStruct* next;	//	следующий элемент тела класса
};

struct ClassBodyElementsListStruct			//	список элементов тела класса
{
	struct ClassBodyElementStruct* first;
	struct ClassBodyElementStruct* last;
};

struct ClassDefStruct							//	объявление класса
{
	char* id;									//	имя класса
	char* parentId;								//	имя родителя
	struct ClassBodyElementsListStruct* body;	//	тело класса
};

