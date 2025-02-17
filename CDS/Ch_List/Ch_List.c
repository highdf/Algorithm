#include "Ch_List_in.h"
#include "Ch_List_out.h"

PtrToCh_ListHead_Num MakeCh_ListHead_Num(void) {
	Ch_ListNode_Num *q = (PtrToCh_ListNode_Num) malloc( sizeof(Ch_ListNode_Num));
	if(q != NULL) {
		q -> Data = NULL;
		q -> Next = NULL;
	} else {
		printf("Error:In the MakeCh_List_NUm: ");
		printf("Malloc is false\n");
	}
	return q;
}

int LengthCh_List_Num(PtrToCh_ListHead_Num q) {
	int Count = 0;

	while( (q->Next) != NULL) {
		Count ++;
		q = q -> Next;
	}
	return Count;
}
status IsEmptyCh_List_Num(PtrToCh_ListHead_Num q) {
	status re;

	(q -> Next == NULL)?(re = TRUE):(re = FALSE);
	return re;
}
PtrToCh_ListNode_Num AccessCh_List_Num(PtrToCh_ListHead_Num q,int t) {
	PtrToCh_ListNode_Num re;
	if(t >= 0 && t < (LengthCh_List_Num(q))) {
		while(t >= 0) { 
			q = q -> Next;
			t --;
		}
		re = q;
	} else {
		re = NULL;
		printf("Error:In the AccessCh_List_Num: ");
		printf("index is error\n");
	}
	return re;
}
status InsertCh_List_Num(PtrToCh_ListHead_Num p,ElementTypeCh_List_Num *a,int n) {
	int Len = LengthCh_List_Num(p);
	status re;
	Ch_ListNode_Num *q = (Ch_ListNode_Num*)malloc(sizeof(Ch_ListNode_Num));

	if(n >= 0 && n <= (Len)) {
		if(q != NULL) {
			p = (n != 0)?(AccessCh_List_Num(p,n-1)):(p);
			q -> Data = a;
			q -> Next = p -> Next;
			p -> Next = q;
			re = TRUE;
		} else {
			printf("Error:In the InsertCh_List_Num: ");
			printf("Malloc is false\n");
			re = FALSE;
		}
	} else {
		printf("Error:In the InsertCh_List_Num: ");
		printf("Index is error\n");
		re = FALSE;
	}
	return re;
}
ElementTypeCh_List_Num* DeleteCh_List_Num(PtrToCh_ListHead_Num p,int i) {
	Length Len = LengthCh_List_Num(p);
	ElementTypeCh_List_Num* re;

	if(i >= 0 && i < Len) {
		PtrToCh_ListNode_Num q;
		p = (i != 0)?(AccessCh_List_Num(p,i-1)):(p);
		q = p -> Next;
		re = q -> Data;
		p -> Next = q -> Next;
		free(q);	
	} else if((Len == 0)) {
		printf("Error:In the DeleteCh_List_Num: ");
		printf("The Ch_List_Num is empty\n");
	} else {
		printf("Error:In the DeleteCh_List_Num: ");
		printf("Index is false\n");
		re = NULL;
	}
	return re;
}
void StatusCh_List_Num(PtrToCh_ListHead_Num q,int n) {
	printf("The status of Ch_List_Num %d\n",n);

	printf("\tLength of Ch_List_Num %d\n",LengthCh_List_Num(q));
	(IsEmptyCh_List_Num(q) == TRUE)?(printf("\tCh_List_Num is Empty\n")):(printf("\tCh_List_Num is not empty\n"));
}
