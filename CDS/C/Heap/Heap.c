#include "Heap_in.h"
#include "Heap_out.h"

PtrToHeap MakeHeap (int Size) {
	Heap *p = (Heap*) malloc (sizeof(Heap));

	if(p) {
		p -> Data = (PtrToElementHeap*) malloc(sizeof(PtrToElementHeap) * (Size + 1));
		if(p -> Data) {
			p -> Size = 0;
			p -> MaxSize = Size;
		} else {
			p = NULL;
			printf("Error:In the MeakHeap :");
			printf("Info -> Malloc is false\n");
		}
	} else {
		printf("Error:In the MeakHeap :");
		printf("Info -> Malloc is false\n");
	}

	return p;
}
status IsEmptyHeap(PtrToHeap p) {
	return (p -> Size == 0)?(TRUE):(FALSE);
}
status IsFullHeap(PtrToHeap p) {
	return ((p->Size) == (p->MaxSize))?(TRUE):(FALSE);
}
status InsertHeap(PtrToHeap p,ElementTypeHeap *Data) {
	status re;
	if( IsFullHeap(p) == FALSE) {
		int i = ++ (p->Size);	//用于存放被处理子节点的序号
		p -> Data[i] = Data;

		do {
			int h = i/2;	//用于被处理子节点的上级节点的序号
			if(FLAG == LARGE) { 
			//根据标记执行不同的行为
				if(h > 0 && Order(p,i,h) > 0) {
			//若为大堆，则判断H是否合法同时是否满足调整条件
					PtrToElementHeap temp = p->Data[h];
					p->Data[h] = p->Data[i];
					p->Data[i] = temp;
					i = h;
				} else {
					break;
				}
			} else {
			//则为小堆
				if(h > 0 && Order(p,i,h) < 0) {
					PtrToElementHeap temp = p->Data[h];
					p->Data[h] = p->Data[i];
					p->Data[i] = temp;
					i = h;
				} else {
					break;
				}
			}
		} while(1);
		re = TRUE;
	} else {
		re = FALSE;
		printf("Error:In the InsertHeap :");
		printf("Info -> Heap is Full\n");
	}
	return re;
}
PtrToElementHeap DeleteHeap(PtrToHeap p) {
	PtrToElementHeap re = p -> Data[1];

	if(IsEmptyHeap(p) == FALSE) {
		p -> Data[1] = p -> Data[p->Size --];
		int i = 1; 	//用于存放被处理节点的序号	

		do{
			int c0 = 2 * i,c1 = c0 + 1;
			//用于存放被处理节点的下级节点序号
			if(FLAG == LARGE){ 
				if(c0 <= (p->Size)) {
					if(c1 <= (p->Size)) {
						(Order(p,c0,c1) > 0)?(0):(c0 = c1);	
						//让C0指向两个结点中的最大者
					}
					if(Order(p,i,c0) < 0) {
						PtrToElementHeap temp;
						temp = p->Data[i];
						p->Data[i] = p->Data[c0];
						p->Data[c0] = temp;
						i = c0;	
					} else {
						break;
					}
				} else {
					break;
				}
			} else {
			//则为小堆
				if(c0 <= (p->Size)) {
					if(c1 <= (p->Size)) {
						(Order(p,c0,c1) < 0)?(0):(c0 = c1);	
						//让C0指向两个结点中的最大者
					}
					if(Order(p,i,c0) > 0) {
						PtrToElementHeap temp;
						temp = p->Data[i];
						p->Data[i] = p->Data[c0];
						p->Data[c0] = temp;
						i = c0;	
					} else {
						break;
					}
				} else {
					break;
				}
			}
		} while(1);
	} else {
		printf("Error:In the DeleteHeap :");
		printf("Info -> Heap is Empty\n");
	}
	return re;
}
void StatusHeap(PtrToHeap p,int n) {
	//需要指向堆的指针和其序号
	printf("Heap %d is status\n",n);
	printf("\tSize is %d\n\tMaxSize is %d\n",p->Size,p->MaxSize);
}
int Order(Heap *p,int i,int j) {
	int re = 0;

	if(p->Data[i]->Value > p->Data[j]->Value) {
		re = 1;
	} else if(p->Data[i]->Value < p->Data[j]->Value) {
		re = -1;
	}

	return re;
}
