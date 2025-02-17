#include "Ch_List.h"
#include <stdio.h>

void Scanf(PtrToCh_ListHead0 p,int n);
PtrToCh_ListNode0 AttachCh_List0 (PtrToCh_ListNode0 q,PtrToEl_Ty_Ch_L0 t);
void F0(PtrToCh_ListHead0 p,int Len,int k);
PtrToCh_ListNode0 F1(PtrToCh_ListHead0 p0,int k);
void Printf(PtrToCh_ListHead0 p);

int main() {
	int Len,k;
	Ch_ListNode0 *Head = MakeCh_ListHead0();

	printf("Please enter Len and k\n");
	printf("Len = ");
	scanf("%d",&Len);
	printf("k = ");
	scanf("%d",&k);
	
	Scanf(Head,Len);
	if(Len >= k && k > 1) {
		F0(Head,Len,k);
		Printf(Head);
	} else {
		printf("k is error\n");
	}

	return 0;
}
//funcation
void Scanf(PtrToCh_ListHead0 p,int n) {
	printf("Please enter Data\n");

	for(int i = 0;i < n;i ++ ) {
		int Num;
		scanf("%d",&Num);
		p = AttachCh_List0(p,&Num);
	}
}

PtrToCh_ListNode0 AttachCh_List0 (PtrToCh_ListNode0 q,PtrToEl_Ty_Ch_L0 t) {
	InsertCh_List0(q,t,1);
	q = q -> Next;
	
	return q;
}

void F0(PtrToCh_ListHead0 p,int Len,int k) {
	do{
		p = F1(p,k-1);
		Len = Len - k;
	}while(k > 0 && k <= Len);
}
PtrToCh_ListNode0 F1(PtrToCh_ListHead0 p0,int k) {
	Ch_ListNode0 *q0,*q1,*q2,*re;

	re = p0 -> Next;
	q0 = p0 -> Next;
	q1 = q0 -> Next;
	q2 = q1 -> Next;
	while(k > 0) {
		q1 -> Next = q0;
		(k > 1)?(q0 = q1,q1 = q2,q2 = (q2->Next)):((re->Next) = q2,(p0->Next) = q1);
		k --;
	}
	printf("reDAta is %d\n",re -> Data);
	return re;
}
void Printf(PtrToCh_ListHead0 p) {
	p = p -> Next;
	
	while (p != NULL) {
		char c = ((p->Next) == NULL)?('\0'):(' ');
		printf("%d%c",p->Data,c);
		p = p -> Next;
	}	
	putchar('\n');
}
