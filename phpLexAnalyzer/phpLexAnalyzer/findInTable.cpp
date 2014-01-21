#include "findInTable.h"

int findInTable(ConstsTable table, struct ConstInfo const_info)
{
	int retVal = -1; 
	ConstTable::const_iterator it;
	
	for (it = table.begin(); it != table.end(); ++it)
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
	return retVal;
}