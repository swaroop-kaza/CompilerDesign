%{
	#include<stdio.h>
	#include<stdlib.h>

	#define YYSTYPE tnode*

	#include "1.c.exprtree.h"
	#include "1.d.exprtree.c"
	#include "1.e.codegen.c"

	int yylex(void);

	FILE *yyin,*targetFile;
	int reg;
%}

%token 		NUM PLUS MINUS MUL DIV END

%left		PLUS MINUS
%left		MUL DIV

%%

program		:		expr END		{
								$$ = $2;
								printf("Evalution value = %d\n",evalute($1));

								printf("Prefix\n"); 
								prefix($1);

								printf("\nPostfix\n"); 
								postfix($1);
								printf("\n");
				
								fprintf(targetFile, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
								
								reg=codegen($1,targetFile);
								print(reg,targetFile);
								fprintf(targetFile,"INT 10");

								exit(1);
							}
		;

expr		:		expr PLUS expr		{ $$=makeOperatorNode('+',$1,$3); }
		|		expr MINUS expr		{ $$=makeOperatorNode('-',$1,$3); }
		|		expr MUL expr		{ $$=makeOperatorNode('*',$1,$3); }
		|		expr DIV expr		{ $$=makeOperatorNode('/',$1,$3); }
		|		'(' expr ')'		{ $$=$2; }
		|		NUM			{ $$=$1; }
		;

%%

yyerror(char const *s)
{
	printf("ERROR %s\n",s);
}

int main()
{
	FILE *fp;
	fp=fopen("1.input","r");
	
	if(fp)
		yyin=fp;
	
	else
		printf("Input Error\n");

	targetFile=fopen("1.output.xsm","w");

	yyparse();
	return 1;
}
