#include "stdio.h"
#include "stdlib.h"

//Data Declaratoin
typedef struct {
	int Value;
}ElementTypeBT;
typedef ElementTypeBT* PtrElementTypeBT;

//Type Declaraton
typedef struct Node{
	PtrElementTypeBT Data;
	struct Node *Child[2];
}BinTreeNode;

//General Declaration
typedef BinTreeNode* PtrToBinTreeNode;
typedef char status;
#define TRUE 1
#define FALSE 0

//funcation Daxlaration
PtrToBinTreeNode CreatBT(FILE *fp);
