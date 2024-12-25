#include <stdio.h>
#include "Ch_List.h"

void FindPr_Num(int Num,int Start);
int FindFac(int Num,int *S);
void P(int N);
Ch_List *Head;

int main() 
{
	int Num;

	printf("Pleae enter a number\n");
	scanf("%d",&Num);
	Head = MakeCh_ListHead();

	if(Num > 1) {
		FindPr_Num(Num,2);
		P(Num);
	} else {
		printf("1 = 1\n");
	}


	return 0;
}
//funcation
void FindPr_Num(int Num,int Start) {
	int i;

	while(Num != 1) {
		if( Start == 2) {
			Num = FindFac(Num,&Start);	
		} else {
			status Leap = TRUE;
			for( i = 2; i < Start && Leap != FALSE;i ++) {
				(Start % i == 0)?(Leap = FALSE):(Leap = TRUE);	
			}
			(Leap == TRUE)?(Num = FindFac(Num,&Start)):(Start ++);
		}
	}
}
int FindFac(int Num,int *S) {
	status Leap;
	int Fac = *S;
	int re;

	(Num % Fac == 0)?(Leap = TRUE):(Leap = FALSE);

	if(Leap == FALSE) {
		re = Num;
		(*S) ++;
	} else {
		Ch_List *p = Head;
		status Leap1 = FALSE;
		while(p -> Next != NULL) {
			p = p -> Next;
			if(p -> Data . Pr_Fac == Fac) {
				Leap1 = TRUE;
				break;
			} 
		}
		if(Leap1 == FALSE) {
			MakeCh_ListNode(Head);
			p = p -> Next;
			p -> Data .  Pr_Fac = Fac;
			p -> Data .  Exp = 1;
		} else {
			p -> Data . Exp ++;
		}
		*S = 2;
		re = Num / Fac;
	}

	return re;
}
void P(int N) {
	Ch_List *p = Head;

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
