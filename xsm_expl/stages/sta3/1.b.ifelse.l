%{
	#include <stdio.h>
	#include <stdlib.h>

	#include "y.tab.h"
	#include "1.c.ifelse.h"

	int number;
%}

%%

"begin"		{return START;}

"end"		{return END;}

"read"		{return READ;}

"write"		{return WRITE;}	

"if"		{return IF;}

"then"		{return THEN;}

"else"		{return ELSE;}

"endif"		{return ENDIF;}

"while"		{return WHILE;}

"do"		{return DO;}

"endwhile"	{return ENDWHILE;}

"break"		{return BREAK;}

"continue"	{return CNTU;}

"repeat"	{return REPEAT;}

"until"		{return UNTIL;}

[a-z]+		{
			yylval=createTree(0,nodetypeID,typeint,yytext,NULL,NULL,NULL); 
			return ID;
		}

[0-9]+		{
			number = atoi(yytext); 
			yylval = createTree(number,nodetypeLEAF,typeint,NULL,NULL,NULL,NULL); 
			return NUM;
		}

"+"		{return PLUS;}

"++"		{return INC;}

"-"		{return MINUS;}

"--"		{return DEC;}

"*"		{return MUL;}

"/"		{return DIV;}

"<"		{return LT;}

"<="		{return LE;}

">"		{return GT;}

">="		{return GE;}

"=="		{return EQ;}

"!="		{return NE;}

"="		{return *yytext;}

[;]		{return *yytext;}

[()]		{return *yytext;}

[\t]		{}

[' ']		{}

[\n]		{lcnt++;}

.		{
			yyerror("unknown character\n");
			exit(1);
		}

%%


int yywrap() 
{
	return 1;
}
