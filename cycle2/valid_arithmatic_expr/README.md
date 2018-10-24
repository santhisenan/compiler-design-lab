# Program to recognize a valid arithmetic expression that uses operator +, – , * and /.

To run the program, execute the following commands in a terminal.
```
yacc -d valid_arithmatic_expr.y

lex valid_arithmatic_expr.l

gcc lex.yy.c y.tab.c -ll

./a.out
```