#include "main.h"

int main() {
	int N,M;
	Heap *heap;
	ElementTypeHeap *Data;
	FILE *fp;

	fp = fopen("in","r");
	fscanf(fp,"%d",&N);
	
	fscanf(fp,"%d ",&M);

	if(N > 0 && M > 0) {
		heap = MakeHeap(N);
		for(int i = 0;i < N;i++) {
			int val;
			fscanf(fp,"%d ",&val);
			Data = MakeElementHeap(val);
			InsertHeap(heap,Data);
		}


		status TrueValue[M];
		for(int i = 0;i < M;i ++) {
			char *str;
			getstr(str,fp);
			TrueValue[i] = Operat(str,heap);
		}

		printf("Result\n");
		for(int i=0;i < M;i ++) {
			printf("%c%c",(TrueValue[i] == TRUE)?('T'):('F'),(i == (M-1))?('\n'):(' '));
		}
	} else {
		printf("N or M is error\n");
	}

	
	return 0;
}
//funcation
void getstr(char *str,FILE *fp) {
	int i;
	for(i = 0;TRUE;i ++) {
		fscanf(fp,"%c",&str[i]);	
		if(str[i] == '\n') {
			str[i] = '\0';
			break;
		}
	}

}
