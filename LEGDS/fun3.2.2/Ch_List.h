#include "status.h"

/**********************************Line Btween**********************************/
//Data Declaration
//typedef struct {
//
//}
typedef int ElementTypeCh_L0;

/**********************************Line Btween**********************************/
//Type Declaration
typedef struct Ch_ListNode0 {
	ElementTypeCh_L0 Data;
	struct Ch_ListNode0 *Next;
}Ch_ListNode0;

/**********************************Line Btween**********************************/
//General Declaration
typedef Ch_ListNode0* PtrToCh_ListNode0;
typedef Ch_ListNode0* PtrToCh_ListHead0;
typedef int Length;
typedef int Node0Number;
typedef int SerialNumber;
typedef int PositionToOne;
typedef ElementTypeCh_L0* PtrToEl_Ty_Ch_L0; 

/**********************************Line Btween**********************************/
//funcation derication
PtrToCh_ListHead0 MakeCh_ListHead0(void);

Length LengthCh_List0(PtrToCh_ListHead0 q);

status IsEmptyCh_List0(PtrToCh_ListHead0 q);

void StatusCh_List0(PtrToCh_ListHead0 q,SerialNumber n);

PtrToCh_ListNode0 AccessCh_List0(PtrToCh_ListHead0 q,PositionToOne t);

status InsertCh_List0(PtrToCh_ListHead0 p,PtrToEl_Ty_Ch_L0 a,PositionToOne n);

status DeletCh_List0(PtrToCh_ListHead0 p,PositionToOne i);
