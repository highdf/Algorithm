#include "main.h"

int main() {
	int length;

	printf("Please enter a length\n");
	scanf("%d",&length);

	int arr[length];	
	printf("Please enter a ordered array\n");
	for(int i = 0;i < length;i ++) {
		scanf("%d",&arr[i]);
	}

	int match;
	printf("Please enter match\n");
	scanf("%d",&match);

	int re = BinSearch(arr,length,match);
	if(re >= 0) {
		printf("ordered_array[%d] = match\n",re);
	} else {
		printf("Don't find in the ordered_array\n");
	}
	// int re = BinSearch0(arr,0,length-1,match);
	//
	// if(re >= 0) {
	// 	printf("ordered_array[%d] = match\n",re);
	// } else {
	// 	printf("Don't find in the ordered_array\n");
	// }
	return 0;
}
