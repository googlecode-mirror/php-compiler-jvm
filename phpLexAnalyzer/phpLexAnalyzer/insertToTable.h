#ifndef _INSERT_TO_TABLE
#define _INSERT_TO_TABLE_H

#include "semantic_structs.h"

int insertToTable(ConstsTable* table, int number, struct ConstInfo const_info);
int insertToTable(FieldsTable* table, std::string str, struct FieldInfo field);
int insertToTable(MethodsTable* table, std::string str, struct MethodInfo method);
int insertToTable(ClassTable* table, std::string str, struct ClassDefStruct* class_def);
int insertToTable(LocVarTable* table, std::string str, int number);

#endif