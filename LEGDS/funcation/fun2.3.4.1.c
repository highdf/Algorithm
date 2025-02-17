#include <stdio.h>
#include "Ch_List.h"

void FindPr_Fac(int Num,PtrToCh_List p,int Prime,int N);
void P(int N,PtrToCh_List p);
int main()
{
	int Num;
	Ch_List *Head = MakeCh_ListHead();
	printf("Please enter a number\n");
	scanf("%d",&Num);

	if(Num != 10) {
		FindPr_Fac(Num,Head,2,Num);
	} else {
		printf("1 = 1\n");
	}

	return 0;
}
//funcation
void FindPr_Fac(int Num,PtrToCh_List p,int Prime,int N) {
	Ch_List *q = p;
	if(Num == 1) {
		P(N,p);
	} else {
		status Leap0 = FALSE;
		status Leap2 = FALSE;

		while(Leap0 != TRUE) {
			status Leap1 = TRUE;
			if(Prime == 2) {
				
			} else if(Prime % 2 == 0) {
				Leap1 = FALSE;
			} else {	
				for(int i = 3;i < Prime && Leap1 != FALSE;i += 2) {
					(Prime % i == 0)?(Leap1 = FALSE):(Leap1 = TRUE);
				}
			}
			if(Leap1 == TRUE) {
				(Num % Prime == 0)?(Leap0 = TRUE):(Prime ++);
			} else {
				Prime ++;
			}
			}	

		while(p -> Next != NULL) {
			p = p -> Next;
			if(p -> Data . Pr_Fac == Prime) {
				Leap2 = TRUE;
				break;
			} 
		}

		if(Leap2 == TRUE) {
			p -> Data . Exp ++;
		} else {
			MakeCh_ListNode(p);
			p = p -> Next;
			p -> Data . Pr_Fac = Prime;
			p -> Data . Exp = 1;
		}
		FindPr_Fac(Num/Prime,q,Prime,N);
	}
}
					
void P(int N,PtrToCh_List p) {

	printf("%d = ",N);
	while(p -> Next != NULL) {
		p = p -> Next;
		(p -> Data . Exp > 1)?(printf("%d ^ %d",p->Data . Pr_Fac,p->Data . Exp)):(printf("%d",p->Data . Pr_Fac));
		if(p -> Next != NULL) {
			printf(" * ");
		}
	}
	putchar('\n');
}


