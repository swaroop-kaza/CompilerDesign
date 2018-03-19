%{
	#include <stdio.h>
	#include <stdlib.h>

	#include "y.tab.h"
	#include "1.c.statNexpr.h"

	int number;
%}

%%

"begin"			{ return START; }

"end"			{ return END; }

"read"			{ return READ; }

"write"			{ return WRITE;	}

[a-z]+			{
				yylval=createTree(0,nodetypeID,yytext,NULL,NULL); 
				return ID;
			}

[0-9]+			{
				number = atoi(yytext); 
				yylval = createTree(number,nodetypeLEAF,NULL,NULL,NULL); 
				return NUM;
			}

"+"			{ return PLUS; }

"-"			{ return MINUS; }

"*"			{ return MUL; }

"/"			{ return DIV; }

"="			{ return *yytext; }

[;]			{ return *yytext; }

[()]			{ return *yytext; }

[\t]			{}

[' ']			{}

[\n]			{}

.			{
				printf("%s\n",yytext);
				yyerror("unknown character\n");
				exit(1);
			}
%%

int yywrap()
{
	return 1;
}
