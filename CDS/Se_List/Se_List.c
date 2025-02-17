#include "Se_List_in.h"
#include "Se_List_out.h"

PtrToSe_List_Num MakeSe_List_Num (int n) {
	Se_List_Num *q = (Se_List_Num*) malloc(sizeof(Se_List_Num));

	if(q != NULL) {
		q -> Data = (PtrToElementSe_List_Num*)malloc(sizeof(PtrToElementSe_List_Num) * n);
		if((q->Data) != NULL) {
			q -> Last = -1;
			q -> Size = n;
		} else {
			printf("Error:In the MakeSe_List: ");
			printf("Malloc is false\n");
		}
	} else {
			printf("Error:In the MakeSe_List: ");
			printf("Malloc is false\n");
	}
	return q;
}
status IsEmptySe_List_Num (PtrToSe_List_Num a) {
	status re;

	re = (a -> Last == -1)?(TRUE):(FALSE);
	return re;
}
status IsFullSe_List_Num (PtrToSe_List_Num a) {
	status re;
	(a -> Last == (a -> Size - 1))?(re = TRUE):(re = FALSE);
	 
	return re;
}
status InsertSe_List_Num (PtrToSe_List_Num a,ElementTypeSe_List_Num *x,int t) {
	status re;

	if(IsFullSe_List_Num(a) == TRUE) {
		printf("Error:In the InsertSe_List_Num: ");
		printf("The Se_List_Num is full\n");
		re = FALSE;
	} else {
		if(t >= 0 && t <= (a -> Last + 1)) {
			int i;
			for(i = (a->Last + 1);i > t;i --) {
				a -> Data[i] = a -> Data[i-1];
			}
			a -> Data[i] = x;	
			a -> Last ++;
			re = TRUE;
		} else {
			printf("Error:In the InsertSe_List_Num: ");
			printf("Index is error\n");
			re = FALSE;
		}
	}
	return re;
}
PtrToElementSe_List_Num DeleteSe_List_Num (PtrToSe_List_Num a,int t) {
	PtrToElementSe_List_Num re = a -> Data[t];

	if(IsEmptySe_List_Num(a) == TRUE) {
		printf("Error:In the DeleteSe_List: ");
		printf("the Se_List_Num is empty\n");
	} else {
		if(t >= 0 && t <= (a->Last)) {
			int i;
			for(i = t+1;i <= (a -> Last);i ++) {
				a -> Data[i-1] = a -> Data[i];
			}
			a -> Last --;
		} else {
			printf("Error:In the DeleteSe_List: ");
			printf("The index is error\n");
		}
	}
	return re;
}
void StatusSe_List_Num (PtrToSe_List_Num q,int n) {
		printf("Se_List_Num %d status\n",n);
		printf("\tLast = %d\n\tSize = %d\n",q -> Last,q -> Size);

		(IsEmptySe_List_Num(q) == TRUE)?(printf("\tSe_List_Num %d IsEmpty\n",n)):(printf("\tSe_List_Num %d Is not Empty\n",n));

		(IsFullSe_List_Num(q) == TRUE)?(printf("\tSe_List_Num %d IsFull\n",n)):(printf("\tList_Num %d Is not Full\n",n));
}


