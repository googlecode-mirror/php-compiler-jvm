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

struct ClassInfo CreateClass(struct ClassDefStruct* class_def);
struct ClassInfo FillClass(struct ClassDefStruct* class_def);

#endif