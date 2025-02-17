#include "status.h"

/**********************************Line Btween**********************************/
//Data Declaration
//typedef struct {
//
//}
typedef int  ElementTypeSe_Queue_Num;

/**********************************Line Btween**********************************/
//Type Declaration
typedef struct Queue{
	ElementTypeSe_Queue_Num *Data;
	int Front;
	int Count;
	int MaxSize;
}Se_Queue_Num;

/**********************************Line Btween**********************************/
//General Declaration
typedef Se_Queue_Num* PtrToSe_Queue_Num;
typedef int Length;
typedef ElementTypeSe_Queue_Num* PtrToEl_Ty_Se_Q_Num;
typedef int Serial_Number; 

/**********************************Line Btween**********************************/
//funcation Daclaration
PtrToSe_Queue_Num MakeSe_Queue_Num(Length n);

status IsEmptySe_Queue_Num(PtrToSe_Queue_Num p);

ElementTypeSe_Queue_Num DeleteSe_Queue_Num(PtrToSe_Queue_Num p);

status AddSe_Queue_Num(PtrToSe_Queue_Num p,PtrToEl_Ty_Se_Q_Num x);

status IsFullSe_Queue_Num(PtrToSe_Queue_Num p);

void StatusSe_Queue_Num(PtrToSe_Queue_Num q,Serial_Number n);

ElementTypeSe_Queue_Num Eject(PtrToSe_Queue_Num q);

status Pop(PtrToSe_Queue_Num q,PtrToEl_Ty_Se_Q_Num x);
