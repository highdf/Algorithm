#include "main.h"

int main() {
	FILE *fp;
	int Len;
	char fname[10];
	char text[MAXTEXT];

	printf("Please enter file name\n");
	scanf("%s",fname);

	fp = fopen(fname,"r");
//	Len = GetText(fp,text,MAXTEXT);
//
//	if(fp && Len > 0) {
//		Operat(text,Len);
//		PiPei(text);
//
//		fclose(fp);
//	} else if(!fp && Len < 0) {
//		printf("open the %s is false\n",fname);
//		printf("Read %s text is false\n",fname);
//	} else if(!fp) {
//		printf("open the %s is false\n",fname);
//	} else {
//		printf("Read %s text is false\n",fname);
//	}
//
	if(fp) {
		Len = GetText(fp,text,MAXTEXT);
		Operat(text,Len);
		PiPei(text);

		fclose(fp);

	}
	return 0;
}

