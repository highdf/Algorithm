#include "status.h"

//Data Declaration
typedef char ElementTypeCh_L1;

//Type Declaration
typedef struct Ch_ListNode1 {
	ElementTypeCh_L1 Data;
	struct Ch_ListNode1 *Next;
}Ch_ListNode1;

//General Declaration
typedef Ch_ListNode1* PtrToCh_ListNode1;
typedef Ch_ListNode1* PtrToCh_ListHead1;
typedef int Length;
typedef int Node1Number;
typedef int SerialNumber;
typedef int PositionToOne;
typedef ElementTypeCh_L1* PtrToEl_Ty_Ch_L1; 

//funcation derication
PtrToCh_ListHead1 MakeCh_ListHead1(void);

Length LengthCh_List1(PtrToCh_ListHead1 q);

status IsEmptyCh_List1(PtrToCh_ListHead1 q);

void StatusCh_List1(PtrToCh_ListHead1 q,SerialNumber n);

PtrToCh_ListNode1 AccessCh_List1(PtrToCh_ListHead1 q,PositionToOne t);

PtrToCh_ListHead1 InsertCh_List1(PtrToCh_ListHead1 p,PtrToEl_Ty_Ch_L1 a);

status DeletCh_List1(PtrToCh_ListHead1 p,PositionToOne i);
