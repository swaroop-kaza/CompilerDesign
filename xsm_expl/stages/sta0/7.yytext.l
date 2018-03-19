%option noyywrap
%{
	#include<stdio.h>
	#include<stdlib.h>
%}

number		[0-9]+

%%

{number}	{printf("Found		:	%d\n",atoi(yytext));}

%%

int main()
{
	yylex();
	return 1;
}
