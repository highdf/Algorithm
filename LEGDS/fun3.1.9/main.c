#include "Se_Queue.h"
#include <stdio.h>

int main() {
	Se_Queue_Num *q = MakeSe_Queue_Num(4);
	int n = 3;
	int a,b;

	scanf("%d%d",&a,&b);
	Pop(q,&n);
	StatusSe_Queue_Num(q,0);
	n = Eject(q);
	StatusSe_Queue_Num(q,0);
	printf("n = %d\n",n);
	printf("a%%b = %d\n",a%b);
	return 0;
}
