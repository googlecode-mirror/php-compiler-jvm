echo Bison runing...
copy /Y grammar.y D:\GnuWin32\bin\grammar.y
D:
cd D:\GnuWin32\bin
bison.exe -d --verbose grammar.y -o parser.c
F:
copy /Y D:\GnuWin32\bin\parser.h parser.h
copy /Y D:\GnuWin32\bin\parser.c parser.c
copy /Y D:\GnuWin32\bin\parser.output parser.output
pause