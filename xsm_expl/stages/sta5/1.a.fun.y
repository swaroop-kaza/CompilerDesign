%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#define YYSTYPE tnode *

	#include "1.c.fun.h"
	#include "1.d.fun.c"

	#include "1.e.symbolTable.h"
	#include "1.f.symbolTable.c"

	#include "1.g.codegen.c"

	int yylex(void);
	void yyerror(char const *s);
	
	FILE *yyin,*targetFile;

	int reg,type,funcType,decl=1,size=0;

	char *tupleName;
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
%token MAIN RETURN TUPLE

%left PLUS MINUS
%left DIV MUL

%nonassoc LT LE GT GE EQ NE

%%

program 	: 	GDeclarations FDeclarations mainblk	
							{
								end(targetFile); 
								printf("%d",count);
							}
		| 	GDeclarations mainblk		{ end(targetFile); }
		| 	mainblk				{ end(targetFile); }
		;


Body 		:	START Slist END ';'		{ $$=$2; } 
	 	| 	START END	';'		{ $$=NULL; }
		;

Slist 		:	Slist Stmt			{ $$=createTree(0,nodetypeNULL,typenull,NULL,$1,$2,NULL); } 
	  	| 	Stmt				{ $$=$1; }
	  	;

Stmt 		:	InputStmt			{ $$=$1; } 
		|	OutputStmt			{ $$=$1; }
		|	AsgStmt			 	{ $$=$1; }
		|	IfStmt				{ $$=$1; }
		|	WhileStmt		 	{ $$=$1; }
		|	BREAK	';'			{ $$=createTree(0,nodetypeBRK,typenull,NULL,NULL,NULL,NULL); }
		|	CNTU	';'			{ $$=createTree(0,nodetypeCNTU,typenull,NULL,NULL,NULL,NULL); }
		|	RET 				{ $$=$1; }
		;

RET 		: 	RETURN expr ';'			{ $$=createTree(0,nodetypeRET,typenull,NULL,$2,NULL,NULL); }
		;

InputStmt	:	READ '(' ID ')' ';' 		{
								Ltemp=LLookUp($3->varname);
									
								if(Ltemp==NULL)
								{
									tempST=GLookUp($3->varname);
										
									if(tempST==NULL)
									{
										yyerror("undefined Variable");
										printf("%s\n",$3->varname );
										exit(1);
									}

									else 
										$3->Gentry=tempST;
								}
								
								else
									$3->Lentry=Ltemp;
									
								$$=createTree(0,nodetypeREAD,typenull,NULL,$3,NULL,NULL);
							}
		|	READ '(' ID '[' expr ']' ')' ';' 
							{
								Ltemp=LLookUp($3->varname);

								if(Ltemp==NULL)
								{
									tempST=GLookUp($3->varname);
	
									if(tempST==NULL)
									{
										yyerror("undefined Variable");
										printf("%s\n",$3->varname );
										exit(1);
									}

									else $3->Gentry=tempST;
								}
								
								else
									$3->Lentry=Ltemp;
				
								$$=createTree(0,nodetypeARRREAD,typenull,NULL,$3,$5,NULL);
							}
		|	READ '(' ID '[' expr ']' '[' expr ']' ')' ';' 
							{
								Ltemp=LLookUp($3->varname);
			
								if(Ltemp==NULL)
								{
									tempST=GLookUp($3->varname);
				
									if(tempST==NULL)
									{
										yyerror("undefined Variable");
										printf("%s\n",$3->varname );
										exit(1);
									}

									else $3->Gentry=tempST;
								}
					
								else
									$3->Lentry=Ltemp;
				
								struct tnode *temp=createTree(tempST->s2,nodetypeLEAF,typeint,NULL,NULL, NULL,NULL);
								$5=createTree(0,nodetypeMUL,typeint,NULL,$5,temp,NULL);
								$5=createTree(0,nodetypePLUS,typeint,NULL,$5,$8,NULL);
								$$=createTree(0,nodetypeARRREAD,typenull,NULL,$3,$5,NULL);
							}
		;

OutputStmt	:	WRITE '(' expr ')' ';'		{ $$=createTree(0,nodetypeWRITE,typenull,NULL,$3,NULL,NULL); } 
		;

AsgStmt		:	ID '=' expr ';'			{
								Ltemp=LLookUp($1->varname);
							
								if(Ltemp==NULL)
								{
									tempST=GLookUp($1->varname);
	
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
											
										else if(tempST->type==typechar || tempST->type==typestrptr)
											$1->type=typechar;
									}
								}
								
								else
								{
									$1->Lentry=Ltemp;

									if(Ltemp->type==typeint || Ltemp->type==typeintptr || Ltemp->type==typeargint || Ltemp->type==typeargintref)
										$1->type=typeint;
										
									else if(Ltemp->type==typechar || Ltemp->type==typestrptr || Ltemp->type==typeargchar || Ltemp->type==typeargcharref)
										$1->type=typechar;
								}
								
								$$=createTree(0,nodetypeASGN,typenull,NULL,$1,$3,NULL);
							}
		|	ID '[' expr ']' '=' expr ';'	{
								tempST=GLookUp($1->varname);
								
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
								tempST=GLookUp($1->varname);
						
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
								Ltemp=LLookUp($2->varname);
								if(Ltemp==NULL)
								{
									tempST=GLookUp($2->varname);
								
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
								}
								
								else
								{
									$2->Lentry=Ltemp;
	
									if(Ltemp->type==typeintptr || Ltemp->type==typeargintref)
										$2->type=typeint;
										
									else if(Ltemp->type==typestrptr || Ltemp->type==typeargcharref)
										$2->type=typechar;
								}
				
								$$=createTree(0,nodetypePASGN,typenull,NULL,$2,$4,NULL);
							}	
			| ID '.' ID '=' expr ';'	{
								tempST=GLookUp($1->varname);
						
								if(tempST==NULL)
								{
									yyerror("undefined Variable");
									printf("%s\n",$1->varname );
									exit(1);
								}
								
								else 
								{	
									$1->Gentry=tempST;
									Ptemp=$1->Gentry->paramList;
									
									int j=0;

									while(Ptemp!=NULL)
									{
										if(strcmp(Ptemp->name,$3->varname)==0)
											break;
										j++;
										Ptemp=Ptemp->next;
									}
							
									if(Ptemp==NULL)
									{
										yyerror("Invalid reference");
										exit(1);
									}
									
									if(Ptemp->type==typeint)
										$1->type=typeint;
									
									else if(Ptemp->type==typechar)
										$1->type=typechar;
								}	
							
								$$=createTree(0,nodetypeTASGN,typenull,NULL,$1,$3,$5);
							}
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
		| 	ID 				{
								Ltemp=LLookUp($1->varname);
							
								if(Ltemp==NULL)
								{
									tempST=GLookUp($1->varname);
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
								}

								else
								{
									$1->Lentry=Ltemp;
						
									if(Ltemp->type==typeargint || Ltemp->type==typeargintref)
										$1->type=typeint;

									else if(Ltemp->type==typeargchar || Ltemp->type==typeargcharref)
										$1->type=typechar;

									else
										$1->type=Ltemp->type;	
								}
								
								$$ = $1;
							}
		| 	ID '[' expr ']'			{
								tempST=GLookUp($1->varname);

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
								tempST=GLookUp($1->varname);

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
								
								$$ = createTree(0,nodetypeARRID,$1->type,NULL,$1,$3,$6);
							}
		| 	MUL ID				{
								Ltemp=LLookUp($2->varname);
							
								if(Ltemp==NULL)
								{
									tempST=GLookUp($2->varname);
				
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
								}

								else
								{
									$2->Lentry=Ltemp; 
								
									if(Ltemp->type==typeintptr || Ltemp->type==typeargintref)
										$2->type=typeint;

									else if(Ltemp->type==typestrptr || Ltemp->type==typeargcharref)
										$2->type=typechar;
								}
								$$ = createTree(0,nodetypePOINTER,$2->type,NULL,$2,NULL,NULL);
							}
		| 	'&'	ID 			{
								Ltemp=LLookUp($2->varname);
					
								if(Ltemp==NULL)
								{
									tempST=GLookUp($2->varname);
							
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
								}

								else
								{
									$2->Lentry=Ltemp;
 
									if(Ltemp->type==typeint || Ltemp->type==typeintptr || Ltemp->type==typeargint || Ltemp->type==typeargintref)
										$2->type=typeint;

									else if(Ltemp->type==typechar || Ltemp->type==typestrptr || Ltemp->type==typeargchar || Ltemp->type==typeargcharref)
										$2->type=typechar;	
								}
								$$ = createTree(0,nodetypeADDR,$2->type,NULL,$2,NULL,NULL);
							}
		| 	ID '(' ')'			{		
								tempST=GLookUp($1->varname);
				
								if(tempST==NULL)
								{
									yyerror("undefined function");
									exit(1);
								}

								$1->Gentry=tempST;

								if(tempST->type==typefunctionint)
									$1->type=typeint;

								else if(tempST->type==typefunctionchar)
									$1->type=typechar;

								$$=createTree(0,nodetypefuncall,$1->type,$1->varname,$1,NULL,NULL);
							}
		| 	ID '(' ArgList ')'		{
								tempST=GLookUp($1->varname);

								if(tempST==NULL)
								{
									yyerror("undefined function");
									exit(1);
								}

								$1->Gentry=tempST;

								if(tempST->type==typefunctionint)
									$1->type=typeint;

								else if(tempST->type==typefunctionchar)
									$1->type=typechar;

								else
								{
									yyerror("Variable is not a function");
									exit(1);
								}

								$$=createTree(0,nodetypefuncall,$1->type,$1->varname,$1,$3,NULL);
							}
		|	ID '.' ID 			{
								tempST=GLookUp($1->varname);

								if(tempST==NULL)
								{
									yyerror("undefined function");
									exit(1);
								}

								$1->Gentry=tempST;
								Ptemp=$1->Gentry->paramList;
							
								while(Ptemp!=NULL)
								{
									if(strcmp(Ptemp->name,$3->varname)==0)
										break;

									Ptemp=Ptemp->next;
								}

								if(Ptemp==NULL)
								{
									yyerror("Invalid reference");
									exit(1);
								}

								if(Ptemp->type==typeint)
									$1->type=typeint;

								else if(Ptemp->type==typechar)
									$1->type=typechar;

								$$=createTree(0,nodetypetuple,$1->type,NULL,$1,$3,NULL);
							}
		;

ArgList		: 	ArgList ',' expr		{ $$=createTree(0,nodetypeARG,typenull,NULL,$1,$3,NULL); }
		| 	expr				{ $$=createTree(0,nodetypeARG,typenull,NULL,NULL,$1,NULL); }
		;

Type		:	INTG 				{ type=typeint; }
		|	STR 				{ type=typechar; }
		|	TUPLE ID '(' {funcType=type;} ParamList ')' 
							{ 
								Ptemp=Phead;
								Phead=NULL;
								type=typetuple; 
							}
		;

GDeclarations  	: 	DECL GDeclList ENDDECL 		{ 
								printf("Global Symbol Table\n");
								printsymbolTable();

								decl=0;

								generate(targetFile);
								printf("GDeclarations ok\n");
							}
		| 	DECL ENDDECL			{ decl=0; }
		;

GDeclList 	: 	GDeclList GDecl 		{}
		| 	GDecl 				{}
		; 

GDecl 		: 	Type GidList ';'		{}
	  	; 

GidList 	: 	GidList ',' Gid  		{}
		| 	Gid 				{}
		;

Gid 		:	ID 				{
								if(type==typetuple)
									GInstall($1->varname,type,size,1,Ptemp);
							
								else
									GInstall($1->varname,type,1,1,NULL);
							}
		|	ID '[' NUM ']'			{
								if(type==typeint)
									GInstall($1->varname,typearrint,$3->val,1,NULL);
		
								else if(type==typechar)
									GInstall($1->varname,typestr,$3->val,1,NULL);
							}
		|	ID '[' NUM ']' '[' NUM ']'	{
								if(type==typeint)
									GInstall($1->varname,typearrint,$3->val,$6->val,NULL);
							
								else if(type==typechar)
									GInstall($1->varname,typestr,$3->val,$6->val,NULL);
							}
		|	MUL	ID 			{
								if(type==typeint)
									GInstall($2->varname,typeintptr,1,1,NULL);

								else if(type==typechar)
									GInstall($2->varname,typestrptr,1,1,NULL);
							}
		|	ID '(' {funcType=type;} ParamList ')' 
							{
								if(funcType==typeint)
								{
									GInstall($1->varname,typefunctionint,0,1,Phead);
									printf("installed fun\n");
								}

								else if(funcType==typechar)
								{
									GInstall($1->varname,typefunctionchar,0,1,Phead);
									printf("installed fun\n");
								}

								else if(funcType==typetuple)
								{
									Ptemp=Phead;
									type=typetuple;
								}
								Phead=NULL;
							}
		;

FDeclarations	: 	FDeclarations Fdef 		{} 
		| 	Fdef				{}
		; 

Fdef 		:	Type ID '('{funcType=type;}  ParamList ')' '{' LDeclarations Body '}' 
							{
								validateParams(funcType,$2->varname,Phead);
								$2->Lentry=Lhead;

								tempST=GLookUp($2->varname);

								$2->Gentry=tempST;
								codegenFunc($2,$9,targetFile);
				
								Ltemp=Lhead;

								while(Ltemp!=NULL)
								{
									Lhead=Ltemp;
									Ltemp=Ltemp->next;

									free(Lhead->name);
									free(Lhead);
								}
								
								Lhead=NULL;
								lvaradrs=1;
								padrs=-3;
								Phead=NULL;
								printf("FDefinition %d ok\n",tempST->flabel);
							}
	 	;

ParamList	: 	ParamList ',' Param 		{}
		| 	Param 		                { size=1; }
		;

Param 		:	Type ID 			{
								if(type==typeint) 
									type=typeargint;

								else 
									type=typeargchar;

								PInstall($2->varname,type,passtypeval);

								if(decl==0)
									LInstall($2->varname,type);

								size++;
							}
		|	Type MUL ID 			{
								if(type==typeint) 
									type=typeargintref;
								
								else 
									type=typeargcharref;
		
								PInstall($3->varname,type,passtyperef);
				
								if(decl==0)
									LInstall($3->varname,type);

								size++;
							}
		;

mainblk		: 	INTG MAIN '(' ')' '{' LDeclarations Body'}'	
							{
								GInstall("main",typefunctionint,0,1,NULL);
								$$=createTree(0,nodetypeMAIN,typeint,NULL,$7,NULL,NULL);
			
								codegen($$,targetFile);
								printf("Main function ok\n");
							}
		;

LDeclarations	: 	DECL LDecList ENDDECL		{} 
		| 	DECL ENDDECL 			{}
		;

LDecList	: 	LDecList LDecl 			{} 
		| 	LDecl 				{}
		;

LDecl 		:	Type IdList	';'		{} 
		; 

IdList 		: 	IdList ',' ID 			{ LInstall($3->varname,type); } 
		| 	ID 				{ LInstall($1->varname,type); }
		; 
%%

void yyerror(char const *s)
{
	printf("yyerror %s at line %d\n",s,lcnt);
}

int main(void) 
{
	FILE *fp=fopen("input","r");

	lcnt=1;
	Ghead=NULL;
	Lhead=NULL;
	Phead=NULL;

	varadrs=4096;
	flabel=1;
	lvaradrs=1;
	padrs=-3;

	if(fp)
		yyin=fp;

	else
		printf("Input file error\n");

	targetFile=fopen("intermediate.xsm","w");
	yyparse();
	return 0;
}
