%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#define YYSTYPE tnode *

	#include "1.c.dec.h"
	#include "1.d.dec.c"

	#include "1.e.symbolTable.h"
	#include "1.f.symbolTable.c"

	#include "1.g.codegen.c"

	int yylex(void);
	void yyerror(char const *s);

	FILE *yyin,*targetFile;
	int reg,type;
%}

%token NUM ID PLUS MINUS MUL DIV START END NL READ WRITE 
%token IF THEN ELSE ENDIF 
%token WHILE DO ENDWHILE 
%token LT LE GT GE EQ NE 
%token INC DEC 
%token BREAK CNTU 
%token REPEAT UNTIL
%token STRING
%token DECL ENDDECL INTG STR POINTER 

%left PLUS MINUS
%left DIV MUL

%nonassoc LT LE GT GE EQ NE

%%

program		:	Declarations main 		{
								generate($2,targetFile);
								exit(1);
							}
		;

main 		: 	START Slist END ';'		{ $$=$2; } 
		| 	START END	';'		{}
		;

Slist 		: 	Slist Stmt			{ $$=createTree(0,nodetypeNULL,typenull,NULL,$1,$2,NULL); } 
		| 	Stmt				{ $$=$1; }
		;

Stmt 		:	InputStmt			{ $$=$1; } 
		|	OutputStmt			{ $$=$1; }
		|	AsgStmt			 	{ $$=$1; }
		|	IfStmt				{ $$=$1; }
	 	|	WhileStmt			{ $$=$1; }
		|	BREAK	';'			{ $$=createTree(0,nodetypeBRK,typenull,NULL,NULL,NULL,NULL); }
		|	CNTU	';'			{ $$=createTree(0,nodetypeCNTU,typenull,NULL,NULL,NULL,NULL); }
		;

InputStmt	:	READ '(' ID ')' ';' 		{
								tempST=LookUp($3->varname);

								if(tempST==NULL)
								{
									yyerror("undefined Variable");
								
									printf("%s\n",$3->varname );
									exit(1);
								}
								else 
									$3->Gentry=tempST;
									
								$$=createTree(0,nodetypeREAD,typenull,NULL,$3,NULL,NULL);
							}
		|	READ '(' ID '[' expr ']' ')' ';'{
								tempST=LookUp($3->varname);
									
								if(tempST==NULL)
								{
									yyerror("undefined Variable");
									
									printf("%s\n",$3->varname );
									exit(1);
								}

								else 
									$3->Gentry=tempST;

								$$=createTree(0,nodetypeARRREAD,typenull,NULL,$3,$5,NULL);
							}
		|	READ '(' ID '[' expr ']' '[' expr ']' ')' ';' 
							{
								tempST=LookUp($3->varname);
								
								if(tempST==NULL)
								{
									yyerror("undefined Variable");
										
									printf("%s\n",$3->varname );
									exit(1);
								}

								else 
									$3->Gentry=tempST;

								struct tnode *temp=createTree(tempST->s2,nodetypeLEAF,typeint,NULL,NULL, NULL,NULL);
								$5=createTree(0,nodetypeMUL,typeint,NULL,$5,temp,NULL);
								$5=createTree(0,nodetypePLUS,typeint,NULL,$5,$8,NULL);
								$$=createTree(0,nodetypeARRREAD,typenull,NULL,$3,$5,NULL);
							}
		;

OutputStmt	:	WRITE '(' expr ')' ';'		{ $$=createTree(0,nodetypeWRITE,typenull,NULL,$3,NULL,NULL); }
		;

AsgStmt		:	ID '=' expr ';'			{
								tempST=LookUp($1->varname);
									
								if(tempST==NULL)
								{
									yyerror("undefined Variable");
							
									printf("%s\n",$1->varname );
									exit(1);
								}
				
								else 
								{
									$1->Gentry=tempST;
									
									if(tempST->type==typeint || tempST->type==typeintptr)
										$1->type=typeint;
									
									else if(tempST->type==typechar||tempST->type==typestrptr)
										$1->type=typechar;
								}
								
								$$=createTree(0,nodetypeASGN,typenull,NULL,$1,$3,NULL);
							}
		|	ID '[' expr ']' '=' expr ';'	{
								tempST=LookUp($1->varname);

								if(tempST==NULL)
								{
									yyerror("undefined Variable");
									
									printf("%s\n",$1->varname );
									exit(1);
								}

								else 
								{
									$1->Gentry=tempST;
						
									if(tempST->type==typearrint)
										$1->type=typeint;
							
									else if(tempST->type==typestr)
										$1->type=typechar;
								}
								
								$$=createTree(0,nodetypeARRASGN,typenull,NULL,$1,$3,$6);
							}
		|	ID '[' expr ']' '[' expr ']' '=' expr ';' 
							{ 
								tempST=LookUp($1->varname);
						
								if(tempST==NULL)
								{
									yyerror("undefined Variable");

									printf("%s\n",$1->varname );
									exit(1);
								}
								
								else 
								{
									$1->Gentry=tempST;
									
									if(tempST->type==typearrint)
										$1->type=typeint;
									
									else if(tempST->type==typestr)
										$1->type=typechar;
								}
								struct tnode *temp=createTree(tempST->s2,nodetypeLEAF,typeint,NULL,NULL, NULL,NULL);
								$3=createTree(0,nodetypeMUL,typeint,NULL,$3,temp,NULL);
								$3=createTree(0,nodetypePLUS,typeint,NULL,$3,$6,NULL);
								$$=createTree(0,nodetypeARRASGN,typenull,NULL,$1,$3,$9); 
							}
		|	MUL ID '=' expr	';'		{
								tempST=LookUp($2->varname);

								if(tempST==NULL)
								{
									yyerror("undefined Variable");
			
									printf("%s\n",$2->varname );
									exit(1);
								}

								else 
								{
									$2->Gentry=tempST;
							
									if(tempST->type==typeintptr)
										$2->type=typeint;
								
									else if(tempST->type==typestrptr)
										$2->type=typechar;
								}
					
								$$=createTree(0,nodetypePASGN,typenull,NULL,$2,$4,NULL);
							}	
		;

IfStmt		:	IF '(' expr ')'	THEN Slist ELSE Slist ENDIF ';'	
							{ $$=createTree(0,nodetypeIF,typenull,NULL,$3,$6,$8); }
		|	IF '(' expr ')' THEN Slist ENDIF ';'			
							{ $$=createTree(0,nodetypeIF,typenull,NULL,$3,$6,NULL); }
		;

WhileStmt	:	WHILE '(' expr ')' DO Slist ENDWHILE ';'	
							{ $$=createTree(0,nodetypeWHILE,typenull,NULL,$3,$6,NULL); }
		|	DO Slist WHILE '(' expr ')' ';'	{ $$=createTree(0,nodetypeDOWHILE,typenull,NULL,$5,$2,NULL); }
		|	REPEAT Slist UNTIL '(' expr ')' ';'			
							{ $$=createTree(0,nodetypeREPEAT,typenull,NULL,$5,$2,NULL); }
		;	

expr 		: 	expr PLUS expr			{ $$=createTree(0,nodetypePLUS,typeint,NULL,$1,$3,NULL); }
		| 	expr MINUS expr 		{ $$=createTree(0,nodetypeMINUS,typeint,NULL,$1,$3,NULL); }
		| 	expr MUL expr			{ $$=createTree(0,nodetypeMUL,typeint,NULL,$1,$3,NULL); }
		| 	expr DIV expr			{ $$=createTree(0,nodetypeDIV,typeint,NULL,$1,$3,NULL); }
		| 	'(' expr ')'			{ $$=$2; }
		| 	NUM				{ $$=$1; }
		| 	STRING 				{ $$=$1; }
		| 	expr LT expr			{ $$=createTree(0,nodetypeLT,typebool,NULL,$1,$3,NULL); }
		| 	expr LE expr			{ $$=createTree(0,nodetypeLE,typebool,NULL,$1,$3,NULL); }
		| 	expr GT expr			{ $$=createTree(0,nodetypeGT,typebool,NULL,$1,$3,NULL); }
		| 	expr GE expr			{ $$=createTree(0,nodetypeGE,typebool,NULL,$1,$3,NULL); }
		| 	expr EQ expr			{ $$=createTree(0,nodetypeEQ,typebool,NULL,$1,$3,NULL); }
		| 	expr NE expr			{ $$=createTree(0,nodetypeNE,typebool,NULL,$1,$3,NULL); }
		|	ID 				{
								tempST=LookUp($1->varname);
								
								if(tempST==NULL)
								{
									yyerror("undefined Variable ");
									
									printf(" %s\n",$1->varname );
									exit(1);
								}
								
								else 
								{
									$1->Gentry=tempST;
									$1->type=tempST->type;
								}

								$$ = $1;
							}
		| 	ID '[' expr ']'			{
								tempST=LookUp($1->varname);
								
								if(tempST==NULL)
								{
									yyerror("undefined Variable");
			
									printf("%s\n",$1->varname );
									exit(1);
								}

								else
								{
									$1->Gentry=tempST; 
								
									if(tempST->type==typearrint)
										$1->type=typeint;
										
									else if(tempST->type==typestr)
										$1->type=typechar;
								}
								
								$$ = createTree(0,nodetypeARRID,$1->type,NULL,$1,$3,NULL);
							}
		| 	ID '[' expr ']' '['expr']'	{
								tempST=LookUp($1->varname);
								
								if(tempST==NULL)
								{
									yyerror("undefined Variable");
	
									printf("%s\n",$1->varname );
									exit(1);
								}

								else 
								{
									$1->Gentry=tempST; 
									
									if(tempST->type==typearrint)
										$1->type=typeint;
										
									else if(tempST->type==typestr)
										$1->type=typechar;
								}
								$$=createTree(0,nodetypeARRID,$1->type,NULL,$1,$3,$6);
							}
		| 	MUL ID				{
								tempST=LookUp($2->varname);
							
								if(tempST==NULL)
								{
									yyerror("undefined Variable");

									printf("%s\n",$2->varname );
									exit(1);
								}
								
								if(tempST->type!=typeintptr && tempST->type!=typestrptr)
								{
									yyerror("type mismatch");

									printf("%s\n",$2->varname );
									exit(1);
								}

								else 
								{
									$2->Gentry=tempST; 
										
									if(tempST->type==typeintptr)
										$2->type=typeint;
										
									else if(tempST->type==typestrptr)
										$2->type=typechar;
								}
								$$=createTree(0,nodetypePOINTER,$2->type,NULL,$2,NULL,NULL);
							}
		| 	'&'ID 				{
								tempST=LookUp($2->varname);
								
								if(tempST==NULL)
								{
									yyerror("undefined Variable");
									
									printf("%s\n",$2->varname );
									exit(1);
								}
								
								else 
								{
									$2->Gentry=tempST; 
									
									if(tempST->type==typeint || tempST->type==typeintptr)
										$2->type=typeint;
										
									else if(tempST->type==typechar || tempST->type==typestrptr)
										$2->type=typechar;
								}
								$$=createTree(0,nodetypeADDR,$2->type,NULL,$2,NULL,NULL);
							}
		;

Declarations	:	DECL DeclList ENDDECL		{ printsymbolTable(); }
		|	DECL ENDDECL			{}
		;

DeclList	:	DeclList Decl 			{}
		|	Decl				{}
		;

Decl		:	Type VarList ';'		{}
		;

Type		:	INTG 				{ type=typeint; }
		|	STR 			 	{ type=typechar; }
		;

VarList 	:	VarList ',' ID 			{ Install($3->varname,type,1,1); }
		|	VarList ',' MUL ID 		{ Install($4->varname,type,1,1); }
		|	ID 				{ Install($1->varname,type,1,1); }
		|	VarList ',' ID '[' NUM ']' 	{		
								if(type==typeint)
									Install($3->varname,typearrint,$5->val,1);
											
								else if(type==typechar)
									Install($3->varname,typestr,$5->val,1);	
							}
		|	VarList ',' ID '[' NUM ']' '[' NUM ']' 
							{		
								if(type==typeint)
									Install($3->varname,typearrint,$5->val,$8->val);
											
								else if(type==typechar)
									Install($3->varname,typestr,$5->val,$8->val);	
							}
		|	ID '[' NUM ']' '[' NUM ']'	{
								if(type==typeint)
									Install($1->varname,typearrint,$3->val,$6->val);
											
								else if(type==typechar)
									Install($1->varname,typestr,$3->val,$6->val);
							}
		|	ID '[' NUM ']'			{
								if(type==typeint)
									Install($1->varname,typearrint,$3->val,1);
									
								else if(type==typechar)
									Install($1->varname,typestr,$3->val,1);
							}
		|	MUL	ID 			{
								if(type==typeint)
									Install($2->varname,typeintptr,1,1);
								
								else if(type==typechar)
									Install($2->varname,typestrptr,1,1);
							}
		;

%%


void yyerror(char const *s)
{
	printf("yyerror %s at line %d\n",s,lcnt);
}

int main(void) 
{
	FILE *fp=fopen("1.input","r");
	
	lcnt=1;
	Ghead=NULL;
	varadrs=4096;

	if(fp)
		yyin=fp;
	else
		printf("Input file error\n");

	targetFile=fopen("1.intermediate.xsm","w");

	yyparse();
	return 0;
}
