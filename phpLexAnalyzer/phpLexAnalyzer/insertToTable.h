#ifndef _INSERT_TO_TABLE
#define _INSERT_TO_TABLE_H

#include "parser_structs.h"
#include <string>
#include <hash_map>

typedef std::pair<int, struct ConstInfo> ConstPair;
typedef stdext::hash_map<int, struct ConstInfo> ConstsTable;
int insertToTable(ConstsTable* table, int number, struct ConstInfo const_info);

typedef std::pair<std::string, struct FieldInfo> FieldPair;
typedef stdext::hash_map<std::string, struct FieldInfo> FieldsTable;
int insertToTable(FieldsTable* table, std::string str, struct FieldInfo field);

typedef std::pair<std::string, struct MethodInfo> MethodPair;
typedef stdext::hash_map<std::string, struct MethodInfo> MethodsTable;
int insertToTable(MethodsTable* table, std::string str, struct MethodInfo method);

typedef std::pair<std::string, struct ClassInfo> ClassPair;
typedef stdext::hash_map<std::string, struct ClassInfo> ClassTable;
int insertToTable(ClassTable* table, std::string str, struct ClassDefStruct* class_def);

typedef std::pair<std::string, int> LocVarPair;
typedef stdext::hash_map<std::string, int> LocVarTable;
int insertToTable(LocVarTable* table, std::string str, int number);

#endif