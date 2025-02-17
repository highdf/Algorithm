
//Data Declaration
typedef struct Ch_QueueElement0{
      int Value;
}ElementTypeCh_Queue0;

//Type Declaration
typedef struct Ch_QueueNode {
	ElementTypeCh_Queue0 *Data;
	struct Ch_QueueNode *Next;
}Ch_QueueNode0;

typedef struct Queue{
	Ch_QueueNode0 Head;
	Ch_QueueNode0 *Front;
	Ch_QueueNode0 *Rear;
}Ch_Queue0;

//General Declaration
typedef Ch_Queue0* PtrToCh_Queue0;
typedef Ch_QueueNode0* PtrToCh_QueueNode0;
