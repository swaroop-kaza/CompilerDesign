%{
	#include<stdio.h>
	#include<stdlib.h>	

	int level=0;
	int pos=0;

%}

%token		DIGIT CHARTERS i f t h e n l s n d 
%nonassoc	'<' '>' '>=' '<=' '==' '!='

%%

start		:		statement						{
												printf("\nComplete\n");
												exit(1);
											}
		;

statement	:		I F '('lexpr')'THEN'\n'stat'\n'ELSEstat'\n'ENDIF';''\n'		{}
		;

lexpr		:		lexpr'>'lexpr		{printOperator(">");}
		|		lexpr'<'lexpr		{printOperator("<");}
		|		lexpr'<='lexpr		{printOperator("<=");}
		|		lexpr'>='lexpr		{printOperator(">=");}
		|		lexpr'=='lexpr		{printOperator("==");}
		|		lexpr'!='lexpr		{printOperator("!=");}
		|		DIGIT			{printf("%d ",$1);}
		;
		
stat		:		statement						{}
		|		CHARACTERS						{}
		;

%%

yylex()
{
	char c;
	c=getchar();
	
	if(isdigit(c))
	{
		yylval=c-'0';
		return DIGIT;
	}
	
	else if(c=='i' || c=='f' || c=='e' || c=='n' || c=='d' || c=='t' || c=='h' || c=='l' || c=='')
		return ;

	else if(c=='i')
                return I;

	else if(c=='i')
                return I;
	
	
	else if(c==' ')
	{
		yylex();
	}
	
	else
	
		

int main()
{
	yyparse();
	return 1;
}
