#include "main.h"

int main() {
	int length;

	printf("Please neter length of array\n");
	scanf("%d",&length);

	int arr[length];
	printf("Please enter element of array\n");
	for(int i = 0;i < length;i ++) {
		scanf("%d",&arr[i]);
	}

	printf("Please enter number of circular left shift\n");
	int count;
	scanf("%d",&count);

	printf("Circular left shift %d after\n",count);
	CircularLeftShift(arr,length,count);

	for(int i = 0;i < length;i ++) {
		char separator = (i == (length-1))?('\n'):(' ');
		printf("%d%c",arr[i],separator);
	}
	return 0;
}
