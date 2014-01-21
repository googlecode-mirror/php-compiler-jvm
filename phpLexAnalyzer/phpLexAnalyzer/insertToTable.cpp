#include "insertToTable.h"
#include "semantic.h"
#include <stdio.h>

// Добавление константы в таблицу констант
int insertToTable(ConstsTable* table, int number, struct ConstInfo const_info)
{
	int retVal = -1; 
	ConstTable::const_iterator it;
	for (it = table->begin(); it != table->end(); ++it)
		if (const_info.сonst_type == it->second.сonst_type)
			switch (it->second.сonst_type)
			{
				case const_utf8:
					if (strcmp(const_info.const_value.utf8_const, it->second.const_value.utf8_const) == 0)
						retVal = it->first;
					break;
				case const_int: 
					if (const_info.const_value.int_const == it->second.const_value.int_const)
						retVal = it->first;
					break;
				case const_string:
					if (const_info.const_value.string_num_const == it->second.const_value.string_num_const)
						retVal = it->first;
					break;
				case const_class:
					if (const_info.const_value.class_num_const == it->second.const_value.class_num_const)
						retVal = it->first;
					break;
				case const_methodref:
				case const_field:
					if (const_info.const_value.class_num_ref_const == it->second.const_value.class_num_ref_const && 
						const_info.const_value.name_and_type_num_ref_const == it->second.const_value.name_and_type_num_ref_const)
						retVal = it->first;
					break;
				case const_nameandtype:
					if (const_info.const_value.descr_num_nat_const == it->second.const_value.descr_num_nat_const && 
						const_info.const_value.name_num_nat_const == it->second.const_value.name_num_nat_const)
						retVal = it->first;
					break;
				default:
					retVal = -1;
			}

	if(retVal == -1)
	{
		table->insert(ConstPair(number, const_info));
		retVal = table->size();
	}
	return retVal;
}

// Добавление поля в таблицу полей
int insertToTable(FieldsTable* table, std::string str, struct FieldInfo field)
{
	int retVal = -1;
	FieldTable::const_iterator it;

	int i = 0;
	for (it = table->begin(); it != table->end(); ++it)
	{
		if (it->first == str)
			retVal = i;
		++i;
	}

	if (retVal == -1)
	{
		table->insert(FieldPair(str, field));
		retVal = table->size();
	}
	return retVal;
}

// Добавление метода в таблицу методов
int insertToTable(MethodsTable* table, std::string str, struct MethodInfo method)
{
	int retVal = -1;
	MethodsTable::const_iterator it;

	int i = 0;
	for (it = table->begin(); it != table->end(); ++it)
	{
		if (it->first == string(str + string(method.descr_const)))
			retVal = i;
		++i;
	}

	if (retVal == -1)
	{
		if(str == string("__construct"))
		{
			method.name_const[0] =  0;
			method.descr_const[strlen(method.descr_const) - strlen(UNIVERSAL)] = 'V';
			method.descr_const[strlen(method.descr_const) - strlen(UNIVERSAL)+1] = 0;
			strcpy(method.name_const, INIT);
			table->insert(MethodPair(string(INIT) + string(method.descr_const), method));
			retVal = table->size();
		}
		else
		{
			table->insert(MethodPair(str + string(method.descr_const), method));
			retVal = table->size();
		}
	}
	return retVal;
}

// Добавление класса в таблицу классов
int insertToTable(ClassTable* table, std::string str, struct ClassDefStruct* class_def)
{
	int retVal = -1;
	ClassTable::const_iterator it;

	int i = 0;
	for (it = table->begin(); it != table->end(); ++it)
	{
		if (it->first == str)
			retVal = i;
		++i;
	}

	if (retVal == -1)
	{
		table->insert(ClassPair(str, FillClass(class_def)));
		retVal = table->size();
	}
	return retVal;
}

// Добавление локальной переменной в таблицу локальных переменных
int insertToTable(LocVarTable* table, std::string str, int number)
{
	int retVal = -1;

	if (table->find(str) != table->end())
		retVal = table->find(str)->second;
	else
	{
		table->insert(LocVarPair(str, number));
		retVal = table->size();
	}
	return retVal;
}