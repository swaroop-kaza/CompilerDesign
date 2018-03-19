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

void scan(int adrs,FILE *fp )
{
	int i;

	fprintf(fp,"MOV SP,4121\n");
	
	i=getReg();
	
	fprintf(fp,"MOV R%d,7\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	
	fprintf(fp,"MOV R%d,-1\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	
	fprintf(fp,"MOV R%d,%d\n",i,adrs);
	fprintf(fp,"PUSH R%d\n",i);
	
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	
	fprintf(fp,"INT 6\n");
	
	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",i);
	
	freeReg();
}	

void print(int reg,FILE *fp)
{
	int i;

	fprintf(fp,"MOV SP,4121\n");

	i=getReg();

	fprintf(fp,"MOV R%d,5\n",i);
	fprintf(fp,"PUSH R%d\n",i);

	fprintf(fp,"MOV R%d,-2\n",i);
	fprintf(fp,"PUSH R%d\n",i);

	fprintf(fp,"PUSH R%d\n",reg);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"PUSH R%d\n",i);

	fprintf(fp,"INT 7\n");

	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",i);

	freeReg();
}

void end(FILE *fp)
{
	fprintf(fp,"INT 10" );
}


int codegen(struct tnode *t,FILE *fp)
{
	int i,j;
	switch(t->nodetype)
	{
		case nodetypeNULL	:	codegen(t->left,fp);
						codegen(t->right,fp);
						break;

		case nodetypePLUS	:	i=codegen(t->left,fp);
						j=codegen(t->right,fp);
						
						fprintf(fp, "ADD R%d,R%d\n",i,j );
			
						freeReg();
			
						return i;
						break;

		case nodetypeMUL	:	i=codegen(t->left,fp);
						j=codegen(t->right,fp);
			
						fprintf(fp, "MUL R%d,R%d\n",i,j );
			
						freeReg();
			
						return i;
						break;

		case nodetypeMINUS	:	i=codegen(t->left,fp);
						j=codegen(t->right,fp);
			
						fprintf(fp, "SUB R%d,R%d\n",i,j );
					
						freeReg();
			
						return i;
						break;

		case nodetypeDIV	:	i=codegen(t->left,fp);
						j=codegen(t->right,fp);
			
						fprintf(fp, "DIV R%d,R%d\n",i,j );
			
						freeReg();
			
						return i;
						break;
	
		case nodetypeLEAF	:	i=getReg();
			
						fprintf(fp, "MOV R%d,%d\n",i,t->val);
			
						return i;
						break;
		
		case nodetypeID		:	i=getReg();
			
						fprintf(fp, "MOV R%d,[%d]\n",i,4096+*(t->varname)-'a');
			
						return i;
						break;
		
		case nodetypeREAD	:	scan(4096+*(t->left->varname)-'a',fp);
						break;
		
		case nodetypeWRITE	:	i=codegen(t->left,fp);
			
						print(i,fp);
			
						freeReg();
						break;
		
		case nodetypeASGN	:	i=codegen(t->right,fp);
			
						fprintf(fp,"MOV [%d],R%d\n",4096+*(t->left->varname)-'a',i );
			
						return i;
						break;
	}
}

void generate(struct tnode *t,FILE *fp)
{
	fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
	
	codegen(t,fp);
	
	end(fp);
}
