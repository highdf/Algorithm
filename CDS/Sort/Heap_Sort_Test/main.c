#include "main.h"

int main() {
	int Len;

	printf("Please enter Arr's Length\n");
	scanf("%d",&Len);

	int Arr[Len];

	printf("Please enter Arr's element\n");
	for(int i = 0;i < Len;i ++) {
		scanf("%d",&Arr[i]);
	}

	Heap_Sort(Arr,Len);

	return 0;
}
