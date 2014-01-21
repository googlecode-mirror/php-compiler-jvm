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

/* ��� ��������� */
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

/* �������� ��������� */
union ConstUnion
{
    /* �������� ��������� UTF8 */
	char utf8_const[150];
    /* �������� ������������� ��������� */
	int int_const;
    /* ����� ������ UTF8 - ��������*/
	int string_num_const;
    /* ����� ������ UTF8 - ����� ������*/
	int class_num_const;

    /* Methodref � Fieldref */
	struct
	{
        /* ����� ������ UTF8 - ����� ������ */
		int class_num_ref_const;
        /* ����� Name&Type ��������� */
		int name_and_type_num_ref_const;
	};
    /* Name&Type */
	struct
	{
        /* ����� ������ UTF8 - �����*/
		int name_num_nat_const;
        /* ����� ������ UTF8 - ����������� */
		int descr_num_nat_const;
	};
};

/* ��������� */
struct ConstInfo
{
    /* ��� ��������� */
	enum ConstTypeEnum �onst_type;
    /* �������� ��������� */
	union ConstUnion const_value;
};

/* ���� */
struct FieldInfo
{
    /* ��� ���� */
	char name_const[100];
    /* ���������� ���� */
	char descr_const[100];
    /* ������� ������� ���� */
	enum ProtectionType protection;
};

/* ����� */
struct MethodInfo
{
    /* ���������� ��������� ���������� */
	int local_val_count;
    /* ������� ��������� ���������� */
	LocVarTable loc_vars;
    /* ��� ������ */
	char name_const[100];
    /* ���������� ������ */
	char descr_const[100];
    /* ������� ������� ������ */
	enum ProtectionType protection;
    /* ����������� ������ */
	bool is_static;

	MethodInfo()
	{
		isStatic = false;
	}
    /* ��������� �� ���� ������ � ��������, ��������������� ������*/
	struct FuncDefStruct* implementation;
};

/* ����� */
struct ClassInfo
{
    /* ��� ������ */
    std::string classname;
	/* ��� �������� */
    std::string parentname;
    /* ������� �������� */
	ConstsTable consts;
    /* ������� ����� */
	FieldsTable fields;
    /* ������� ������� */
	MethodsTable methods;
    
    /* ��������� RTL */
    struct RTLConsts consts;

    /* ����� ������ */
	int class_name_index;

    int parent_constr_num;
};

// ��������� ������� RTL
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