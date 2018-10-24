%{
#include<stdio.h>
#include<stdlib.h>
int yyerror()
{
    printf("Invalid!");
    exit(0);
}
int yylex();
%}
%token ID NUMBER
%left '+' '-'
%left '*' '/'
%%
stmt:expr
    ;
expr: expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr  
    | '(' expr ')'
    | NUMBER 
    | ID
    ;
%% 
int main()
{
    printf("Expression:");
    printf("\n");
    yyparse();
    printf("Valid!");
    exit(0);
}
// int yyerror()
// {
//     printf("Invalid!");
//     exit(0);
// }