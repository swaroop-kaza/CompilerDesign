int count=-1;

int getReg()
{
	if(count<19)
	{
		count++;
		return count;
	}
	
	else
		printf("Registers not available for assigning\n");
}

void freeReg()
{

	if(count != -1)
		count--;
	else
		printf("Registers not available for freeing\n");
}

int codegen(struct tnode *t,FILE *fp)
{
	int i,j;
	
	if(t->op == NULL)
	{
		i=getReg();
		fprintf(fp,"MOV R%d,%d\n",i,t->val);
		return i;
	}
	
	switch(*(t->op))
	{
		case	'+'	:	i=codegen(t->left,fp);
					j=codegen(t->right,fp);
					fprintf(fp,"ADD R%d,R%d\n",i,j);
					freeReg();
					return i;
					break;
	
		case 	'*'	:	i=codegen(t->left,fp);
					j=codegen(t->right,fp);
					fprintf(fp,"MUL R%d, R%d\n",i,j);
					freeReg();
					return i;
					break;

		case 	'-'	:	i=codegen(t->left,fp);
					j=codegen(t->right,fp);
					fprintf(fp,"SUB R%d, R%d\n",i,j);
					freeReg();
					return i;
					break;
	
		case 	'/'	:	i=codegen(t->left,fp);
					j=codegen(t->right,fp);
					fprintf(fp,"DIV R%d, R%d\n",i,j);
					freeReg();
					return i;
					break;
	}
}

void print(int reg,FILE *fp)
{
	int i;

	fprintf(fp,"MOV SP,4095\n");

	i=getReg();

	fprintf(fp,"MOV R%d,5\n",i);
	fprintf(fp,"PUSH R%d\n",i);

	fprintf(fp,"MOV R%d,-2\n",i);
	fprintf(fp,"PUSH R%d\n",i);

	fprintf(fp,"MOV R0,R%d\n",reg);
	fprintf(fp,"PUSH R0\n");

	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"PUSH R%d\n",i);

	fprintf(fp,"INT 7\n");

	fprintf(fp,"POP R0\n");
	fprintf(fp,"POP R0\n");
	fprintf(fp,"POP R0\n");
	fprintf(fp,"POP R0\n");
	fprintf(fp,"POP R0\n");
}
