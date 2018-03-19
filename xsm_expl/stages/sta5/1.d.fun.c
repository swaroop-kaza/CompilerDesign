struct tnode* createTree(int val, int nodetype,int type,char *c,struct tnode *l, struct tnode *r,struct tnode *p3)
{
	switch(nodetype)
	{
		case nodetypeNULL	:	break;

		case nodetypeLEAF	:	break;

		case nodetypeID		:	break;

		case nodetypeARRID	:	break;

		case nodetypePLUS	:	if((l->type!=typeint && l->type!=typeargint) || (r->type!=typeint && r->type!=typeargint))
						{
							yyerror("type mismatch 1");
							exit(1);
						}
						break;
			
		case nodetypeMUL	:	if((l->type!=typeint && l->type!=typeargint) || (r->type!=typeint && r->type!=typeargint))
						{
							yyerror("type mismatch 1");
							exit(1);
						}
						break;

		case nodetypeMINUS	:	if((l->type!=typeint && l->type!=typeargint) || (r->type!=typeint && r->type!=typeargint))
						{
							yyerror("type mismatch 1");
							exit(1);
						}
						break;
			
		case nodetypeDIV	:	if((l->type!=typeint && l->type!=typeargint) || (r->type!=typeint && r->type!=typeargint))
						{
							yyerror("type mismatch 1");
							exit(1);
						}
						break;

		case nodetypeREAD	:	if(l->nodetype!=nodetypeID)
						{
							yyerror("type mismatch expected variable");
							exit(1);
						}
						break;

		case nodetypeARRREAD	:	if(l->nodetype!=nodetypeID)
						{
							yyerror("type mismatch expected variable");
							exit(1);
						}
						break;

		case nodetypeWRITE	:	if(l->type!=typeint && l->type!=typechar)
						{
							yyerror("type mismatch 2");
							exit(1);
						}
						break;

		case nodetypeASGN	:	if(l->type!=r->type)
						{
							yyerror("type mismatch 3");
							exit(1);
						}
						break;

		case nodetypeARRASGN	:	if(l->type!=p3->type || r->type!=typeint)
						{
							yyerror("type mismatch 4");
							exit(1);
						}
						break;

		case nodetypePASGN	:	if(l->type!=r->type)
						{
							yyerror("type mismatch 5");
							exit(1);
						}
						break;

		case nodetypeLT		:	if(l->type!=r->type || l->type!=typeint)
						{
							yyerror("type mismatch expected integers values");
							exit(1);
						}
						break;

		case nodetypeLE		:	if(l->type!=r->type || l->type!=typeint)
						{
							yyerror("type mismatch expected integers values");
							exit(1);
						}
						break;

		case nodetypeGT		:	if(l->type!=r->type || l->type!=typeint)
						{
							yyerror("type mismatch expected integers values");
							exit(1);
						}
						break;

		case nodetypeGE		:	if(l->type!=r->type || l->type!=typeint)
						{
							yyerror("type mismatch expected integers values");
							exit(1);
						}
						break;

		case nodetypeEQ		:	if(l->type!=r->type || l->type!=typeint)
						{
							yyerror("type mismatch expected integers values");
							exit(1);
						}
						break;

		case nodetypeNE		:	if(l->type!=r->type || l->type!=typeint)
						{
							yyerror("type mismatch expected integers values");
							exit(1);
						}
						break;

		case nodetypeIF		:	if(l->type!=typebool)
						{
							yyerror("type mismatch expected boolean");
							exit(1);
						}
						break;
			
		case nodetypeWHILE	:	if(l->type!=typebool)
						{
							yyerror("type mismatch expected boolean");
							exit(1);
						}
						break;
			
		case nodetypeDOWHILE	:	if(l->type!=typebool)
						{
							yyerror("type mismatch expected boolean");
							exit(1);
						}
						break;
			
		case nodetypeREPEAT	:	if(l->type!=typebool)
						{
							yyerror("type mismatch expected boolean");
							exit(1);
						}
						break;
		case nodetypeBRK	:	break;

		case nodetypeCNTU	:	break;

		case nodetypePOINTER	:	break;

		case nodetypeADDR	:	break;
	}

	struct tnode *temp=(struct tnode *)malloc(sizeof(struct tnode));

	temp->val=val;
	temp->type=type;
	temp->nodetype=nodetype;

	if(c!=NULL)
	{
		if(type==typechar)
		{
			temp->str=(char *)malloc(sizeof(c));
			strcpy(temp->str,c);	
		}

		else
		{
			temp->varname=(char *)malloc(sizeof(c));
			strcpy(temp->varname,c);
		}
	}

	else
		temp->varname=NULL;

	temp->Gentry=NULL;
	temp->Lentry=NULL;
	temp->left=l;
	temp->right=r;
	temp->end=p3;

	return temp;
}

int abstEvaluate(struct tnode *t)
{
	switch(t->nodetype)
	{
		case nodetypeNULL	:	abstEvaluate(t->left);
						abstEvaluate(t->right);
						
						return 1;
						break;

		case nodetypePLUS	:	return abstEvaluate(t->left)+abstEvaluate(t->right);
						break;

		case nodetypeMUL	:	return abstEvaluate(t->left)*abstEvaluate(t->right);
						break;

		case nodetypeMINUS	:	return abstEvaluate(t->left)-abstEvaluate(t->right);
						break;

		case nodetypeDIV	:	return abstEvaluate(t->left)/abstEvaluate(t->right);
						break;

		case nodetypeLEAF	:	return t->val;
						break;

		case nodetypeID		:	if(val[*(t->varname)-'a']!=NULL)
							return *val[*(t->varname)-'a'];
			
						else
						{
							printf("error\n");
							exit(1);
						}
						break;

		case nodetypeREAD	:	if(val[*(t->left->varname)-'a']==NULL)
							val[*(t->left->varname)-'a']=malloc(sizeof(int*));
		
						scanf("%d",val[*(t->left->varname)-'a']);
			
						return 1;
						break;

		case nodetypeWRITE	:	printf("%d\n",abstEvaluate(t->left));
						break;

		case nodetypeASGN	:	if(val[*(t->left->varname)-'a']==NULL)
							val[*(t->left->varname)-'a']=malloc(sizeof(int*));
			
						*val[*(t->left->varname)-'a']=abstEvaluate(t->right);
			
						return 1;
						break;

		case nodetypeLT		:	return abstEvaluate(t->left)<abstEvaluate(t->right);
						break;

		case nodetypeLE		:	return abstEvaluate(t->left)<=abstEvaluate(t->right);
						break;

		case nodetypeGT		:	return abstEvaluate(t->left)>abstEvaluate(t->right);
						break;

		case nodetypeGE		:	return abstEvaluate(t->left)>=abstEvaluate(t->right);
						break;

		case nodetypeEQ		:	return abstEvaluate(t->left)==abstEvaluate(t->right);
						break;

		case nodetypeNE		:	return abstEvaluate(t->left)!=abstEvaluate(t->right);
						break;		

		case nodetypeIF		:	if(abstEvaluate(t->left))
							abstEvaluate(t->right);
			
						else if(t->end!=NULL)
							abstEvaluate(t->end);
			
						break;

		case nodetypeWHILE	:	while(abstEvaluate(t->left))
							abstEvaluate(t->right);
			
						break;
	}
}	
