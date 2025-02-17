#include "Ch_List.h"
#include <stdlib.h>
#include "status.h"
#include <stdio.h>

PtrToCh_ListHead0 MakeCh_ListHead0(void) {
	Ch_ListNode0 *q = (PtrToCh_ListNode0) malloc( sizeof(Ch_ListNode0));
	if(q != NULL) {
		q -> Next = NULL;
	} else {
		printf("Make Ch_List0 is error\n");
	}
	return q;
}

Length LengthCh_List0(PtrToCh_ListHead0 q) {
	int Count = 0;

	while( (q->Next) != NULL) {
		Count ++;
		q = q -> Next;
	}
	return Count;
}
status IsEmptyCh_List0(PtrToCh_ListHead0 q) {
	status re;

	(q -> Next == NULL)?(re = TRUE):(re = FALSE);
	return re;
}
PtrToCh_ListNode0 AccessCh_List0(PtrToCh_ListHead0 q,PositionToOne t) {
	PtrToCh_ListNode0 re;
	if(t >= 0 && t <= (LengthCh_List0(q))) {
		while(t > 0) { 
			q = q -> Next;
			t --;
		}
		re = q;
	} else {
		re = NULL;
		printf("Ch_List0 Access is ERROR\n");
	}
	return re;
}
status InsertCh_List0(PtrToCh_ListHead0 p,PtrToEl_Ty_Ch_L0 a,PositionToOne n) {
	int Len = LengthCh_List0(p);
	status re;
	Ch_ListNode0 *q = (Ch_ListNode0*)malloc(sizeof(Ch_ListNode0));

	if(n > 0 && n <= (Len + 1)) {
		if(q != NULL) {
			p = AccessCh_List0(p,n-1);
			q -> Data = *a;
			q -> Next = p -> Next;
			p -> Next = q;
			re = TRUE;
		} else {
			printf("Ch_list0 Insert is error\n");
			re = FALSE;
		}
	} else {
		printf("Ch_list Insert0t is error\n");
		re = FALSE;
	}
	return re;
}
status DeletCh_List0(PtrToCh_ListHead0 p,PositionToOne i) {
	Length Len = LengthCh_List0(p);
	status re;

	if(i >= 1 && i <= Len) {
		PtrToCh_ListNode0 q;
		p = AccessCh_List0(p,i-1);
		q = p -> Next;
		p -> Next = q -> Next;
		free(q);	
		re = TRUE;
	} else {
		printf("Ch_list0 Delete is error\n");
		re = FALSE;
	}
	return re;
}
void StatusCh_List0(PtrToCh_ListHead0 q,SerialNumber n) {
	printf("The status of Ch_List0 %d\n",n);

	printf("\tLength of Ch_List0 %d\n",LengthCh_List0(q));
	(IsEmptyCh_List0(q) == TRUE)?(printf("\tCh_List0 is Empty\n")):(printf("\tCh_List0 is not empty\n"));
}
