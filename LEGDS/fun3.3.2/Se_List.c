#include "Se_List.h"
#include <stdio.h>
#include <stdlib.h>
#include "status.h"

PtrToSe_List0 MakeSe_List0 (Se_List_Size n) {
	Se_List0 *q = (Se_List0*) malloc(sizeof(Se_List0));

	if(q != NULL) {
		q -> Data = (ElementTypeSe_L0*)malloc(sizeof(ElementTypeSe_L0) * n);
		if((q->Data) != NULL) {
			q -> Last = -1;
			q -> MaxSize = n;
		} else {
			printf("Make Se_List0 is error\n");
		}
	} else {
		printf("Make Se_List0 is error\n");
	}
	return q;
}
status IsEmptySe_List0 (PtrToSe_List0 a) {
	status re;

	re = (a -> Last == -1)?(TRUE):(FALSE);
	return re;
}
status IsFullSe_List0 (PtrToSe_List0 a) {
	status re;
	(a -> Last == (a -> MaxSize - 1))?(re = TRUE):(re = FALSE);
	 
	return re;
}
status InsertSe_List0 (PtrToSe_List0 a,El_Ty_Se_L0 x,PositionToOne t) {
	status re;
	t = t - 1;

	if(IsFullSe_List0(a) == TRUE) {
		printf("Se_List0 Insert is FALSE\n");
		re = FALSE;
	} else {
		if(t >= 0 && t <= (a -> Last + 1)) {
			int i;
			for(i = (a->Last + 1);i > t;i --) {
				a -> Data[i] = a -> Data[i-1];
			}
			a -> Data[i] = *x;	
			a -> Last ++;
			re = TRUE;
		} else {
			printf("Se_List0 Insert is FALSE\n");
			re = FALSE;
		}
	}
	return re;
}
status DeleteSe_List0 (PtrToSe_List0 a,PositionToOne t) {
	status re;
	t --;
	if(IsEmptySe_List0(a) == TRUE) {
		printf("Delete Se_List is error\n");
		re = FALSE;
	} else {
		if(t >= 0 && t <= (a->Last)) {
			int i;
			for(i = t+1;i <= (a -> Last);i ++) {
				a -> Data[i-1] = a -> Data[i];
			}
			a -> Last --;
			re = TRUE;	
		} else {
			printf("Se_List0 Delete is ERROR\n");
			re = FALSE;
		}
	}
	return re;
}
void StatusSe_List0 (PtrToSe_List0 q,Serial0ber n) {
		printf("Se_List0 %d status\n",n);
		printf("\tLast = %d\nSize = %d\n",q -> Last,q -> MaxSize);

		(IsEmptySe_List0(q) == TRUE)?(printf("\tSe_List0 %d IsEmpty\n",n)):(printf("\tSe_List0 %d Is not Empty\n",n));

		(IsFullSe_List0(q) == TRUE)?(printf("\tSe_List0 %d IsFull\n",n)):(printf("\tList0 %d Is not Full\n",n));
}


