echo Bison runing...
rem bison_input.yacc_tab.h
rem bison_input.yacc_tab.c
bison.exe -d --verbose bison_input.yacc
rem phpLexAnalyzer\phpLexAnalyzer\bison_input.yacc_tab.c
rem phpLexAnalyzer\phpLexAnalyzer\bison_input.yacc_tab.h
rem phpLexAnalyzer\phpLexAnalyzer\bison_input_structs.c
copy /Y bison_input.yacc_tab.c phpLexAnalyzer\phpLexAnalyzer\bison_input.yacc_tab.c
copy /Y bison_input.yacc_tab.h phpLexAnalyzer\phpLexAnalyzer\bison_input.yacc_tab.h
copy /Y bison_input_structs.c phpLexAnalyzer\phpLexAnalyzer\bison_input_structs.c
pause