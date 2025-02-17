#include "Ch_Stack3.1.8.0.h"
#include <stdio.h>
#include <stdlib.h>

PtrToCh_Stack2 MakeCh_Stack2(void) {
	Ch_Stack2 *c = (Ch_Stack2*) malloc(sizeof(Ch_Stack2));
	c -> Top = &(c -> Head);
	c -> Head.Next = NULL;
	return c;
}
status IsEmptyCh_Stack2(PtrToCh_Stack2 p) {
	return (p->Top == &(p->Head))?(TRUE):(FALSE);
}
void PushCh_Stack2(PtrToCh_Stack2 p,PtrToEl_Ty_Ch_S2 n) {
	Ch_StackNode2 *q = (Ch_StackNode2*) malloc(sizeof(Ch_StackNode2));
	q -> Data = *n;
	q -> Next = p -> Top;
	p -> Top = q;
}
status PopCh_Stack2(PtrToCh_Stack2 p) {
	status re;

	if( IsEmptyCh_Stack2(p) == FALSE) {
		Ch_StackNode2 *w = p -> Top -> Next;
		free(p -> Top);
		p -> Top = w;
		re = TRUE;
	} else {
		printf("ERROR\n");
		re = FALSE;
	}
	return re;

}
Length LengthCh_Stack2(PtrToCh_Stack2 p) {
	int Cun = 0;
	Ch_StackNode2 *q = p -> Top;
	
	while(q != (&(p->Head))) {
		q = q -> Next;
		Cun ++;
	}
	return Cun;

}
void StatusCh_Stack2(PtrToCh_Stack2 p,SerialNumber n) {
	printf("Ch_Stack2 %d\n",n);
	(IsEmptyCh_Stack2(p) == TRUE)?(printf("Is Empty\n")):(printf("not Empty\n"));
	printf("Length is %d\n",LengthCh_Stack2(p));

}	
