#include "main.h"

int main() {
	int Len;
	FILE *fp;
	char fname[10];

	printf("Please neter name of file\n");
	scanf("%s",fname);

	fp = fopen(fname,"r");

	fscanf(fp,"%d",&Len);
  	int array[Len];

 	for(int i = 0;i < Len;i ++) {
		fscanf(fp,"%d",&array[i]);
 	} 

	Print(array,Len);

	MSort(array,Len);

	//Print(array,Len);

 	return 0;
}

