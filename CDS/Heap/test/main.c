#include "main.h"

ElementTypeHeap* ElementHeap(int i);

int main() {
	Heap *Heap = MakeHeap(10);
	ElementTypeHeap *Data;

	for(int i = 0;i < 10;i ++) {
		Data = ElementHeap(i);
		InsertHeap(Heap,Data);
	}
	StatusHeap(Heap,0);

	for(int i = 1;i <= (Heap->Size);i ++) {
		printf("Heap->Data[%d]->Value = %d\n",i,Heap->Data[i]->Value);
	}

	for(int i = 0;i < 10;i ++) {
		Data = DeleteHeap(Heap);
		free(Data);
	}
	StatusHeap(Heap,0);

	for(int i = 0;i < 10;i ++) {
		Data = ElementHeap(i);
		InsertHeap(Heap,Data);
	}
	StatusHeap(Heap,0);

	for(int i = 1;i <= (Heap->Size);i ++) {
		printf("Heap->Data[%d]->Value = %d\n",i,Heap->Data[i]->Value);
	}

	for(int i = 0;i < 10;i ++) {
		Data = DeleteHeap(Heap);
		free(Data);
	}
	StatusHeap(Heap,0);
	return 0;
}
ElementTypeHeap* ElementHeap(int i) {
	ElementTypeHeap *Data = (ElementTypeHeap*) malloc (sizeof(ElementTypeHeap));
	Data->Value = i;

	return Data;

}
