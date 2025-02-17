#include "Ch_List.h"
#include <stdio.h>

PtrToCh_ListHead0 F0 (PtrToCh_ListHead0 p0,PtrToCh_ListHead0 p1);
PtrToCh_ListNode0 Write(PtrToCh_ListNode0 p,double c,int e);
void Scanf(PtrToCh_ListHead0 p,int n);
void Printf(PtrToCh_ListHead0 p);

int main() {
	int Num;
	Ch_ListNode0 *p0 = MakeCh_ListHead0();
	Ch_ListNode0 *p1 = MakeCh_ListHead0();

	printf("Please enter Number of Ploy\n");
	scanf("%d",&Num);

	Scanf(p0,Num);
	printf("dian0\n");
	F0(p0,p1);
	printf("dian1\n");
	Printf(p1);
	return 0;
}
//funcation
PtrToCh_ListHead0 F0 (PtrToCh_ListHead0 p0,PtrToCh_ListHead0 p1) {
	p0 = p0 -> Next;
	status Leap = ((p0->Data.Exp) > 0)?(FALSE):(TRUE);

	while (p0 != NULL) {
		int Exp;
		double Coef;
		if(Leap == FALSE) { 
			if((p0->Data.Exp) != 0) {
				Coef = (p0->Data.Coef) * (p0->Data.Exp);
				Exp = (p0->Data.Exp) - 1;
				p1 = Write(p1,Coef,Exp);
			}
		} else {
			Exp = Coef = 0;
			p1 = Write(p1,Coef,Exp);
		}
		p0 = p0 -> Next;
	}

	return p1;
}
PtrToCh_ListNode0 Write(PtrToCh_ListNode0 p,double c,int e) {
	Ploy t;

	t.Exp = e;
	t.Coef = c;

	InsertCh_List0(p,&t,1);
	p = p -> Next;

	return p;
}	
void Scanf(PtrToCh_ListHead0 p,int n) {
	printf("Please enter Data\n");
	for(int i = 0;i < n;i ++) {
		int e;
		double c;
		printf("Cofe = ");
		scanf("%lf",&c);
		printf("Exp = ");
		scanf("%d",&e);
		p = Write(p,c,e);
	}
}
void Printf(PtrToCh_ListHead0 p) {
	printf("result is ...\n");

	p = p -> Next;
	while( p != NULL) {
		char c = ((p->Next) != NULL)?(' '):('\0');
		printf("%.2lf %d%c",(p->Data.Coef),(p->Data.Exp),c);
		p = p -> Next;
	}
	putchar('\n');
}
