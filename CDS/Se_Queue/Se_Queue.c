#include "Se_Queue_in.h"
#include "Se_Queue_out.h"

PtrToSe_Queue_Num MakeSe_Queue_Num(int n) {
	Se_Queue_Num *q = (Se_Queue_Num*)malloc(sizeof(Se_Queue_Num));

	if(q != NULL) {
		q -> Data = (PtrToElementSe_Queue_Num*) malloc(sizeof(PtrToElementSe_Queue_Num) * n);
		if((q->Data) != NULL) {
			q -> Front = 0;
			q -> Count = 0;
			q -> MaxSize = n;
		} else {
			printf("Error:In the MakeSe_Queue_Num: ");
			printf("Malloc is error\n");
		}
	} else {
		printf("Error:In the MakeSe_Queue_Num: ");
		printf("Malloc is error\n");
	}

	return q;
}
status IsEmptySe_Queue_Num(PtrToSe_Queue_Num p) {
	return ((p -> Count) == 0)?(TRUE):(FALSE);
}
status IsFullSe_Queue_Num(PtrToSe_Queue_Num p) {
	return ((p->Count) == (p->MaxSize))?(TRUE):(FALSE);
}
status AddSe_Queue_Num(PtrToSe_Queue_Num p,ElementTypeSe_Queue_Num* x) {
	status re;
	if(IsFullSe_Queue_Num(p) == TRUE) {
		printf("Error:In the AddSe_Queue_Num: ");
		printf("The Se_Queue is full\n");
		re = FALSE;
	} else {
		int Rear = ((p->Front) + (p->Count)) % (p->MaxSize);
		p -> Data[Rear] = x;
		p -> Count ++;
		re = TRUE;
	}
	return re;
}
PtrToElementSe_Queue_Num DeleteSe_Queue_Num(PtrToSe_Queue_Num p) {
	PtrToElementSe_Queue_Num a;

	if(IsEmptySe_Queue_Num(p) == FALSE) {
		a = p -> Data[p->Front];
		p -> Front = (p->Front + 1) % (p->MaxSize);
		p -> Count --;
	} else {
		printf("Error:In the DeleteSe_Queue: ");
		printf("The Se_Queue_Num is empty\n");
	}

	return a;
}
void StatusSe_Queue_Num(PtrToSe_Queue_Num q,int n) {
	printf("Se_Queue_Num Status %d \n",n);
	printf("\tMaxSize is %d\n", q->MaxSize);
	printf("\tFront = %d,Count = %d\n",q->Front,q->Count);
	(IsEmptySe_Queue_Num(q) ==TRUE)?(printf("\tIs Empty\n")):(printf("\tIs not Empty\n"));
	(IsFullSe_Queue_Num(q) == TRUE)?(printf("\tIs Full\n")):(printf("\tIs not Full\n"));

}
