%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#define YYSTYPE tnode *

	#include "1.c.statNexpr.h"
	#include "1.d.statNexpr.c"
	#include "1.e.codegen.c"

	int yylex(void);
	void yyerror(char const *s);

	FILE *yyin,*targetFile;
	int reg;
%}

%token NUM ID PLUS MINUS MUL DIV START END NL READ WRITE

%left PLUS MINUS
%left MUL DIV

%%

program 	:		START Slist END ';'		{
									printf("Evaluating tree\n"); 
									printf("abstEvalute = %d\n",abstEvaluate($2));

									generate($2,targetFile);

									exit(1);
								} 
		| 		START END ';'			{}
		;

Slist 		: 		Slist Stmt			{ $$=createTree(0,nodetypeNULL,NULL,$1,$2); } 
		| 		Stmt				{ $$=$1; }
		;

Stmt 		:		InputStmt			{ $$=$1; } 
		|		OutputStmt			{ $$=$1; }
		|		AsgStmt				{ $$=$1; }
		;

InputStmt	:		READ '(' ID ')' ';' 		{ $$=createTree(0,nodetypeREAD,NULL,$3,NULL); }
		;

OutputStmt	:		WRITE '(' expr ')' ';'  	{ $$=createTree(0,nodetypeWRITE,NULL,$3,NULL); }
		;

AsgStmt		:		ID '=' expr ';'			{ $$=createTree(0,nodetypeASGN,NULL,$1,$3); }
		;

expr 		: 		expr PLUS expr			{ $$=createTree(0,nodetypePLUS,NULL,$1,$3); }
		| 		expr MINUS expr 		{ $$=createTree(0,nodetypeMINUS,NULL,$1,$3); }
		|	 	expr MUL expr			{ $$=createTree(0,nodetypeMUL,NULL,$1,$3); }
		| 		expr DIV expr			{ $$=createTree(0,nodetypeDIV,NULL,$1,$3); }
		| 		'(' expr ')'			{ $$ = $2; }
		| 		NUM				{ $$ = $1; }
		| 		ID 				{ $$ = $1; }
		;

%%

void yyerror(char const *s)
{
	printf("yyerror %s",s);
}


int main(void) 
{
	FILE *fp=fopen("1.input","r");

	if(fp)
		yyin=fp;
	
	else
		printf("Input Error\n");

	targetFile=fopen("1.output.xsm","w");
	
	yyparse();
	return 0;
}
