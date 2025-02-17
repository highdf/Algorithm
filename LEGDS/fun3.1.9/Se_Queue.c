#include <stdio.h>
#include <stdlib.h>
#include "Se_Queue.h"

PtrToSe_Queue_Num MakeSe_Queue_Num(Length n) {
	Se_Queue_Num *q = (Se_Queue_Num*)malloc(sizeof(Se_Queue_Num));

	if(q != NULL) {
		q -> Data = (ElementTypeSe_Queue_Num*) malloc(sizeof(ElementTypeSe_Queue_Num) * n);
		q -> Front = 0;
		q -> Count = 0;
		q -> MaxSize = n;
	} else {
		printf("Make Se_Queue_Num is error\n");
	}

	return q;
}
status IsEmptySe_Queue_Num(PtrToSe_Queue_Num p) {
	return ((p -> Count) == 0)?(TRUE):(FALSE);
}
status IsFullSe_Queue_Num(PtrToSe_Queue_Num p) {
	return ((p->Count) == (p->MaxSize))?(TRUE):(FALSE);
}
status AddSe_Queue_Num(PtrToSe_Queue_Num p,PtrToEl_Ty_Se_Q_Num x) {
	status re;
	if(IsFullSe_Queue_Num(p) == TRUE) {
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
ElementTypeSe_Queue_Num DeleteSe_Queue_Num(PtrToSe_Queue_Num p) {
	ElementTypeSe_Queue_Num a;

	if(IsEmptySe_Queue_Num(p) == FALSE) {
		a = p -> Data[p->Front];
		p -> Front = (p->Front + 1) % (p->MaxSize);
		p -> Count --;
	} else {
		printf("Delete Se_Queue_NUm error\n");
	}

	return a;
}
void StatusSe_Queue_Num(PtrToSe_Queue_Num q,Serial_Number n) {
	printf("Se_Queue_Num Status %d \n",n);
	printf("\tMaxSize is %d\n", q->MaxSize);
	printf("\tFront = %d,Count = %d\n",q->Front,q->Count);
	(IsEmptySe_Queue_Num(q) ==TRUE)?(printf("\tIs Empty\n")):(printf("\tIs not Empty\n"));
	(IsFullSe_Queue_Num(q) == TRUE)?(printf("\tIs Full\n")):(printf("\tIs not Full\n"));

}
status Pop(PtrToSe_Queue_Num q,PtrToEl_Ty_Se_Q_Num x) {
	status re;

	if(IsFullSe_Queue_Num(q) == FALSE) {
		q -> Front = ((q -> Front) - 1);
		q -> Front = ((q->Front) < 0)?((q->MaxSize) + (q->Front)):(q->Front);
		printf("Front = %d\n",q -> Front);
		q -> Data[q->Front] = *x;
		q -> Count ++;
		re = TRUE;
	} else {
		printf("Pop Se_Queue_Num is error\n");
		re = FALSE;
	}
	return re;
}
ElementTypeSe_Queue_Num Eject(PtrToSe_Queue_Num q) {
	ElementTypeSe_Queue_Num x;
	
	if(IsEmptySe_Queue_Num(q) == FALSE) {
		int n = (q->Front) + (q->Count) - 1;
		x = q -> Data[n];
		q -> Count --;
	} else {
		printf("Eject Se_Queue is error\n");
	}

	return x;
}
