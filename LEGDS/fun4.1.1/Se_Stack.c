#include "Se_Stack.h"

PtrToSe_Stack0 MakeSe_Stack0(Length n) {
	Se_Stack0 *q = (Se_Stack0*) malloc(sizeof(Se_Stack0));

	if(q != NULL) {
		q -> Data = (ElementTypeSe_Stack0*)malloc(sizeof(ElementTypeSe_Stack0)*n);
		if((q->Data) != NULL) {
			q -> Top = -1;
			q -> SIZE = n;
		} else {
			printf("Make Se_Stack0 is error\n");
		}
	} else {
		printf("Make Se_Stack0 is error\n");
	}
	return q;
}
status IsEmptySe_Stack0(PtrToSe_Stack0 s) {
	return (s -> Top == -1)? (TRUE):(FALSE);
	 
}
status IsFullSe_Stack0(PtrToSe_Stack0 a) {
	return (a -> Top == (a -> SIZE - 1))?(TRUE):(FALSE);
}
status PushSe_Stack0(PtrToSe_Stack0 a,PtrToEl_Ty_Se_S0 p) {
	status re;

	if(IsFullSe_Stack0(a) == FALSE) {
		a -> Top ++;
		a -> Data[a->Top] = *p;
		re = TRUE;
	} else {
		printf("Push Se_Stack0 is ERROR\n");
		re = FALSE;
	}
	return re;
}
ElementTypeSe_Stack0 PopSe_Stack0(PtrToSe_Stack0 a) {
	ElementTypeSe_Stack0 x;

	if(IsEmptySe_Stack0(a) == FALSE) {
		x = a -> Data[a->Top];
		a -> Top --;
	} else {
		printf("Pop Se_Stack0 is ERROR\n");
	}
	return x;
}
void StatusSe_Stack0(PtrToSe_Stack0 a,Number n) {
	printf("Number %d Se_Stack0\n",n);
	(IsEmptySe_Stack0(a) == TRUE)?(printf("\tIsEmpty\n")):(printf("\tis ont Empty\n"));
	(IsFullSe_Stack0(a) == TRUE)?(printf("\tIsFull\n")):(printf("\tis not full\n"));
	printf("\tTop = %d\n",a->Top);
}
