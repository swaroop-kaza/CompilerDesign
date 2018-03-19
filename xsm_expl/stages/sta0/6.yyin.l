/*Declarations*/

 /*Rules*/
%%

%%

main(int c,char *s[])
{
	if(c>1)
	{
		FILE* fp;
		fp=fopen(s[1],"r");
		if(fp)
			yyin = fp;
	}
	yylex();
	return 1;
}
