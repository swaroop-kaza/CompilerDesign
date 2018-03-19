%{

	#include<stdio.h>
	#include<string.h>

	char *file1;

%}

number		[0-9]+

%%

{number}	{printf("number");}

%%

int yywrap()
{
	FILE * newFilePointer;
	char *file2="inputFile2.txt";
	
	newFilePointer = fopen(file2,"r");

	if(strcmp(file1,file2) != 0)
	{
		file1=file2;
		yyin = newFilePointer;
		return 0;
	}

	return 1;
}

int main()
{
	file1 = "inputFile1.txt";
	
	yyin = fopen(file1,"r");

	yylex();
		
	return 1;

}
