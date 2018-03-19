%{
	#include<stdio.h>
	#include<stdio.h>
%}

number		[0-9]+

%%

{number}	{	
			printf("Found	:	%d\n",atoi(yytext));
			return atoi(yytext);
		}

%%

int yywrap()
{
	return 1;
}

int main()
{

	int num1,num2;
	
	printf("Enter an even number and an odd number\n");

	num1=yylex();
	num2=yylex();

	if((num1-num2)%2==1)
		printf("Enterd numbers are correct\n");
	
	else
		printf("Enterd numbers are in correct\n");

	return 1;
}
