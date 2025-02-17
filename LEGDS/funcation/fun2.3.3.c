#include <stdio.h>
#include "Ch_List.h"
void F0(PtrToCh_List p0,PtrToCh_List p1,PtrToCh_List p2);
void S(PtrToCh_List p);

int main()
{
	Ch_List *Head1,*Head2,*Head3;
	int num;

	printf("Please enter number of numbers\n");
	Head1 = MakeCh_ListHead();
	Head2 = MakeCh_ListHead();
	Head3 = MakeCh_ListHead();

	S(Head1);
	S(Head2);

	F0(Head1,Head2,Head3);

	printf("result is\n");
	if(IsEmptyCh_List(Head3) == TRUE) {
		printf("NULL\n");
	} else {
		while(Head3 -> Next != NULL) {
			Head3 = Head3 -> Next;
			printf("%d ",Head3 -> Data);
		}
		putchar('\n');
	}

	return 0;
}
//funcation
void S(PtrToCh_List p) {
	int num;
	scanf("%d",&num);
	while(num != -1) {
		MakeCh_ListNode(p);
		p = p -> Next;
		p -> Data = num;
		scanf("%d",&num);
	}
}
void F0(PtrToCh_List p0,PtrToCh_List p1,PtrToCh_List p2) {
	int i,j;

	p0 = p0 -> Next;
	p1 = p1 -> Next;

	while(p0 != NULL) {
		while(p1 != NULL) {
			if(p0 -> Data == p1 -> Data) {
				p2 -> Next = p0;
				p2 = p2 -> Next;
				p1 = p1 -> Next;
				break;
			} else if(p0 -> Data < p1 -> Data) {
				break;
			} else {
				p1 = p1 -> Next;
			}
		}
		p0 = p0 -> Next;
	}
}
