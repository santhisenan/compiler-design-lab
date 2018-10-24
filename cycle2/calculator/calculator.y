%{
#include <stdio.h>
#include <stdlib.h>
int flag = 0;
int yyerror() {
    printf("Invalid!");
    exit(0);
}
int yylex();
%}
%token NUM
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%
ArithmaticExpr: E{
    printf("\nResult = %d\n", $$);
    return 0;
};
E: E '+' E {$$ = $1 + $3;}
 | E '-' E {$$ = $1 - $3;}
 | E '*' E {$$ = $1 * $3;}
 | E '/' E {$$ = $1 / $3;}
 | E '%' E {$$ = $1 % $3;}
 | '(' E ')' {$$ = $2;}
 | NUM {$$ = $1;}
 ;
%%
int main() {
    printf("\nArithmatic Expression (Allowed symbols: ( ) + - / * and modulo) \n");
    yyparse();
    // printf("Valid!");
    exit(0);
}
