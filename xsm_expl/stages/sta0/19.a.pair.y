%{
	#include<stdio.h>
	#include<stdlib.h>
	
	int yyerror();
%}

%token 	DIGIT

%%

start	:	pair '\n'		{
						printf("\ncomplete\n");
						exit(1);
					}
	;

pair	:	num ',' num		{ printf("Pair(%d,%d)",$1,$3); }
	;

num	:	DIGIT			{ $$=$1; }
	;
%%

int yyerror()
{
	printf("Error\n");
	return 0;
}

int main()
{
	yyparse();
	return 1;
}
