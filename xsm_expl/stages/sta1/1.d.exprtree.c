struct tnode* makeLeafNode(int n)
{
	struct tnode* temp;
	
	temp=(struct tnode*)malloc(sizeof(struct tnode));
	
	temp->op=NULL;
	temp->val=n;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r)
{
	struct tnode* temp;

	temp=(struct tnode*)malloc(sizeof(struct tnode));

	temp->op=malloc(sizeof(char));
	
	*(temp->op)=c;
	temp->left=l;
	temp->right=r;

	return temp;
}

int evalute(struct tnode *t)
{
	if(t->op == NULL)
		return t->val;
	
	switch(*(t->op))
	{
		case '+'	:		return (evalute(t->left) + evalute(t->right));
						break;
		
		case '-'	:		return (evalute(t->left) - evalute(t->right));
						break;
		
		case '*'	:		return (evalute(t->left) *  evalute(t->right));
						break;

		case '/'	:		return (evalute(t->left) / evalute(t->right));
						break;
	}
}

void prefix(struct tnode *t)
{
	if(t==NULL)
		return;
	else
	{
		if(t->op==NULL)
			printf("%d ",t->val);
		else
			printf("%c ",*(t->op));
		prefix(t->left);
		prefix(t->right);
	}
}

void postfix(struct tnode *t)
{
	if(t==NULL)
		return ;
	else
	{
		postfix(t->left);
		postfix(t->right);
		if(t->op==NULL)
                        printf("%d ",t->val);
                else
                        printf("%c ",*(t->op));
	}
}	
