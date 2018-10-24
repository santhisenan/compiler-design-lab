%{
#include<stdio.h>
#include<stdlib.h>
int yyerror(char* err)
{
    printf("%s", err);
    exit(0);
}
int yylex();
%}
%token DIGIT LETTER
%%
stmt:A
    ;
A: LETTER B
 ;
B: LETTER B
 | DIGIT B
 | LETTER 
 | DIGIT
 ;
%%
int main() {
    printf("String: ");
    printf("\n");
    yyparse();
    printf("valid");
    exit(0);
}

