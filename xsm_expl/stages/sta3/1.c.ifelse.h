#define typeint		1
#define typebool 	2
#define typenull 	3

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
#define nodetypeIF 	10
#define nodetypeTHEN 	11
#define nodetypeELSE 	12
#define nodetypeENDIF 	13
#define nodetypeWHILE 	14
#define nodetypeDO 	15
#define nodetypeENDWHILE 16
#define nodetypeLT 	17
#define nodetypeLE 	18
#define nodetypeGT 	19
#define nodetypeGE 	20
#define nodetypeEQ	21
#define nodetypeNE 	22
#define nodetypeBRK 	23
#define nodetypeCNTU 	24
#define nodetypeDOWHILE 25
#define nodetypeREPEAT 	26

int *val[26],lcnt;

typedef struct tnode 
{
	int type;
	int nodetype;
	int val;
	char *varname;	
	struct tnode *left,*right,*end;
}tnode;

struct tnode* createTree(int val, int nodetype,int type, char *c,struct tnode *l, struct tnode *r,struct tnode *p3);

int abstEvaluate(struct tnode *t);
