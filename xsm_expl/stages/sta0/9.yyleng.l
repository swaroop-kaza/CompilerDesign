%option noyywrap
%{
	#include<stdio.h>
	#include<stdlib.h>
%}

number		[0-9]+

%%

{number}	{
			printf("Found		:	%d\n",atoi(yytext));
			printf("Number of digits:	%d\n",yyleng);
		}

%%

int main()
{
	yylex();
	return 1;
}
