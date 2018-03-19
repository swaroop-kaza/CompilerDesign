typedef struct tnode
{
	int val;			//value of the expression tree
	char *op;			//indicates the operator branch
	struct tnode *left,*right;	//left and right branches
}tnode;

struct tnode* makeLeafNode(int n);	//makes a tnode leaf operator and set value in feild

struct tnode* makeOperatorNode(char c,struct tnode* l,struct tnode* r);
					//makes a tnode with operator and left and right nodes

int evalute(struct tnode* t);		//evalutes the tree t
