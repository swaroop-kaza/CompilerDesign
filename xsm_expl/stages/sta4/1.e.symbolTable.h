typedef struct Gsymbol
{
	char *name;
	int type,size,binding,s2;
	struct Gsymbol *next;
}Gsymbol;


struct Gsymbol *Ghead,*tempST;
int varadrs;

struct Gsymbol *LookUp(char * name);
void Install(char *name, int type, int size,int s2);
