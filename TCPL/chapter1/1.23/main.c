#include "main.h"

int main() {
	char str[MAXTEXT];
	int Len;
	char fname[10];
	FILE *fp;

	printf("Please enter open file's name\n");
	scanf("%s",fname);

	fp = fopen(fname,"r");

	if(fp) {
		Len = GetText(fp,str,MAXTEXT);

		if(Len > 0) {
			annotation(str,Len);
			Print(str);
		} else {
			printf("Read Text is error\n");
		}

		fclose(fp);
	} else {
		printf("open this file is false\n");
	}
	return 0;
}
