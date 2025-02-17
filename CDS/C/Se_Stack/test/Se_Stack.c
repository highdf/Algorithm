#include "Se_Stack_in.h"
#include "Se_Stack_out.h"

PtrToSe_Stack_Num MakeSe_Stack_Num(int n) {
	Se_Stack_Num *q = (Se_Stack_Num*) malloc(sizeof(Se_Stack_Num));

	if(q != NULL) {
		q -> Data = (PtrToElementSe_Stack_Num*)malloc(sizeof(PtrToElementSe_Stack_Num)*n);
		if((q->Data) != NULL) {
			q -> Top = -1;
			q -> Size = n;
		} else {
			printf("Error:In the makeSe_Stack_Num: ");
			printf("malloc is fasse\n");
		}
	} else {
		printf("Error:In the makeSe_Stack_Num: ");
		printf("malloc is fasse\n");
	}
	return q;
}
status IsEmptySe_Stack_Num(PtrToSe_Stack_Num s) {
	return (s -> Top == -1)? (TRUE):(FALSE);
}
status IsFullSe_Stack_Num(PtrToSe_Stack_Num a) {
	return (a -> Top == (a -> Size - 1))?(TRUE):(FALSE);
}
status PushSe_Stack_Num(PtrToSe_Stack_Num a,ElementTypeSe_Stack_Num* p) {
	status re;

	if(IsFullSe_Stack_Num(a) == FALSE) {
		a -> Top ++;
		a -> Data[a->Top] = p;
		re = TRUE;
	} else {
		printf("Error:In the PushSe_Stack_Num: ");
		printf("The Se_Stack_Num is Full\n");
		re = FALSE;
	}
	return re;
}
PtrToElementSe_Stack_Num PopSe_Stack_Num(PtrToSe_Stack_Num a) {
	PtrToElementSe_Stack_Num x;

	if(IsEmptySe_Stack_Num(a) == FALSE) {
		x = a -> Data[a->Top];
		a -> Top --;
	} else {
		printf("Error:In the PopSe_Stack_Num: ");
		printf("the Se_Stack is empty\n");
	}
	return x;
}
void StatusSe_Stack_Num(PtrToSe_Stack_Num a,int n) {
	printf("Number %d Se_Stack_Num\n",n);
	(IsEmptySe_Stack_Num(a) == TRUE)?(printf("\tIsEmpty\n")):(printf("\tis ont Empty\n"));
	(IsFullSe_Stack_Num(a) == TRUE)?(printf("\tIsFull\n")):(printf("\tis not full\n"));
	printf("\tTop = %d\n",a->Top);
	printf("\tSize = %d\n",a->Size);
}
