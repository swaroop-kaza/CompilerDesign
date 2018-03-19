%option noyywrap
%{
	#include<stdio.h>
	int global_varible;
%}

number		[0-9]+
op		[+|-|*|/|^]

%%

{number}	{printf(" number");}
{op}		{printf(" operator");}

%%

int main()
{
	yylex();
	return 1;
}
