
//Data Declaration
typedef struct ElementCh_Stack_Num{
	int Value;
}ElementTypeCh_Stack_Num;

//Type Declatation
typedef struct Ch_StackNode_Num{
	ElementTypeCh_Stack_Num *Data;
	struct Ch_StackNode_Num *Next;
}Ch_StackNode_Num;

typedef struct Ch_Stack_Num{
	Ch_StackNode_Num Head;
	struct Ch_StackNode_Num *Top;
}Ch_Stack_Num;

//General Declaration
typedef Ch_Stack_Num* PtrToCh_Stack_Num;
typedef ElementTypeCh_Stack_Num* PtrToEl_Ty_Ch_S_Num;
typedef Ch_StackNode_Num* PtrToCh_StackNode_Num;
