%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#define YYSTYPE tnode*

	#include "1.c.ifelse.h"
	#include "1.d.ifelse.c"
	#include "1.e.codegen.c"

	int yylex(void);
	void yyerror(char const *s);

	FILE *yyin,*targetFile;
	int reg;
%}

%token NUM ID PLUS MINUS MUL DIV START END NL READ WRITE 
%token IF THEN ELSE ENDIF 
%token WHILE DO ENDWHILE 
%token LT LE GT GE EQ NE 
%token INC DEC 
%token BREAK CNTU 
%token REPEAT UNTIL

%left PLUS MINUS
%left DIV MUL

%nonassoc LT LE GT GE EQ NE

%%

program		:	START Slist END ';'		{
								printf("Evaluating tree\n"); 
								abstEvaluate($2);
								generate($2,targetFile);
							} 
		| 	START END ';'			{}
		;

Slist 		: 	Slist Stmt			{ $$=createTree(0,nodetypeNULL,typenull,NULL,$1,$2,NULL); } 
		| 	Stmt				{ $$=$1; }
		;

Stmt 		:	InputStmt			{ $$=$1; } 
		|	OutputStmt			{ $$=$1; }
		|	AsgStmt				{ $$=$1; }
		|	IfStmt				{ $$=$1; }
		|	WhileStmt			{ $$=$1; }
		|	BREAK	';'			{ $$=createTree(0,nodetypeBRK,typenull,NULL,NULL,NULL,NULL); }
		|	CNTU	';'			{ $$=createTree(0,nodetypeCNTU,typenull,NULL,NULL,NULL,NULL); }
		;

InputStmt	:	READ '(' ID ')' ';' 		{ $$=createTree(0,nodetypeREAD,typenull,NULL,$3,NULL,NULL); } 
		;

OutputStmt	:	WRITE '(' expr ')' ';' 		{ $$=createTree(0,nodetypeWRITE,typenull,NULL,$3,NULL,NULL); }
		;

AsgStmt		:	ID '=' expr ';'			{ $$=createTree(0,nodetypeASGN,typenull,NULL,$1,$3,NULL); }
		;

IfStmt		:	IF '(' expr ')'	THEN Slist ELSE Slist ENDIF ';'	
							{ $$=createTree(0,nodetypeIF,typenull,NULL,$3,$6,$8); }
		|	IF '(' expr ')' THEN Slist ENDIF ';'			
							{ $$=createTree(0,nodetypeIF,typenull,NULL,$3,$6,NULL); }
		;

WhileStmt	:	WHILE '(' expr ')' DO Slist ENDWHILE ';'	
							{ $$=createTree(0,nodetypeWHILE,typenull,NULL,$3,$6,NULL); }
		|	DO Slist WHILE '(' expr ')' ';'				
							{ $$=createTree(0,nodetypeDOWHILE,typenull,NULL,$5,$2,NULL); }
		|	REPEAT Slist UNTIL '(' expr ')' ';'			
							{ $$=createTree(0,nodetypeREPEAT,typenull,NULL,$5,$2,NULL); }
		;	

expr 		: 	expr PLUS expr			{ $$ =createTree(0,nodetypePLUS,typeint,NULL,$1,$3,NULL); }
		| 	expr MINUS expr 		{ $$ =createTree(0,nodetypeMINUS,typeint,NULL,$1,$3,NULL); }
		| 	expr MUL expr			{ $$ =createTree(0,nodetypeMUL,typeint,NULL,$1,$3,NULL); }
		| 	expr DIV expr			{ $$ =createTree(0,nodetypeDIV,typeint,NULL,$1,$3,NULL); }
		| 	'(' expr ')'			{ $$ = $2; }
		| 	NUM				{ $$ = $1; }
		| 	ID 				{ $$ = $1; }
		| 	expr LT expr			{ $$ =createTree(0,nodetypeLT,typebool,NULL,$1,$3,NULL); }
		| 	expr LE expr			{ $$ =createTree(0,nodetypeLE,typebool,NULL,$1,$3,NULL); }
		| 	expr GT expr			{ $$ =createTree(0,nodetypeGT,typebool,NULL,$1,$3,NULL); }
		| 	expr GE expr			{ $$ =createTree(0,nodetypeGE,typebool,NULL,$1,$3,NULL); }
		| 	expr EQ expr			{ $$ =createTree(0,nodetypeEQ,typebool,NULL,$1,$3,NULL); }
		| 	expr NE expr			{ $$ =createTree(0,nodetypeNE,typebool,NULL,$1,$3,NULL); }
		;

%%


void yyerror(char const *s)
{
	printf("yyerror %s %d",s,lcnt);
}


int main(void) 
{
	FILE *fp=fopen("1.input","r");
	lcnt=0;
	if(fp)
		yyin=fp;
	
	else
		printf("Input Error\n");

	targetFile=fopen("1.intermediate.xsm","w");
	
	yyparse();
	return 0;
}
