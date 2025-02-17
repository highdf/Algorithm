#include <stdio.h>
#include "permutationf_le_to_ri.h"
#include "status.h"
void P(PtrToArray num,PtrToArray op,ArraySize n);
void f1(PtrToArray num,PtrToArray op,ArraySize n,PositionToZero l);
double jisuan(PtrToArray num,ArraySize n,PtrToArray op);

int m;
status Leap = FALSE;

int main() {
	int n;
	printf("Please enter the number of numbers\n");
	printf("Please enter result\n");
	scanf("%d%d",&n,&m);

	int a[n];
	int i;
	printf("Please enter the number of sets\n");
	for(i = 0;i < n;i ++) {
		scanf("%d",&a[i]);
	}
	PermutationF_Le_To_Ri(a,n,0,n-1);
	(Leap == FALSE)?(printf("find not\n")):(1);

	return 0;
}
//funcation
void PermutationF_Le_To_Ri(PtrToArray a,ArraySize Length,PositionToZero Left,PositionToZero Right) {
	int Len;
	
	Len = (Right - Left) + 1;

	if(Leap == TRUE) {

	} else if(Len == 1) {
		int op[Length-1];
		f1(a,op,Length-1,0);
	} else {
		int i;
		int Temp;
		for(i = Left;i <= Right;i ++) {
			Temp = a[i],a[i]= a[Left],a[Left] = Temp;
			PermutationF_Le_To_Ri(a,Length,Left+1,Right);
			Temp = a[i],a[i]= a[Left],a[Left] = Temp;
		}
	}
}
void f1(PtrToArray num,PtrToArray op,ArraySize n,PositionToZero l) {
	char c[4] = {'+','-','*','/'};
	int i;

	if(Leap == TRUE) {
	} else if(n == l) {
		double re;
		re = jisuan(num,n+1,op);
		(re == m)?(P(num,op,n),Leap = TRUE):(Leap = FALSE);
	} else {
		for(i = 0;i < 4;i ++) {
		op[l] = c[i];
		f1(num,op,n,l+1);
		}
	}
}
double jisuan(PtrToArray num,ArraySize n,PtrToArray op) {
	double num1,num2;
	char op1;
	int i,j;

	i = 0,j = 0;
	num1 = num[i++];

	while(i < n) {
		num2 = num[i++];
		op1 = op[j++];
		switch(op1) {
			case '+':num1 += num2;break;
			case '-':num1 -= num2;break;
			case '*':num1 *= num2;break;
			case '/':num1 /= num2;break;
		}
	}
	return num1;

}
void P(PtrToArray num,PtrToArray op,ArraySize n) {
	int i;

	for(i = 0;i < n;i ++) {
		printf("(");
	}
	printf("%d",num[0]);
	for(i = 0;i < n;i ++) {
		printf("%c%d)",op[i],num[i+1]);
	}
	putchar('\n');
}
