#include "status.h"

//Data Declaration
typedef double  ElementTypeCh_Stack2;

//Type Declatation
typedef struct Ch_StackNode2* PtrToCh_StackNode2;
typedef struct Ch_StackNode2{
	ElementTypeCh_Stack2 Data;
	PtrToCh_StackNode2 Next;
}Ch_StackNode2;

typedef struct Ch_Stack2{
	Ch_StackNode2 Head;
	PtrToCh_StackNode2 Top;
}Ch_Stack2;

//General Declaration
typedef Ch_Stack2* PtrToCh_Stack2;
typedef ElementTypeCh_Stack2* PtrToEl_Ty_Ch_S2;
typedef int Length;
typedef int SerialNumber;

//funcation
PtrToCh_Stack2 MakeCh_Stack2(void);

status IsEmptyCh_Stack2(PtrToCh_Stack2 p);

void PushCh_Stack2(PtrToCh_Stack2 p,PtrToEl_Ty_Ch_S2 n);

void StatusCh_Stack2(PtrToCh_Stack2 p,SerialNumber n);

Length LengthCh_Stack2(PtrToCh_Stack2 p);

status PopCh_Stack2(PtrToCh_Stack2 p);
