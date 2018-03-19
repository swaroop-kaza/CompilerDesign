%{
	#include<stdio.h>
	#include<stdlib.h>
%}

%union
{
	char charter;
	int integer;
};

%token NEWLINE DIGIT
%token OP
%token NUMBER

%type	<charater>	OP
%type	<integer>	NUMBER 
%type	<integer>	expr
%type	<integer>	DIGIT

%%

start	:	expr NEWLINE		{
						printf("\nComplete\n");
						exit(1);
					}
	;

expr	:	expr OP expr		{ printf("%c %d %d",$2,$1,$3); }
	|	'(' expr ')'		{}
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
