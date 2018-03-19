%{
	#include<stdio.h>
%}

%%

[/*](.)*[*/]		{
				printf("Found		:	%s\n",yytext);
				printf("Length		:	%d\n",yyleng);
			}

[//](.![\n])*		{
				printf("Found           :       %s\n",yytext);
				printf("Length          :       %d\n",yyleng);
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
