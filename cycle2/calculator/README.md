# Implementation of Calculator using LEX and YACC
To run the program, run the following commands in a terminal.

```
yacc -d calculator.y

lex calculator.l

cc lex.yy.c y.tab.c -ll

./a.out
```