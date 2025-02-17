#include <stdio.h>
#include <stdlib.h>
#include "Se_Queue.h"

PtrToSe_Queue1 MakeSe_Queue1(Length n) {
	Se_Queue1 *q = (Se_Queue1*)malloc(sizeof(Se_Queue1));

	if(q != NULL) {
		q -> Data = (ElementTypeSe_Queue1*) malloc(sizeof(ElementTypeSe_Queue1) * n);
		if((q->Data) != NULL) {
			q -> Front = 0;
			q -> Count = 0;
			q -> MaxSize = n;
		} else {
			printf("Make Se_Queue1 is error\n");
		}
	} else {
		printf("Make Se_Queue1 is error\n");
	}

	return q;
}
status IsEmptySe_Queue1(PtrToSe_Queue1 p) {
	return ((p -> Count) == 0)?(TRUE):(FALSE);
}
status IsFullSe_Queue1(PtrToSe_Queue1 p) {
	return ((p->Count) == (p->MaxSize))?(TRUE):(FALSE);
}
status AddSe_Queue1(PtrToSe_Queue1 p,PtrToEl_Ty_Se_Q1 x) {
	status re;
	if(IsFullSe_Queue1(p) == TRUE) {
		printf("AddSe_Queue_NUm error\n");
		re = FALSE;
	} else {
		int Rear = ((p->Front) + (p->Count)) % (p->MaxSize);
		p -> Data[Rear] = *x;
		p -> Count ++;
		re = TRUE;
	}
	return re;
}
ElementTypeSe_Queue1 DeleteSe_Queue1(PtrToSe_Queue1 p) {
	ElementTypeSe_Queue1 a;

	if(IsEmptySe_Queue1(p) == FALSE) {
		a = p -> Data[p->Front];
		p -> Front = (p->Front + 1) % (p->MaxSize);
		p -> Count --;
	} else {
		printf("Delete Se_Queue_NUm error\n");
	}

	return a;
}
void StatusSe_Queue1(PtrToSe_Queue1 q,Serial1ber n) {
	printf("Se_Queue1 Status %d \n",n);
	printf("\tMaxSize is %d\n", q->MaxSize);
	printf("\tFront = %d,Count = %d\n",q->Front,q->Count);
	(IsEmptySe_Queue1(q) ==TRUE)?(printf("\tIs Empty\n")):(printf("\tIs not Empty\n"));
	(IsFullSe_Queue1(q) == TRUE)?(printf("\tIs Full\n")):(printf("\tIs not Full\n"));

}
