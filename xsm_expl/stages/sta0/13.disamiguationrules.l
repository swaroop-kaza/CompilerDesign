%option noyywrap
%{
	#include<stdio.h>
%}

%%

"-"		{printf("MINUS\n");}

"--"		{printf("DECREMENT\n");}

%%

int main()
{
	yylex();
	return 1;
}
