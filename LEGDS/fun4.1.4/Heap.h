#include <stdio.h>
#include <stdlib.h>

//Data Declaration
//typde struct (
//
//)
typedef int ElementTypeHeap;

//Type Declaration
typedef struct {
	ElementTypeHeap *Data;
	int Size;	//存放堆当前节点的个数
	int MaxSize;	//存放堆的最大容量	
}Heap;

//General Declaration
typedef Heap* PtrToHeap;
typedef char status;
#define LARGE 3
#define SMALL 2
//控制是大堆还是小堆
#define FLAG SMALL
#define TRUE 1
#define FALSE 0

//Funcation Declaration
PtrToHeap MakeHeap (int Size);
status IsEmptyHeap(PtrToHeap p);
status DeleteHeap(PtrToHeap p);
status IsFullHeap(PtrToHeap p);
status InsertHeap(PtrToHeap p,ElementTypeHeap Data);
void StatusHeap(PtrToHeap p,int n);
