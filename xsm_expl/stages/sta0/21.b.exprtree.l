%{
	#include<stdio.h>
	#include<stdlib.h>

	#include "y.tab.h"

	int number;
%}

%%

[0-9]+		{
			number = atoi(yytext);
			yylval = makeLeafNode(number);
			return NUM;
		}

"+"		{ return PLUS; }

"-"		{ return MINUS; }

"*"		{ return MUL; }

"/"		{return DIV; }

[\t]		

[()]		{ return *yytext; }

[\n]		{ return END; }

.		{ 
			yyerror("UNKNOWN CHAR\n"); 
			exit(1);
		}

%%

int yywrap()
{
	return 1;
}
