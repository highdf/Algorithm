#include "stdio.h"
#include "stdlib.h"

//Data Declaratoin
#define MaxSize 30
typedef struct {
	char Name[MaxSize+1];
	int Count;
}BSTNode;
typedef BSTNode ElementTypeBT;
typedef BSTNode* PtrElementTypeBT;

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

//Funcatoin Declaration
PtrToBinTreeNode InsertBST (PtrToBinTreeNode BT,ElementTypeBT *val);
PtrToBinTreeNode FindBST(PtrToBinTreeNode BT,char* Name);
