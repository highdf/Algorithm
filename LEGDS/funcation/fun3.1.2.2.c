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
//funcarion
void F(PtrToSe_List a) {
	int i;
	status Leap = FALSE;
	int ThisL,ThisR,ThisLen;
	int MaxLen,Left,Right;

	MaxLen = ThisLen = 0;
	for(i = 0;i < (a->Last); i ++) {
		if( (a->Data[i]) < (a->Data[i+1])) {
			if(Leap == FALSE) {
				printf("a\n");
				ThisL = i;
				ThisR = i+1;
				ThisLen = 2;
				Leap = TRUE;
			} else {
				ThisR ++;
				ThisLen ++;
			}

		} 
		if((! (a->Data[i]) < (a->Data[i+1])) ||( i == (a->Last-1))) {
			Leap = FALSE;
			if(MaxLen < ThisLen) {
				Left = ThisL;
				Right = ThisR;
				MaxLen = ThisLen;
			}
		}
	}

	if(MaxLen > 0) {
		for(i = Left;i <= Right;i ++) {
			printf("%d%c",(a->Data[i]),(i == Right)?('\n'):(' '));
	}
	} else {
		printf("None\n");
	}
}
