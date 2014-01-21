#ifndef _SEMANTIC_H
#define _SEMANTIC_H

#include <vector>
#include <windows.h>
#include <atlbase.h>
#include "insertToTable.h"

//#define MAIN_CLASS_NAME "PHPmain"
//#define JAVA_OBJECT_CLASSNAME "java/lang/Object"
//#define UNIVERSAL "Lrtl/UniversalVariable;"
//
//using namespace std;
//
//#define BASE "rtl/base"
//#define BASE_FIELD_IN_UNIVERSAL "object"
//#define INIT "<init>"
//
//#define PARENT_CONST_CLASS 6

/* Тип константы */
enum ConstTypeEnum
{
	const_utf8,
	const_int,
	const_string,
	const_class,
	const_methodref,
	const_nameandtype,
	const_field
};

/* Значение константы */
union ConstUnion
{
    /* Значение константы UTF8 */
	char utf8_const[150];
    /* Значение целочисленной константы */
	int int_const;
    /* Номер строки UTF8 - литерала*/
	int string_num_const;
    /* Номер строки UTF8 - имени класса*/
	int class_num_const;

    /* Methodref и Fieldref */
	struct
	{
        /* Номер строки UTF8 - имени класса */
		int class_num_ref_const;
        /* Номер Name&Type константы */
		int name_and_type_num_ref_const;
	};
    /* Name&Type */
	struct
	{
        /* Номер строки UTF8 - имени*/
		int name_num_nat_const;
        /* Номер строки UTF8 - дескриптора */
		int descr_num_nat_const;
	};
};

/* Константа */
struct ConstInfo
{
    /* Тип константы */
	enum ConstTypeEnum сonst_type;
    /* Значение константы */
	union ConstUnion const_value;
};

/* Поле */
struct FieldInfo
{
    /* Имя поля */
	char name_const[100];
    /* Дескриптор поля */
	char descr_const[100];
    /* Уровень доступа поля */
	enum ProtectionType protection;
};

/* Метод */
struct MethodInfo
{
    /* Количество локальных переменных */
	int local_val_count;
    /* Таблица локальных переменных */
	LocVarTable loc_vars;
    /* Имя метода */
	char name_const[100];
    /* Дескриптор метода */
	char descr_const[100];
    /* Уровень доступа метода */
	enum ProtectionType protection;
    /* Статичность метода */
	bool is_static;

	MethodInfo()
	{
		isStatic = false;
	}
    /* Указатель на узел дерева с функцией, соответствующей методу*/
	struct FuncDefStruct* implementation;
};

/* Класс */
struct ClassInfo
{
    /* Имя класса */
    std::string classname;
	/* Имя родителя */
    std::string parentname;
    /* Таблица констант */
	ConstsTable consts;
    /* Таблица полей */
	FieldsTable fields;
    /* Таблица методов */
	MethodsTable methods;
    
    /* Константы RTL */
    struct RTLConsts consts;

    /* Номер класса */
	int class_name_index;

    int parent_constr_num;
};

// Константы методов RTL
struct RTLConsts
{
    int echo;
    int universalVariableClass;
    int universalVariableConstructor;
    int toString;
    int getString;
    int getMe;
    int append;
    int toInt;
    int getInt;

    int getBool;

    int invert;
    int sum;
    int sub;
    int mul;
    int div;
    int mod;

    int and;
    int or;
    int not;

    int greater;
    int geq;
    int less;
    int leq;
    int equal;
    int ne;
    int tequal;

    int addKeyValue;
    int SaddKeyValue;
    int addValue;
    int toArray;
    int getValue;
    int getCount;

    int getBase;
    int SgetBase;
	int setBase;
};

struct ClassInfo CreateClass(struct ClassDefStruct* class_def);
struct ClassInfo FillClass(struct ClassDefStruct* class_def);

#endif