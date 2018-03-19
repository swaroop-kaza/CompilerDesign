struct tnode* createTree(int val, int type, char *c,struct tnode *l, struct tnode *r)
{
	struct tnode *temp=(struct tnode *)malloc(sizeof(struct tnode));

	temp->val=val;
	temp->nodetype=type;

	if(c!=NULL)
	{
		temp->varname=(char *)malloc(sizeof(c));
		strcpy(temp->varname,c);
	}

	else
		temp->varname=NULL;

	temp->left=l;
	temp->right=r;

	return temp;
}

int abstEvaluate(struct tnode *t)
{
	//printf("-----1\n");
	switch(t->nodetype)
	{
		case nodetypeNULL	:	abstEvaluate(t->left);
						abstEvaluate(t->right);
						return 1;
						break;

		case nodetypePLUS	:	return abstEvaluate(t->left)+ abstEvaluate(t->right);
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
						
						//scanf("%d",val[*(t->left->varname)-'a']);
						
						return 1;
						break;
	
		case nodetypeWRITE	:	printf("%d\n",abstEvaluate(t->left));
						break;
		
		case nodetypeASGN	:	if(val[*(t->left->varname)-'a']==NULL)
							val[*(t->left->varname)-'a']=malloc(sizeof(int*));
						
						*val[*(t->left->varname)-'a']=abstEvaluate(t->right);
			
						return 1;
						break;

	}
}
