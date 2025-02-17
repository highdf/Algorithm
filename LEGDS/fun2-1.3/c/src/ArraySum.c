#include "ArraySum_in.h"
#include "ArraySum_out.h"

int ArraySum(int a,int n) {
	int sum = 0;
	int A = a;

	for(int i = 0;i < n;i ++) {
		sum += A;
		A = A * 10 + a;
	}

	return sum;
}
int* ArraySum0(int a,int n) {
	int *re = (int *) malloc (sizeof(int) * (n+1));
	int *A = (int *) malloc(sizeof(int) * n);

	for(int i = 0;i < n+1;i ++) {
		re[i] = 0;
		(i == n)?(0):(A[i] = 0);
	}

	for(int i = 0;i < n;i ++) {
		int j = 0;
		int carry = 0;
		A[i] = a;

		for(;j <= i;j ++) {
			int current = ( A[j] + re[j] + carry) % 10;
			// printf("j = %d,A[j] = %d,re[j] = %d\n",j,A[j],re[j]);
			// printf("current = %d,carry = %d\n",current,carry);
			// printf("A[j] + re[j] = carry = %d\n",A[j]+re[j]+carry);
			carry = (A[j] + re[j] + carry) / 10;
			re[j] = current;
		}
		re[j] = carry;

	}

	free(A);

	return re;
}
int* ArraySum1(int a,int n) {
	int *re = (int *) malloc (sizeof(int) * (n+1));
	int *A = (int *) malloc (sizeof(int) * n);

	int carry = 0;
	for(int i = 0;i < n; i ++) {
		int current = ( (n - i) * a + carry) % 10;
		carry = ( (n-i)*a + carry) / 10;
		re[i] = current;
	}
	re[n] = carry;

	return re;
}
