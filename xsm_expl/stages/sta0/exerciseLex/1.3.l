%{
	
	#include<stdio.h>
	
%}

apl	[a-zA-Z]

%%

[A]{apl}{apl}		{
				printf("Found		:	%s\n",yytext);
				printf("Length		:	%d\n",yyleng);
			}

(.)*			{
				printf("NOT FOUND\n");
			}

%%

int yywrap()
{
	return 1;
}

int main()
{
	yylex();
	return 1;
}
