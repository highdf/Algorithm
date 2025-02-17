#include <stdio.h>
#include <stdlib.h>
#include "Ch_Stack3.1.8.h"

PtrToCh_Stack1 MakeCh_Stack1(void) {
	Ch_Stack1 *c = (Ch_Stack1*) malloc(sizeof(Ch_Stack1));
	c -> Top = &(c -> Head);
	c -> Head.Next = NULL;
	return c;
}
status IsEmptyCh_Stack1(PtrToCh_Stack1 p) {
	return (p->Top == &(p->Head))?(TRUE):(FALSE);
}
void PushCh_Stack1(PtrToCh_Stack1 p,PtrToEl_Ty_Ch_S1 n) {
	Ch_StackNode1 *q = (Ch_StackNode1*) malloc(sizeof(Ch_StackNode1));
	q -> Data = *n;
	q -> Next = p -> Top;
	p -> Top = q;
}
status PopCh_Stack1(PtrToCh_Stack1 p) {
	status re;

	if( IsEmptyCh_Stack1(p) == FALSE) {
		Ch_StackNode1 *w = p -> Top -> Next;
		free(p -> Top);
		p -> Top = w;
		re = TRUE;
	} else {
		printf("ERROR\n");
		re = FALSE;
	}
	return re;

}
Length LengthCh_Stack1(PtrToCh_Stack1 p) {
	int Cun = 0;
	Ch_StackNode1 *q = p -> Top;
	
	while(q != (&(p->Head))) {
		q = q -> Next;
		Cun ++;
	}
	return Cun;

}
void StatusCh_Stack1(PtrToCh_Stack1 p,SerialNumber n) {
	printf("Ch_Stack1 %d\n",n);
	(IsEmptyCh_Stack1(p) == TRUE)?(printf("Is Empty\n")):(printf("not Empty\n"));
	printf("Length is %d\n",LengthCh_Stack1(p));
}

