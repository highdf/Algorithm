#include <stdio.h>
#include "Se_List.h"

void D(PtrToSe_List p,ElementTypeSe_L MinD,ElementTypeSe_L MaxD);
int main()
{
	ElementTypeSe_L MinD,MaxD;
	Se_List *p ;
	int i;
	int Len;

	printf("Please enter Se_List of Length\n");
	scanf("%d",&Len);

	p = MakeSe_List(Len);
	printf("Please initialize it\n");
	for(i = 0;i < Len;i ++) {
		ElementTypeSe_L n;
		scanf("%d",&n);
		InsertSe_List(p,i,n);
		
	}
	printf("Please enter need Data interval to be delete\n");
	scanf("%d %d",&MinD,&MaxD);

	D(p,MinD,MaxD);
	printf("After Element is\n");

	for( i = 0;i <= (p -> Last);i ++) {
		printf("%d ",p->Data[i]);
	}
	printf("\n");

	return 0;
}
//funcation
void D(PtrToSe_List a,ElementTypeSe_L minD,ElementTypeSe_L maxD) {
	int i,j;
	int p;

	for(i = 0;i <= (a->Last);i ++) {
		if( (a->Data[i]) >= minD && (a->Data[i]) <= maxD) {
			p = i;
			j = 0;
			while(i <= (a->Last)) {
				if( (a->Data[i]) < minD || (a->Data[i]) > maxD) {
					a->Data[p++] = a->Data[i];
				}
					i ++;
			}
			a->Last = p-1;
			break;
		}
	}
}
