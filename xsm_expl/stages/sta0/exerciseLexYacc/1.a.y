%{
	#include <stdio.h>
	#include<stdlib.h>

      	#define YYSTYPE char*
%}

%token DIGIT NEWLINE CHAR

%left '+' '-'
%left '*' '/'

%%

start 	: 	expr NEWLINE  		{
                        			printf("\nComplete\n");
                        			exit(1);
                      			}
  	;

expr	:  	expr '+' expr        	{printf("+ ");}
  	| 	expr '-' expr     	{printf("- ");}
  	| 	expr '*' expr     	{printf("* ");}
  	| 	expr '/' expr     	{printf("/ ");}
 	| 	'(' expr ')'		
  	| 	CHAR             	{printf("%s ",$1);}
  	;

%%

void yyerror(char const *s)
{
    	printf("yyerror  %s\n",s);
}

int main()
{
  	yyparse();
  	return 1;
}
