#define typeExpr 	1
#define typeComp 	2
#define typeStmt 	3

#define nodetypeLEAF 	0
#define nodetypeID 	1
#define nodetypePLUS 	2
#define nodetypeMUL 	3
#define nodetypeMINUS 	4
#define nodetypeDIV 	5
#define nodetypeASGN 	6
#define nodetypeREAD 	7
#define nodetypeWRITE 	8
#define nodetypeNULL 	9

int *val[26];

typedef struct tnode 
{ 
	int val;			// value of a number for NUM nodes.
	int type;			//type of variable
	char* varname;			//name of a variable for ID nodes  
	int nodetype;  			// information about non-leaf nodes - read/write/connector/+/* etc.  
	struct tnode *left,*right;	//left and right branches   
}tnode;

											/*Create a node tnode*/
struct tnode* createTree(int val, int type, char* c, struct tnode *l, struct tnode *r);
