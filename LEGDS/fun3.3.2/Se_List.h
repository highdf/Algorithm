#include "status.h"

/**********************************Line Btween**********************************/
//Data Declaration
//typedef struct {
//
//}
typedef int  ElementTypeSe_L0;

/**********************************Line Btween**********************************/
//Type Declaration
typedef int PositionToZero;
typedef int Length;
typedef struct Se_List0 {
		ElementTypeSe_L0 *Data;
		PositionToZero Last;
		Length MaxSize;
}Se_List0;

/**********************************Line Btween**********************************/
//General Declaration
typedef int PositionToOne;
typedef int Serial0ber;
typedef int Se_List_Size;
typedef ElementTypeSe_L0* El_Ty_Se_L0;
typedef Se_List0* PtrToSe_List0;

/**********************************Line Btween**********************************/
//funcation deracation
status IsEmptySe_List0(PtrToSe_List0 a);

status IsFullSe_List0(PtrToSe_List0 a);

status InsertSe_List0(PtrToSe_List0 a,El_Ty_Se_L0 x,PositionToOne t);

status DeleteSe_List0(PtrToSe_List0 a,PositionToOne t);

void StatusSe_List0(PtrToSe_List0 q,Serial0ber n);

PtrToSe_List0 MakeSe_List0(Se_List_Size n);
