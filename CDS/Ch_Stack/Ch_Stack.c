#include "Ch_Stack_in.h"
#include "Ch_Stack_out.h"

PtrToCh_Stack_Num MakeCh_Stack_Num(void) {
	Ch_Stack_Num *c = (Ch_Stack_Num*) malloc(sizeof(Ch_Stack_Num));

	if(c != NULL) {
		c -> Top = &(c -> Head);
		c -> Head.Next = NULL;
	} else {
		printf("Error:In the MakeCh_Stack_Num: ");
		printf("Malloc is erro\n");
	}
	return c;
}
status IsEmptyCh_Stack_Num(PtrToCh_Stack_Num p) {
	return (p->Top == &(p->Head))?(TRUE):(FALSE);
}
void PushCh_Stack_Num(PtrToCh_Stack_Num p,ElementTypeCh_Stack_Num *n) {
	Ch_StackNode_Num *q = (Ch_StackNode_Num*) malloc(sizeof(Ch_StackNode_Num));

	if(q != NULL) {
		q -> Data = n;
		q -> Next = p -> Top;
		p -> Top = q;
	} else {
		printf("Error:In the PushCh_Stack_Num: ");
		printf("Malloc is false \n");
	}
}
ElementTypeCh_Stack_Num* PopCh_Stack_Num(PtrToCh_Stack_Num p) {
	ElementTypeCh_Stack_Num *re;

	if( IsEmptyCh_Stack_Num(p) == FALSE) {
		re = p -> Top -> Data;
		Ch_StackNode_Num *w = p -> Top -> Next;
		free(p -> Top);
		p -> Top = w;
	} else {
		printf("Error:In the Ch_Stack_Num: ");
		printf("The Ch_Stack_Num is empty\n");
	}
	return re;
}
int LengthCh_Stack_Num(PtrToCh_Stack_Num p) {
	int Cun = 0;
	Ch_StackNode_Num *q = p -> Top;
	
	while(q != (&(p->Head))) {
		q = q -> Next;
		Cun ++;
	}
	return Cun;

}
void StatusCh_Stack_Num(PtrToCh_Stack_Num p,int n) {
	printf("Ch_Stack_Num %d\n",n);
	(IsEmptyCh_Stack_Num(p) == TRUE)?(printf("\tIs Empty\n")):(printf("\tnot Empty\n"));
	printf("\tLength is %d\n",LengthCh_Stack_Num(p));

}	
