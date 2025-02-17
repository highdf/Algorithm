#include "main.h"

int main() {
	int a,n;

	printf("Please enter the first element\n");
	scanf("%d",&a);

	printf("Please enter number of sum\n");
	scanf("%d",&n);

	int sum;
	sum = ArraySum(a,n);
	printf("Result of sum = %d\n",sum);

	int *arr = ArraySum0(a, n);

	if(arr[n] > 0) {
		printf("%d",arr[n]);
	}
	for(int i = n-1;i >= 0;i --) {
		char c = (i == 0)?('\n'):('\0');
		printf("%d%c",arr[i],c);	
	}

	int *arr0 = ArraySum1(a, n);

	if(arr0[n] > 0) {
		printf("%d",arr0[n]);
	}
	for(int i = n-1;i >= 0;i --) {
		char c = (i == 0)?('\n'):('\0');
		printf("%d%c",arr0[i],c);	
	}
	return 0;
}
