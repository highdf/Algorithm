#include "Ch_Queue_in.h"
#include "Ch_Queue_out.h"

PtrToCh_Queue0 MakeCh_Queue0 (void) {
	Ch_Queue0 *p = (Ch_Queue0*)malloc(sizeof(Ch_Queue0));

	if(p != NULL) {
		p -> Front = &(p -> Head);
		p -> Rear = p -> Front;
	} else {
		printf("Error:In the MakeCh_Queue0;Malloc is false\n");
	}
	return p;
}
status IsEmptyCh_Queue0 (PtrToCh_Queue0 p) {
	return ((p->Front) == (p->Rear))?(TRUE):(FALSE);
}
status AddCh_Queue0 (PtrToCh_Queue0 p,ElementTypeCh_Queue0* x) {
	Ch_QueueNode0 *q = (Ch_QueueNode0*) malloc(sizeof(Ch_QueueNode0))	;
	status re;

	if(q != NULL) {
		q -> Data = x;
		q -> Next = p -> Rear -> Next;
		p -> Rear -> Next = q;
		p -> Rear = q;
		re = TRUE;
	} else {
		printf("Error:In the AddCh_Queue0:Malloc is false\n");
		re = FALSE;
	}
	return re;
}
ElementTypeCh_Queue0* DeleteCh_Queue0 (PtrToCh_Queue0 p) {
	Ch_QueueNode0 *pt;
	ElementTypeCh_Queue0 *t;

	if(IsEmptyCh_Queue0(p) == FALSE) {
		pt = p -> Front -> Next;	
		t = pt -> Data;
		((p->Front->Next) == (p->Rear))?((p->Rear) = p->Front,1):(1);
		p -> Front -> Next = pt -> Next;
		free(pt);
	} else {
		printf("Error:In the DeleteCh_Queue0");
		printf("Ch_Queue0 is empty\n");
		t = NULL;
	}
	return t;
}
int LengthCh_Queue0 (PtrToCh_Queue0 p) {
	Ch_QueueNode0 *t = p -> Front;
	int Len = 0;

	while(t != (p->Rear)) {
		Len ++;
		t = t -> Next;
	}
	return Len;
}
void StatusCh_Queue0 (PtrToCh_Queue0 p,int x) {
	printf("Ch_Queue0 %d is Status \n",x);
	(IsEmptyCh_Queue0(p) == TRUE)?(printf("\tIs Empty\n")):(printf("\tis not Empty\n"));
	printf("\tits Length is %d\n",LengthCh_Queue0(p));
}
