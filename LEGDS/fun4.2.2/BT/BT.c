#include "BT_in.h"
#include "BT_out.h"

void SeqTrav(PtrToBinTreeNode BT) {
	Ch_Queue0 *q = MakeCh_Queue0();

	AddCh_Queue0(q,&BT);

	if(BT) {
		while((IsEmptyCh_Queue0(q) != TRUE)) {
			BT = DeleteCh_Queue0(q);

			OperatNode(BT);

			(BT -> Child[0] != NULL)?(AddCh_Queue0(q,&BT->Child[0])):(0);
			(BT -> Child[1] != NULL)?(AddCh_Queue0(q,&BT->Child[1])):(0);
		}
		printf("\n");
	} else {
		printf("Error:in the SeqTrav:BinTree is empty\n");
	}
}

void OperatNode(PtrToBinTreeNode p) {
	if(!(p->Child[0]) && !(p->Child[1])) {
		printf("%d ",p -> Data -> Value);
	}
}
