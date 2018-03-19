%{
	#include<stdio.h>
	
	#define	ID 1;
	#define ER 2;
%}

low		[a-z]

high		[A-Z]

num		[0-9]

%%

({low}|{high})({low}|{high})*({num})		{
							printf("Found		:	%s\nLength		:	%d\n",yytext,yyleng);
							return ID;
						}

(.)*						{ return ER; }

%%

int yywrap()
{
	return 1;
}

int main()
{
	int num;

	num = yylex();

	if(num==1)
		printf("IDENTIFIER\n");
	else
		printf("ERROR\n");

	return 1;
}
