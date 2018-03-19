%{
    	#include <stdio.h> 
	#include<stdlib.h>

	#include "y.tab.h"
%}

%%

[0-9]+		{
          		yylval = atoi(yytext);
          		return DIGIT;
        	}

[a-zA-Z]+	{
			yylval=yytext;
			return CHAR;
		}

"+"	  	return *yytext;

"-"	  	return *yytext;

"*"	 	return *yytext;

"/"	  	return *yytext;

[()]	  	return *yytext;

[\n]      	return NEWLINE;

%%

yywrap()
{
	return 1;
}
