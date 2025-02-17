#include "main.h"

int main() {
	int N,M;
	FILE *fp;

	fp = fopen("in","r");

	if(fp) {
		fscanf(fp,"%d%d",&N,&M);

		int arr[N];

		for(int i = 0;i < N;i ++) {
			fscanf(fp,"%d",&arr[i]);
		}

		Heap_Sort(arr,N,M);

		for(int i = N-1;i >= 0 && i >= N-M;i --) {
			char c = (i == 0 || i == N-M)?('\n'):(' ');
			printf("%d%c",arr[i],c);
		}
	} else {
		printf("Error;In the main:");
		printf("file name is in error\n");
	}
	return 9;
}
//funcation

