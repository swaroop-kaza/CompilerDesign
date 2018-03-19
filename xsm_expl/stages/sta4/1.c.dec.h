#define typeint 	1
#define typebool 	2
#define typechar 	3
#define typenull 	4
#define typearrint 	5
#define typestr 	6	
#define typeintptr 	7
#define typestrptr 	8

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
#define nodetypeEQ 	21
#define nodetypeNE 	22
#define nodetypeARRID 	23
#define nodetypeARRASGN 24
#define nodetypeARRREAD 25
#define nodetypeBRK 	26
#define nodetypeCNTU 	27
#define nodetypeDOWHILE 28
#define nodetypeREPEAT 	29
#define nodetypePOINTER 30
#define nodetypeADDR 	31
#define nodetypePASGN 	32

int *val[26],lcnt;

typedef struct tnode 
{
	int type;
	int nodetype;
	int val;
	char *varname,*str;	
	struct tnode *left,*right,*end;
	struct Gsymbol *Gentry;
}tnode;

struct tnode* createTree(int val, int nodetype,int type, char *c,struct tnode *l, struct tnode *r,struct tnode *p3);

int abstEvaluate(struct tnode *t);
