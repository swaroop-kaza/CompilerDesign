%{
	#include<stdio.h>
%}

%token DIGIT NEWLINE

%left '+'
%left '*'

%%

start	:	expr '\n'		{
						printf("Evaluted value = %d\n",$1);						
						printf("Complete\n");
						exit(1);
					}
	;

expr	:	expr '+' expr		{ $$=$1+$3; }
	|	expr '-' expr		{ $$=$1-$3; }
	|	expr '*' expr		{ $$=$1*$3; }
	|	'(' expr ')'		{ $$=$2; }
	|	DIGIT			{ $$=$1; }
	;

%%

void yyerror(char const *s)
{
	printf("error %s\n",s);
}

int main()
{
	yyparse();
	return 1;
}
