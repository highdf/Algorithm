#include "Se_Queue.h"
#include <stdio.h>

void Fun(int n,int Na,int Nb);
int main() {
	int n,Na,Nb;

	printf("Please enter three number\n");
	printf("n = ");
	scanf("%d",&n);
	printf("Na = ");
	scanf("%d",&Na);
	printf("Nb = ");
	scanf("%d",&Nb);
	Fun(n,Na,Nb);
	return 0;
}
//funcation
void Fun(int n,int Na,int Nb) {
	Se_Queue1 *q0 = MakeSe_Queue1(100);	
	Se_Queue1 *q1 = MakeSe_Queue1(100);	
	int n1 = Na,n2;

	printf("Please enter ...\n");
	for(int i = 0;i < n;i ++) {
		int Num;
		scanf("%d",&Num);
		(Num % 2 == 0)?(AddSe_Queue1(q1,&Num)):(AddSe_Queue1(q0,&Num));
	}

	while( (IsEmptySe_Queue1(q0)  != TRUE) && (IsEmptySe_Queue1(q1) != TRUE))
	{
		char c = (n == 1)?('\0'):(' ');
		if(n1) {
			printf("%d%c",DeleteSe_Queue1(q0),c);
			n1 --;
			n2 = (n1 == 0)?(Nb):(0);
		} else {
			printf("%d%c",DeleteSe_Queue1(q1),c);
			n2 --;
			n1 = (n2 == 0)?(Na):(0);	
		}
		n--;
	}

	while(n) {
		char c = (n == 1)?('\0'):(' ');
		if(IsEmptySe_Queue1(q0) != TRUE	) {
			printf("%d%c",DeleteSe_Queue1(q0),c);
		} else {
			printf("%d%c",DeleteSe_Queue1(q1),c);
		}
		n --;
	}
	putchar('\n');
}
