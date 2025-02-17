#include "main.h"

int main() {
	Heap *heap;
	ElementTypeHeap *Data;
	int N;
	FILE *fp;

	fp = fopen("in","r");

	if(fp) {
		int Length = 0;
		fscanf(fp,"%d ",&N); 
		heap = MakeHeap(N);

		for(int i = 0;i < N;i ++) {
			int val;
			fscanf(fp,"%d ",&val);
			Length += val;
			Data = MakeElementHeap(val);
			InsertHeap (heap,Data);
		}

		printf("result is\n%d\n",F0(heap,Length));
	} else {
		printf("in is empty\n");
	}
	return 0;
}
//funcation
ElementTypeHeap* MakeElementHeap(int val) {
	ElementTypeHeap *Data = (ElementTypeHeap*)malloc (sizeof(ElementTypeHeap));

	Data -> Value = val;

	return Data;
}
