int count=-1;
int lcount=-1;

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

int getLabel()
{
	lcount++;
	return lcount;
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

int Bstack[100];
int Cstack[100];
int wh=0;
int p=-1;

int codegen(struct tnode *t,FILE *fp)
{
	int i,j,k;
	switch(t->nodetype)
	{
		case nodetypeNULL	:	codegen(t->left,fp);
						codegen(t->right,fp);
						break;

		case nodetypeLEAF	:	i=getReg();

						fprintf(fp, "MOV R%d,%d\n",i,t->val);

						return i;
						break;

		case nodetypeID		:	i=getReg();
		
						fprintf(fp, "MOV R%d,[%d]\n",i,4096+*(t->varname)-'a');
					
						return i;
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
		
		case nodetypeREAD	:	scan(4096+*(t->left->varname)-'a',fp);
						break;

		case nodetypeWRITE	:	i=codegen(t->left,fp);
						
						print(i,fp);
			
						freeReg();
						
						break;

		case nodetypeASGN	:	i=codegen(t->right,fp);
			
						fprintf(fp,"MOV [%d],R%d\n",4096+*(t->left->varname)-'a',i );
				
						freeReg();
			
						break;

		case nodetypeLT		:	i=codegen(t->left,fp);
						j=codegen(t->right,fp);
			
						fprintf(fp,"LT R%d,R%d\n",i,j);
					
						freeReg();
			
						return i;
						break;

		case nodetypeLE		:	i=codegen(t->left,fp);
						j=codegen(t->right,fp);
		
						fprintf(fp,"LE R%d,R%d\n",i,j);

						freeReg();
			
						return i;
						break;
		
		case nodetypeGT		:	i=codegen(t->left,fp);
						j=codegen(t->right,fp);
		
						fprintf(fp,"GT R%d,R%d\n",i,j);

						freeReg();
			
						return i;
						break;

		case nodetypeGE		:	i=codegen(t->left,fp);
						j=codegen(t->right,fp);
	
						fprintf(fp,"GE R%d,R%d\n",i,j);
						
						freeReg();
					
						return i;
						break;

		case nodetypeEQ		:	i=codegen(t->left,fp);
						j=codegen(t->right,fp);
		
						fprintf(fp,"EQ R%d,R%d\n",i,j);
		
						freeReg();
	
						return i;
						break;
		
		case nodetypeNE		:	i=codegen(t->left,fp);
						j=codegen(t->right,fp);

						fprintf(fp,"NE R%d,R%d\n",i,j);
			
						freeReg();

						return i;
						break;

		case nodetypeIF		:	i=codegen(t->left,fp);
			
						j=getLabel();
			
						fprintf(fp,"JZ R%d,L%d\n",i,j);
		
						codegen(t->right,fp);
			
						if(t->end!=NULL)
						{
							k=getLabel();

							fprintf(fp,"JMP L%d\n",k);
							fprintf(fp,"L%d:\n",j);

							codegen(t->end,fp);

							fprintf(fp,"L%d:\n",k);
						}
					
						else
							fprintf(fp,"L%d:\n",j);
					
						freeReg();
						
						break;

		case nodetypeWHILE	:	wh++;
			
						i=getLabel();
						j=getLabel();
			
						Bstack[++p]=j;
						Cstack[p]=i;
			
						fprintf(fp,"L%d:\n",i);
			
						k=codegen(t->left,fp);
			
						fprintf(fp,"JZ R%d,L%d\n",k,j);
						freeReg();
						
						codegen(t->right,fp);

						fprintf(fp,"JMP L%d\n",i);
						fprintf(fp,"L%d:\n",j);

						wh--;
						p--;

						break;

		case nodetypeBRK	:	if(wh!=0&&p!=-1)
							fprintf(fp,"JMP L%d\n",Bstack[p]);
						break;

		case nodetypeCNTU	:	if(wh!=0&&p!=-1)
							fprintf(fp,"JMP L%d\n",Cstack[p]);
						break;

		case nodetypeDOWHILE	:	wh++;

						i=getLabel();
						j=getLabel();

						Bstack[++p]=j;
						Cstack[p]=i;

						fprintf(fp,"L%d:\n",i);

						codegen(t->right,fp);

						k=codegen(t->left,fp);

						fprintf(fp,"JZ R%d,L%d\n",k,j);

						freeReg();

						fprintf(fp,"JMP L%d\n",i);
						fprintf(fp,"L%d:\n",j);

						wh--;
						p--;

						break;

		case nodetypeREPEAT	:	wh++;
		
						i=getLabel();
						j=getLabel();

						Bstack[++p]=j;
						Cstack[p]=i;

						fprintf(fp,"L%d:\n",i);

						codegen(t->right,fp);
						k=codegen(t->left,fp);

						fprintf(fp,"JNZ R%d,L%d\n",k,j);

						freeReg();

						fprintf(fp,"JMP L%d\n",i);
						fprintf(fp,"L%d:\n",j);

						wh--;
						p--;

						break;
	}
}

int generate(struct tnode *t,FILE *fp)
{
	fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
	codegen(t,fp);
	end(fp);
}
