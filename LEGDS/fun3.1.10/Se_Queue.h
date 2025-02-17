#include "status.h"

/**********************************Line Btween**********************************/
//Data Declaration
//typedef struct {
//
//}
typedef int  ElementTypeSe_Queue1;

/**********************************Line Btween**********************************/
//Type Declaration
typedef struct Queue{
	ElementTypeSe_Queue1 *Data;
	int Front;
	int Count;
	int MaxSize;
}Se_Queue1;

/**********************************Line Btween**********************************/
//General Declaration
typedef Se_Queue1* PtrToSe_Queue1;
typedef int Length;
typedef ElementTypeSe_Queue1* PtrToEl_Ty_Se_Q1;
typedef int Serial1ber; 

/**********************************Line Btween**********************************/
//funcation Daclaration
PtrToSe_Queue1 MakeSe_Queue1(Length n);

status IsEmptySe_Queue1(PtrToSe_Queue1 p);

ElementTypeSe_Queue1 DeleteSe_Queue1(PtrToSe_Queue1 p);

status AddSe_Queue1(PtrToSe_Queue1 p,PtrToEl_Ty_Se_Q1 x);

status IsFullSe_Queue1(PtrToSe_Queue1 p);

void StatusSe_Queue1(PtrToSe_Queue1 q,Serial1ber n);
