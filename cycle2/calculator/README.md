# Implementation of Calculator using LEX and YACC
To run the program, follow the steps given.

```
yacc -d calculator.y

lex calculator.l

cc lex.yy.c y.tab.c -ll
```