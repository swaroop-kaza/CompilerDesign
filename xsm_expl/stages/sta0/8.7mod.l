%option noyywrap
%{
	#include<stdio.h>
	#include<stdlib.h>
%}

number		[0-9]+

%%

{number}	{
			printf("Found		:	%d\n",atoi(yytext));
			if(atoi(yytext) % 2 == 0)
				printf("EVEN\n");
			else
				printf("ODD\n");
		}

%%

int main()
{
	yylex();
	return 1;
}
