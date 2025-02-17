#include "main.h"

int main() {
	int Len;

	printf("Please enter length of array\n");
	scanf("%d",&Len);

	int Arr[Len];

	printf("Please enter element of array\n");
	for(int i = 0;i < Len;i ++) {
		scanf("%d",&Arr[i]);
	}	

	QSort(Arr,Len);

	return 0;
}
