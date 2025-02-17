#include <stdio.h>
#include "Ch_Stack.h"

void G(PtrToCh_Stack p,int n,int a0,int a1,int a2);
void F(int Num);
int main()
{
	int Num;

	printf("Please enter number of plate\n");
	scanf("%d",&Num);

	if( Num >= 1) {
		F(Num);
	} else {
		printf("error in quantily\n");
	}
	return 0;
}
//funcation
void F(int Num) {
	printf("reslut \n");
	printf("Plate\ta\tb\tc\t\n");
	Ch_Stack *p = MakeCh_Stack();
	G(p,Num,0,1,2);

	do{
		if( p->Top->Data.PlateNum > 1) {
			int n,a0,a1,a2;
			n = p->Top->Data.PlateNum;
			a0 = p->Top->Data.P0;
			a1 = p->Top->Data.P1;
			a2 = p->Top->Data.P2;
			PopCh_Stack(p);
			G(p,n-1,a1,a0,a2);
			G(p,1,a0,a1,a2);
			G(p,n-1,a0,a2,a1);
		} else {
			printf("%d\t%d\t%d\t%d\n",(p->Top->Data.PlateNum),(p->Top->Data.P0),(p->Top->Data.P1),(p->Top->Data.P2));
			PopCh_Stack(p);
		}
	}while( IsEmptyCh_Stack(p) != TRUE);
}
void G(PtrToCh_Stack p,int n,int a0,int a1,int a2) {
	HanJota q;

	q.PlateNum = n;
	q.P0 = a0;
	q.P1 = a1;
	q.P2 = a2;
	PushCh_Stack(p,&q);
	
}
