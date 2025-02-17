#include <stdio.h>
#include <stdlib.h>
#include "Ch_Queue/BinTree.h"

//Type Declaration
typedef struct Type{
	ElementTypeBT *Data;
	int Num[2];
}Type0;

//funcation Daxlaration
int FindRoot(Type0 *p,int n);

BinTreeNode* CtBT(Type0 *p,int K);

void WriteData(Type0 *P,FILE *fp);
