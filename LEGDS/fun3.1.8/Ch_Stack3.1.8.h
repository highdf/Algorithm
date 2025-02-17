#include "status.h"

//Data Declaration
typedef struct T0{
	char w;
	char n;
}T0;
typedef T0 ElementTypeCh_Stack1;

//Type Declatation
typedef struct Ch_StackNode1* PtrToCh_StackNode1;
typedef struct Ch_StackNode1{
	ElementTypeCh_Stack1 Data;
	PtrToCh_StackNode1 Next;
}Ch_StackNode1;

typedef struct Ch_Stack1{
	Ch_StackNode1 Head;
	PtrToCh_StackNode1 Top;
}Ch_Stack1;

//General Declaration
typedef Ch_Stack1* PtrToCh_Stack1;
typedef ElementTypeCh_Stack1* PtrToEl_Ty_Ch_S1;
typedef int Length;
typedef int SerialNumber;

//funcation
PtrToCh_Stack1 MakeCh_Stack1(void);

status IsEmptyCh_Stack1(PtrToCh_Stack1 p);

void PushCh_Stack1(PtrToCh_Stack1 p,PtrToEl_Ty_Ch_S1 n);

void StatusCh_Stack1(PtrToCh_Stack1 p,SerialNumber n);

Length LengthCh_Stack1(PtrToCh_Stack1 p);

status PopCh_Stack1(PtrToCh_Stack1 p);
