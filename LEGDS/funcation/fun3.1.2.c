#include <stdio.h>
#include "Se_List.h"
void F(PtrToSe_List a);

int main()
{
	int Len;
	printf("Please enter List of Length\n");
	scanf("%d",&Len);

	Se_List *a = MakeSe_List(Len);
	int i;
	ElementTypeSe_L num;
	printf("Please initialize it\n");
	for(i = 0;i < Len;i ++) {
		scanf("%d",&num);
		InsertSe_List(a,i,num);
	}

	F(a);

	return 0;
}
//funcation
void F(PtrToSe_List a) {
	int i;
	int Len0,Len1;
	int Left,Right;
	int ThisF,ThisR;

	Len0 = Len1 = 0;

	for( i = 0 ;i < (a->Last);i ++) {
		if( (a->Data[i]) <= (a->Data[i+1])) {
			ThisF = i;
			printf("ThisL = %d\n",ThisF);
			do{
				i ++;	
			}while((i < (a->Last) && ((a->Data[i] < (a->Data[i+1])))));
			ThisR = i;
			Len0 = (ThisR - ThisF) + 1;

			if(Len0 > Len1) {
				Left = ThisF;
				Right = ThisR;
				Len1 = Len0;
			}
		} 
	}
	printf("result \n");
	if(Len1 > 0) {
		for( i = Left;i <= Right;i ++) {
			printf("%d%c",(a->Data[i]),(i ==Len1-1)?('\n'):(' '));
		}
	} else {
		printf("none\n");
	}
}

