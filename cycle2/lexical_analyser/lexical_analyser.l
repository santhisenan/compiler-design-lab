%{
int isComment=0;
%}
id [a-zA-Z][a-zA-Z0-9]*
%%
#.* {printf("\n%s -- Preprocessor directive",yytext);}
int |
float |
char |
double |
while |
for |
struct |
typedef |
do |
if |
break |
continue |
void |
switch |
return |
else |
goto {printf("\n\t%s -- Keyword",yytext);}
"/*" {isComment=1;}{printf("\n\t %s -- comment",yytext);}
{id}\( {if(!isComment)printf("\n Function \n\t%s",yytext);}
\{  {if(!isComment)printf("\n Beginning of the block");}
\}  {if(!isComment)printf("End of the block");}
{id}(\[[0-9]*\])? {if(!isComment) printf("\n %s : Identifier",yytext);}
\".*\" {if(!isComment)printf("\n\t %s : String",yytext);}
[0-9]+ {if(!isComment) printf("\n %s : Number ",yytext);}
\)(\:)? {if(!isComment)printf("\n\t");ECHO;printf("\n");}
\( ECHO;
= {if(!isComment)printf("\n\t %s : Assignment operator",yytext);}
\<= |
\>= |
\< |
== |
\> {if(!isComment) printf("\n\t%s : Relational operator",yytext);}
%%
int main(int argc, char **argv)
{
FILE *file;
file=fopen("var.c","r");
if(!file)
{
printf("The file cannot be opened!");
exit(0);
}
yyin=file;
yylex();
printf("\n");
return(0);
}
int yywrap()
{
return(1);
}
