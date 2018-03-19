%{
	#include<stdio.h>
%}

%token DIGIT NEWLINE

%%

start	:	expr '\n'		{
						printf("\nComplete\n");
						exit(1);
					}
	;

expr	:	expr '+' expr		{ printf("+ "); }
	|	expr '-' expr		{ printf("- "); }
	|	expr '*' expr		{ printf("* "); }
	|	'(' expr ')'		
	|	DIGIT			{ printf("%d ",$1); }
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
