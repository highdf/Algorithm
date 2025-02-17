#include "fun4.2.7_in.h"
#include "fun4.2.7_out.h"

int F0(Heap *heap,int n) {
	ElementTypeHeap Data = DeleteHeap(heap);
	int re = 0;

	while ( n > (Data.Value)) {
		re += n;
		n -= Data.Value;
		Data = DeleteHeap(heap);
	}

	return re;
}
