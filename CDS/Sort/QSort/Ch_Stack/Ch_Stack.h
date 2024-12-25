
//Data Declaration
typedef struct ElementCh_Stack0{
	int start;
	int Len;
}ElementTypeCh_Stack0;

//Type Declatation
typedef struct Ch_StackNode0{
	ElementTypeCh_Stack0 *Data;
	struct Ch_StackNode0 *Next;
}Ch_StackNode0;

typedef struct Ch_Stack0{
	Ch_StackNode0 Head;
	struct Ch_StackNode0 *Top;
}Ch_Stack0;

//General Declaration
typedef Ch_Stack0* PtrToCh_Stack0;
typedef ElementTypeCh_Stack0* PtrToEl_Ty_Ch_S0;
typedef Ch_StackNode0* PtrToCh_StackNode0;
