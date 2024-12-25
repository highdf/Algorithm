#include "Ch_Stack_in.h"
#include "Ch_Stack_out.h"

PtrToCh_Stack0 MakeCh_Stack0(void) {
	Ch_Stack0 *c = (Ch_Stack0*) malloc(sizeof(Ch_Stack0));

	if(c != NULL) {
		c -> Top = &(c -> Head);
		c -> Head.Next = NULL;
	} else {
		printf("Error:In the MakeCh_Stack0: ");
		printf("Malloc is erro\n");
	}
	return c;
}
status IsEmptyCh_Stack0(PtrToCh_Stack0 p) {
	return (p->Top == &(p->Head))?(TRUE):(FALSE);
}
void PushCh_Stack0(PtrToCh_Stack0 p,ElementTypeCh_Stack0 *n) {
	Ch_StackNode0 *q = (Ch_StackNode0*) malloc(sizeof(Ch_StackNode0));

	if(q != NULL) {
		q -> Data = n;
		q -> Next = p -> Top;
		p -> Top = q;
	} else {
		printf("Error:In the PushCh_Stack0: ");
		printf("Malloc is false \n");
	}
}
ElementTypeCh_Stack0* PopCh_Stack0(PtrToCh_Stack0 p) {
	ElementTypeCh_Stack0 *re;

	if( IsEmptyCh_Stack0(p) == FALSE) {
		re = p -> Top -> Data;
		Ch_StackNode0 *w = p -> Top -> Next;
		free(p -> Top);
		p -> Top = w;
	} else {
		printf("Error:In the Ch_Stack0: ");
		printf("The Ch_Stack0 is empty\n");
	}
	return re;
}
int LengthCh_Stack0(PtrToCh_Stack0 p) {
	int Cun = 0;
	Ch_StackNode0 *q = p -> Top;
	
	while(q != (&(p->Head))) {
		q = q -> Next;
		Cun ++;
	}
	return Cun;

}
void StatusCh_Stack0(PtrToCh_Stack0 p,int n) {
	printf("Ch_Stack0 %d\n",n);
	(IsEmptyCh_Stack0(p) == TRUE)?(printf("\tIs Empty\n")):(printf("\tnot Empty\n"));
	printf("\tLength is %d\n",LengthCh_Stack0(p));

}	
