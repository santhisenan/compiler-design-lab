digit [0-9]
letter [A-Za-z]
%{
    int count;
%}

%%
{letter}({letter}|{digit})*     count++;`
%%
int main() {
    yylex();
    printf("Number of identifiers = %d\n", count);
    return 0;
}