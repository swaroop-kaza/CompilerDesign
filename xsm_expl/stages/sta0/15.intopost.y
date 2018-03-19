/*Declaraations start here*/

/*C declarations start here*/
%{

	#include<stdio.h>
	#include<stdlib.h>
	
	void printOperator(char op);			//custom function to print operator
	
	int pos=0;					//varible to keep tack of position of number

%}
/*C declarations end here*/

/*YACC declarations start here*/

%token	DIGIT
%left	'+'
%left	'*'

/*YACC declarations end here*/

/*Rules start here*/

%%

start		:		expr'\n'		{ exit(1); }
		;

expr		:		expr'*'expr		{ printOperator('*'); }
		|		expr'+'expr		{ printOperator('+'); }
		|		'('expr')'		
		|		DIGIT			{ printf("NUM%d",pos); }
		;

%%

/*Rules end here*/

/*Auxiliary Functions start here*/

void printOperator(char op)
{
	printf("%c",op);
}

yyerror(char const *s)
{
	printf("ERROR	:	%s\n",s);
}

yylex()
{
	char c;

	c=getchar();

	if(isdigit(c))
	{
		pos++;
		return DIGIT;
	}
	
	else if(c==' ')
	{
		yylex();
	}

	else
	{
		return c;
	}

}

int main()
{
	yyparse();
	return 1;
}

/*Auxiliary functions end here*/	
