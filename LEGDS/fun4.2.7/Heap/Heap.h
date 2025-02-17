
//Data Declaration
typedef struct ElementHeap{
	int Value;
}ElementTypeHeap;

//Type Declaration
typedef struct {
	ElementTypeHeap *Data;
	int Size;	//存放堆当前节点的个数
	int MaxSize;	//存放堆的最大容量	
}Heap;

//General Declaration
typedef Heap* PtrToHeap;
#define LARGE 3
#define SMALL 2
//控制是大堆还是小堆
#define FLAG LARGE

