#include "Ch_Queue_in.h"
#include "Ch_Queue_out.h"

PtrToCh_Queue_Num MakeCh_Queue_Num (void) {
	Ch_Queue_Num *p = (Ch_Queue_Num*)malloc(sizeof(Ch_Queue_Num));

	if(p != NULL) {
		p -> Front = &(p -> Head);
		p -> Rear = p -> Front;
	} else {
		printf("Error:In the MakeCh_Queue_Num;Malloc is false\n");
	}
	return p;
}
status IsEmptyCh_Queue_Num (PtrToCh_Queue_Num p) {
	return ((p->Front) == (p->Rear))?(TRUE):(FALSE);
}
status AddCh_Queue_Num (PtrToCh_Queue_Num p,ElementTypeCh_Queue_Num* x) {
	Ch_QueueNode_Num *q = (Ch_QueueNode_Num*) malloc(sizeof(Ch_QueueNode_Num))	;
	status re;

	if(q != NULL) {
		q -> Data = x;
		q -> Next = p -> Rear -> Next;
		p -> Rear -> Next = q;
		p -> Rear = q;
		re = TRUE;
	} else {
		printf("Error:In the AddCh_Queue_Num:Malloc is false\n");
		re = FALSE;
	}
	return re;
}
ElementTypeCh_Queue_Num* DeleteCh_Queue_Num (PtrToCh_Queue_Num p) {
	Ch_QueueNode_Num *pt;
	ElementTypeCh_Queue_Num *t;

	if(IsEmptyCh_Queue_Num(p) == FALSE) {
		pt = p -> Front -> Next;	
		t = pt -> Data;
		((p->Front->Next) == (p->Rear))?((p->Rear) = p->Front,1):(1);
		p -> Front -> Next = pt -> Next;
		free(pt);
	} else {
		printf("Error:In the DeleteCh_Queue_Num");
		printf("Ch_Queue_Num is empty\n");
		t = NULL;
	}
	return t;
}
int LengthCh_Queue_Num (PtrToCh_Queue_Num p) {
	Ch_QueueNode_Num *t = p -> Front;
	int Len = 0;

	while(t != (p->Rear)) {
		Len ++;
		t = t -> Next;
	}
	return Len;
}
void StatusCh_Queue_Num (PtrToCh_Queue_Num p,int x) {
	printf("Ch_Queue_Num %d is Status \n",x);
	(IsEmptyCh_Queue_Num(p) == TRUE)?(printf("\tIs Empty\n")):(printf("\tis not Empty\n"));
	printf("\tits Length is %d\n",LengthCh_Queue_Num(p));
}
