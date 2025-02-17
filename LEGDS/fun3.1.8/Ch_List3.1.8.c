#include "Ch_List3.1.8.h"
#include <stdlib.h>
#include "status.h"
#include <stdio.h>

PtrToCh_ListHead1 MakeCh_ListHead1(void) {
	Ch_ListNode1 *q = (PtrToCh_ListNode1) malloc( sizeof(Ch_ListNode1));
	q -> Next = NULL;
	return q;
}

Length LengthCh_List1(PtrToCh_ListHead1 q) {
	int Count = 0;

	while( (q->Next) != NULL) {
		Count ++;
		q = q -> Next;
	}
	return Count;
}
status IsEmptyCh_List1(PtrToCh_ListHead1 q) {
	status re;

	(q -> Next == NULL)?(re = TRUE):(re = FALSE);
	return re;
}
void StatusCh_List1(PtrToCh_ListHead1 q,SerialNumber n) {
	printf("The status of Ch_List1 %d\n",n);

	printf("Length of Ch_List1 %d\n",LengthCh_List1(q));
	(IsEmptyCh_List1(q) == TRUE)?(printf("Ch_List1 is Empty\n")):(printf("Ch_List1 is not empty\n"));
}
PtrToCh_ListNode1 AccessCh_List1(PtrToCh_ListHead1 q,PositionToOne t) {
	PtrToCh_ListNode1 re;
	if(t >= 0 && t <= (LengthCh_List1(q))) {
		while(t > 0) { 
			q = q -> Next;
			t --;
		}
		re = q;
	} else {
		re = NULL;
		printf("ERROR Access\n");
	}
	return re;
}
status DeletCh_List1(PtrToCh_ListHead1 p,PositionToOne i) {
	Length Len = LengthCh_List1(p);
	status re;

	if(i >= 1 && i <= Len) {
		PtrToCh_ListNode1 q;
		p = AccessCh_List1(p,i-1);
		q = p -> Next;
		p -> Next = q -> Next;
		free(q);	
		re = TRUE;
	} else {
		printf("ERROR Delet\n");
		re = FALSE;
	}
	return re;
}
PtrToCh_ListHead1 InsertCh_List1(PtrToCh_ListHead1 p,PtrToEl_Ty_Ch_L1 a) {
	Ch_ListNode1 *q = (Ch_ListNode1*)malloc(sizeof(Ch_ListNode1));
		q -> Data = *a;
		q -> Next = p -> Next;
		p -> Next = q;

	return q;
}
