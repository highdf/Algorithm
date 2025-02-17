
//Data Declaration
typedef struct Ch_QueueElement_Num{
      int Value;
}ElementTypeCh_Queue_Num;

//Type Declaration
typedef struct Ch_QueueNode {
	ElementTypeCh_Queue_Num *Data;
	struct Ch_QueueNode *Next;
}Ch_QueueNode_Num;

typedef struct Queue{
	Ch_QueueNode_Num Head;
	Ch_QueueNode_Num *Front;
	Ch_QueueNode_Num *Rear;
}Ch_Queue_Num;

//General Declaration
typedef Ch_Queue_Num* PtrToCh_Queue_Num;
typedef Ch_QueueNode_Num* PtrToCh_QueueNode_Num;
