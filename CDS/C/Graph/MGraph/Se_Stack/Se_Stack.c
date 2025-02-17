#include "Se_Stack_in.h"
#include "Se_Stack_out.h"

PtrToSe_Stack0 MakeSe_Stack0(int n) {
	Se_Stack0 *q = (Se_Stack0*) malloc(sizeof(Se_Stack0));

	if(q != NULL) {
		q -> Data = (PtrToElementSe_Stack0*)malloc(sizeof(PtrToElementSe_Stack0)*n);
		if((q->Data) != NULL) {
			q -> Top = -1;
			q -> Size = n;
		} else {
			printf("Error:In the makeSe_Stack0: ");
			printf("malloc is fasse\n");
		}
	} else {
		printf("Error:In the makeSe_Stack0: ");
		printf("malloc is fasse\n");
	}
	return q;
}
status IsEmptySe_Stack0(PtrToSe_Stack0 s) {
	return (s -> Top == -1)? (TRUE):(FALSE);
}
status IsFullSe_Stack0(PtrToSe_Stack0 a) {
	return (a -> Top == (a -> Size - 1))?(TRUE):(FALSE);
}
status PushSe_Stack0(PtrToSe_Stack0 a,ElementTypeSe_Stack0* p) {
	status re;

	if(IsFullSe_Stack0(a) == FALSE) {
		a -> Top ++;
		a -> Data[a->Top] = p;
		re = TRUE;
	} else {
		printf("Error:In the PushSe_Stack0: ");
		printf("The Se_Stack0 is Full\n");
		re = FALSE;
	}
	return re;
}
PtrToElementSe_Stack0 PopSe_Stack0(PtrToSe_Stack0 a) {
	PtrToElementSe_Stack0 x;

	if(IsEmptySe_Stack0(a) == FALSE) {
		x = a -> Data[a->Top];
		a -> Top --;
	} else {
		printf("Error:In the PopSe_Stack0: ");
		printf("the Se_Stack is empty\n");
	}
	return x;
}
void StatusSe_Stack0(PtrToSe_Stack0 a,int n) {
	printf("Number %d Se_Stack0\n",n);
	(IsEmptySe_Stack0(a) == TRUE)?(printf("\tIsEmpty\n")):(printf("\tis ont Empty\n"));
	(IsFullSe_Stack0(a) == TRUE)?(printf("\tIsFull\n")):(printf("\tis not full\n"));
	printf("\tTop = %d\n",a->Top);
	printf("\tSize = %d\n",a->Size);
}
