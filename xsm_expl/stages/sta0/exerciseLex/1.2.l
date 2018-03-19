%{
	#include<stdio.h>
	
	int integers=0;
	int decimals=0;
%}

int		[0-9]+

%%

{int}                   {
                                integers++;
                                printf("Found           :       %s\n",yytext);
                                printf("Length          :       %d\n",yyleng);
                        }

({int})(.)({int})	{
				decimals++;
				printf("Found		:	%s\n",yytext);
				printf("Length		:	%d\n",yyleng);
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
	printf("Integers		:	%d\nDecimals		:	%d\n",integers,decimals);
	return 1;
}
