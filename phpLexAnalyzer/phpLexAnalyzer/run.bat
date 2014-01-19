@echo _________
@echo bison...
@echo _________
bison.exe -d --verbose grammar.y -o parser.c
@echo _________
@echo flex...
@echo _________
flex.exe -l lexems.l
@pause