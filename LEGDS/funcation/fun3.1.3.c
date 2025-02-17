#include <stdio.h>
#include "Ch_List.h"
typedef int Position;
ElementTypeCh_L F(PtrToCh_ListHead t,Position m,status *Leap);

int main() 
{
	Ch_List *Head;
	ElementTypeCh_L Num;
	Ch_List *p;
	int Len;
	int m;
	status Leap;

	Head = MakeCh_ListHead();
	p = Head;

	printf("Please enter Length\n");
	scanf("%d",&Len);
	printf("Find Elment Position\n");
	scanf("%d",&m);
	printf("Please enter number of numbers\n");

	MakeCh_ListNodes(Head,Len);

	for(int i = 0;i < Len;i ++) {
		p = p -> Next;
		scanf("%d",&(p->Data));
	}
	
	Num = F(Head,m,&Leap);

	if(Leap == TRUE) {
		printf("Element is %d\n",Num);
	}

	return 0;
}
//funcarion
ElementTypeCh_L F(PtrToCh_ListHead t,Position m,status *Leap) {
	Ch_List *p,*q;

	p = t;
	q = t;

	if(m >= 1) {
		while( (p -> Next) != NULL && m > 0) {
			p = p -> Next;
			m --;
		}
		if(m > 0) {
			*(Leap) = FALSE;
			printf("ERROR\n");
		} else {
			*Leap = TRUE;
			q = q -> Next;
			while( p -> Next != NULL) {
				p = p -> Next;
				q = q -> Next;
			}
		}
	} else {
		*Leap = FALSE;
		printf("ERROR\n");
	}

	return (q->Data);
}
