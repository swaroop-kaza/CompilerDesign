%{
      	#include<stdio.h>
	#include<string.h>

	#define YYSTYPE char*
	#define concaat(a,b) concat(concat(a," "),concat(b," "))

      	yydebug=0;
      	char* concat(const char *s1, const char *s2);
%}

%token CHAR NEWLINE

%left '+' '-'
%left '*' '/'
 
%%

start	: 	expr NEWLINE  	{
					printf("---10\n");
					printf("\n%s",$1);
                        		printf("\nComplete\n");
                        
					exit(1);
                      		}
  	;

expr	:  	expr '+' expr  	{ printf("---9\n");$$ = concat("+ ",concaat($1,$3)); }
  	| 	expr '-' expr   { printf("---11\n");$$ = concat("- ",concaat($1,$3)); }
  	| 	expr '*' expr   { printf("---12\n");$$ = concat("* ",concaat($1,$3)); }
  	| 	expr '/' expr   { printf("---13\n");$$ = concat("/ ",concaat($1,$3)); }
  	| 	'(' expr ')'	{ printf("---14\n");$$=$2; }
  	| 	CHAR            { printf("---15\n");$$=$1; }
  	;

%%

char* concat(const char *s1, const char *s2)
{
	printf("---16\n");	

    	char result[strlen(s1)+strlen(s2)+1];

	printf("---17\n");

    	strcpy(result, s1);
    	strcat(result, s2);

    	return result;
}

void yyerror(char const *s)
{
    	printf("yyerror  %s\n",s);
}

int main()
{
	printf("---1\n");
  	yyparse();
  	return 1;
}
