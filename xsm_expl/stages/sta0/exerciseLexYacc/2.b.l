%{
	#include <stdio.h>	
	#include "y.tab.h"
%}

%%

[0-9a-zA-Z]+		{ printf("---2\n");return CHAR; }

"+"	  		{ printf("---3\n");return *yytext; }

"-"	  		{ printf("---4\n");return *yytext; }

"*"	 	 	{ printf("---5\n");return *yytext; }

"/"	  		{ printf("---6\n");return *yytext; }
	
[()]		  	{ printf("---7\n");return *yytext; }

[\n]	  		{ printf("---8\n");return NEWLINE; }

%%

yywrap()
{
	return 1;
}
