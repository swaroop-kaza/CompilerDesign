%{
	#include<stdio.h>
	
	int newLine=0;
	int charater=0;
	int word=0;
%}

word		[a-zA-Z]+

%%

[\n]		{ 
			newLine++;
			charater++;
		}

{word}		{
			word++;
			charater=charater+yyleng;
			printf("Found		:	%s\n",yytext);
			printf("Length		:	%lld\n",yyleng);
		}

(.)*		{	
			charater++;
		}

%%

int yywrap()
{
	return 1;
}

int main()
{
	FILE *newFilePointer;

	newFilePointer=fopen("inputFile","r");

	yyin=newFilePointer;

	yylex();
	printf("Lines		:	%d\nWords		:	%d\nCharaters	:	%d\n",newLine,word,charater);
	return 1;
}
