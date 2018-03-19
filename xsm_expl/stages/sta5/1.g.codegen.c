int count=-1,lcount=-1;

int getReg()
{
	if(count<19)
	{
		count++;
		return count;
	}
	else
		printf("Out of Registers\n");
}

void freeReg()
{
	if(count!=-1)
		count--;
	else
		printf("Freeing register error\n");
}

int getLabel()
{
	lcount++;
	return lcount;
}

void scan(int addrs,FILE *fp,int scantype)
{
	int i=getReg();

	fprintf(fp,"MOV R%d,7\n",i);
	fprintf(fp,"PUSH R%d\n",i);

	fprintf(fp,"MOV R%d,-1\n",i);
	fprintf(fp,"PUSH R%d\n",i);

	if(scantype==0)
		fprintf(fp,"MOV R%d,%d\n",i,addrs);

	else if(scantype==1)
		fprintf(fp,"MOV R%d,R%d\n",i,addrs);

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
	int i=getReg();

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

int Bstack[100],wh=0,p=-1,Cstack[100];

int codegen(struct tnode *t,FILE *fp)
{
	int i,j,k;

	if(t!=NULL)

	switch(t->nodetype)
	{
		case nodetypeNULL	:	codegen(t->left,fp);
						codegen(t->right,fp);
						break;

		case nodetypeLEAF	:	i=getReg();
		
						if(t->type==typechar)
							fprintf(fp, "MOV R%d,%s\n",i,t->str);
			
						else
							fprintf(fp, "MOV R%d,%d\n",i,t->val);
		
						return i;
						break;

		case nodetypeID		:	i=getReg();

						if(t->Lentry==NULL)
							fprintf(fp, "MOV R%d,[%d]\n",i,t->Gentry->binding);
		
						else
						{
							fprintf(fp, "MOV R%d,%d\n",i,t->Lentry->binding );

							j=getReg();
	
							fprintf(fp, "MOV R%d,BP\n",j );
							fprintf(fp, "ADD R%d,R%d\n",i,j);
	
							freeReg();

							fprintf(fp, "MOV R%d,[R%d]\n",i,i);
						}

						return i;
						break;

		case nodetypeARRID	:	i=getReg();
			
						fprintf(fp,"MOV R%d,%d\n",i,t->left->Gentry->binding );

						j=codegen(t->right,fp);

						if(t->end!=NULL)
						{
							k=codegen(t->end,fp);
				
							fprintf(fp,"MUL R%d,%d\n",j,t->left->Gentry->s2);
							fprintf(fp,"ADD R%d,R%d\n",j,k );
		
							freeReg();
						}

						fprintf(fp,"ADD R%d,R%d\n",i,j);
						fprintf(fp,"MOV R%d,[R%d]\n",i,i);
			
						freeReg();
			
						return i;
						break;

		case nodetypetuple	:	i=getReg();
	
						fprintf(fp, "MOV R%d,%d\n",i,t->left->Gentry->binding);
			
						Ptemp=t->left->Gentry->paramList;
			
						j=0;
	
						while(Ptemp!=NULL)
						{
							if(strcmp(Ptemp->name,t->right->varname)==0)
								break;
			
							j++;
							Ptemp=Ptemp->next;
						}
	
						fprintf(fp,"ADD R%d,%d\n",i,j);
						fprintf(fp,"MOV R%d,[R%d]\n",i,i);
	
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

		case nodetypeMOD	:	i=codegen(t->left,fp);
						j=codegen(t->right,fp);
		
						fprintf(fp, "MOD R%d R%d\n",i,j );
			
						freeReg();
	
						return i;
						break;

		case nodetypeREAD	:	if(t->left->Lentry==NULL)
							scan((t->left->Gentry)->binding,fp,0);
			
						else
						{
							i=getReg();
			
							fprintf(fp, "MOV R%d,%d\n",i,t->left->Lentry->binding);
			
							j=getReg();

							fprintf(fp, "MOV R%d,BP\n",j);
							fprintf(fp, "ADD R%d,R%d\n",i,j);
		
							freeReg();
			
							scan(i,fp,1);
				
							freeReg();
						}
			
						break;

		case nodetypeWRITE	:	i=codegen(t->left,fp);
			
						print(i,fp);
			
						freeReg();

						break;

		case nodetypeARRREAD	:	i=getReg();

						fprintf(fp,"MOV R%d,%d\n",i,t->left->Gentry->binding);
		
						j=codegen(t->right,fp);
		
						fprintf(fp,"ADD R%d,R%d\n",i,j);
			
						freeReg();
	
						scan(i,fp,1);
			
						freeReg();
			
						break;

		case nodetypeASGN	:	i=codegen(t->right,fp);
	
						if(t->left->Lentry==NULL)
							fprintf(fp,"MOV [%d],R%d\n",t->left->Gentry->binding,i );
		
						else
						{
							j=getReg();
	
							fprintf(fp, "MOV R%d,%d\n",j,t->left->Lentry->binding);

							k=getReg();

							fprintf(fp, "MOV R%d,BP\n",k);
							fprintf(fp, "ADD R%d,R%d\n",j,k);
				
							freeReg();
				
							fprintf(fp, "MOV [R%d],R%d\n",j,i);
				
							freeReg();
						}
		
						freeReg();
			
						break;

		case nodetypeARRASGN	:	i=getReg();

						fprintf(fp,"MOV R%d,%d\n",i,t->left->Gentry->binding );

						j=codegen(t->right,fp);

						fprintf(fp,"ADD R%d,R%d\n",i,j);
			
						freeReg();
		
						j=codegen(t->end,fp);
	
						fprintf(fp,"MOV [R%d],R%d\n",i,j);
			
						freeReg();
		
						break;

		case nodetypePASGN	:	i=codegen(t->right,fp);
						j=codegen(t->left,fp);

						fprintf(fp,"MOV [R%d],R%d\n",j,i);

						freeReg();

						break;
	
		case nodetypeTASGN	:	i=codegen(t->end,fp);
	
						j=getReg();
			
						fprintf(fp, "MOV R%d,%d\n",j,t->left->Gentry->binding);

						Ptemp=t->left->Gentry->paramList;
						k=0;
	
						while(Ptemp!=NULL)
						{
							if(strcmp(Ptemp->name,t->right->varname)==0)
								break;
						
							k++;
		
							Ptemp=Ptemp->next;
						}

						fprintf(fp,"ADD R%d,%d\n",j,k);
						fprintf(fp,"MOV [R%d],R%d\n",j,i);

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

		case nodetypePOINTER	:	i=getReg();
		
						j=codegen(t->left,fp);
	
						fprintf(fp,"MOV R%d,[R%d]\n",i,j);

						freeReg();
	
						return i;
						break;

		case nodetypeADDR	:	i=getReg();
		
						fprintf(fp,"MOV R%d,%d\n",i,t->left->Gentry->binding);
		
						return i; 
						break;

		case nodetypefuncall	:	i=0;

						int reg=count;
			
						while(i<=count)
							fprintf(fp, "PUSH R%d\n",i++);

						struct tnode *temp=t->right;
	
						while(temp!=NULL)
						{
							codegen(temp,fp);
							temp=temp->left;
						}
		
						i=getReg();

						fprintf(fp, "PUSH R%d\n",i);
			
						freeReg();
		
						fprintf(fp, "CALL F%d\n",t->left->Gentry->flabel);

						i=getReg();
				
						fprintf(fp, "POP R%d\n",i);
			
						j=getReg();
			
						temp=t->right;
						while(temp!=NULL)	
						{
							fprintf(fp,"POP R%d\n",j);
							temp=temp->left;
						}
				
						freeReg();

						while(reg>=0)
							fprintf(fp, "POP R%d\n",reg--);
			
						return i;
						break;

		case nodetypeARG	:	i=codegen(t->right,fp);
				
						fprintf(fp, "PUSH R%d\n",i);
		
						freeReg();
						break;

		case nodetypeRET	:	i=codegen(t->left,fp);
						j=getReg();
						k=getReg();

						fprintf(fp, "MOV R%d,BP\n",j );
						fprintf(fp, "MOV R%d,2\n",k );
						fprintf(fp, "SUB R%d,R%d\n",j,k );

						freeReg();

						fprintf(fp, "MOV [R%d],R%d\n",j,i );

						freeReg();
						break;

		case nodetypeMAIN	:	fprintf(fp, "F0:\n" );
						fprintf(fp, "PUSH BP\n" );
						fprintf(fp, "MOV BP,SP\n" );
	
						i=getReg();
			
						Ltemp=Lhead;
	
						while(Ltemp!=NULL)
						{
							if(Ltemp->type!=typeargint && Ltemp->type!=typeargchar && Ltemp->type!=typeargintref && Ltemp->type!=typeargcharref)
								fprintf(fp, "PUSH R%d\n",i);
				
							Ltemp=Ltemp->next;
						}
			
						freeReg();

						codegen(t->left,fp);
					
						break;
	}
}

int generate(FILE *fp)
{
	fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
	fprintf(fp, "MOV SP,%d\n",varadrs);
	fprintf(fp, "MOV BP,SP\n" );
	fprintf(fp, "CALL F0\n" );
}

void codegenFunc(struct tnode *id,struct tnode *t,FILE *fp)
{
	count=-1;

	int i,j,k;

	fprintf(fp, "F%d:\n",id->Gentry->flabel);
	fprintf(fp, "PUSH BP\n" );
	fprintf(fp, "MOV BP,SP\n" );

	i=getReg();

	Ltemp=Lhead;
	while(Ltemp!=NULL)
	{
		if(Ltemp->type!=typeargint && Ltemp->type!=typeargchar && Ltemp->type!=typeargintref && Ltemp->type!=typeargcharref)
		{
			fprintf(fp, "PUSH R%d\n",i);
			printf("%s %d\n",Ltemp->name,Ltemp->binding);
		}
		Ltemp=Ltemp->next;
	}

	freeReg();

	codegen(t,fp);

	i=getReg();

	Ltemp=Lhead;

	while(Ltemp!=NULL)
	{
		if(Ltemp->type!=typeargint && Ltemp->type!=typeargchar && Ltemp->type!=typeargintref && Ltemp->type!=typeargcharref)
			fprintf(fp, "POP R%d\n",i);

		Ltemp=Ltemp->next;
	}

	freeReg();

	fprintf(fp, "POP BP\n" );
	fprintf(fp, "RET \n" );
}
