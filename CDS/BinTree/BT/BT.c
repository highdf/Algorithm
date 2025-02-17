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

void PreorderTrav(PtrToBinTreeNode BT) {
	
	if(BT) {	
		Ch_Stack0 *stack = MakeCh_Stack0();
		ElementTypeCh_Stack0 *Data;

		Data = MakeCh_StackData0(BT,FALSE);
		PushCh_Stack0(stack,Data);

		do{
			BinTreeNode *q = PopCh_Stack0(stack)->Value;

			while(q) {
				OperatNode(q);
				if(q->Child[1]) {
					Data  = MakeCh_StackData0(q->Child[1],FALSE);
					PushCh_Stack0(stack,(Data));
				}
				q = q->Child[0];
			}
		}while((IsEmptyCh_Stack0(stack)) == FALSE);

		printf("\n");
	} else {
		printf("Error:In the PreorderTrav:");
		printf("the BinTree is empty\n");
	}

}
void InorderTrav(PtrToBinTreeNode BT) {
	if(BT) {
		Ch_Stack0 *stack = MakeCh_Stack0();
		ElementTypeCh_Stack0 *Data;
		status Leap;
		
		do{
			do{

				if(BT->Child[1]) {
					Data = MakeCh_StackData0(BT->Child[1],FALSE);
					PushCh_Stack0(stack,Data);
				}

				Data = MakeCh_StackData0(BT,FALSE);
				PushCh_Stack0(stack,Data);

				BT = BT -> Child[0];
			}while(BT);

			while((IsEmptyCh_Stack0(stack)) == FALSE) {
				Leap = FALSE;
				BT = (PopCh_Stack0(stack)->Value);
				OperatNode(BT);

				if(BT->Child[1]) {
					Leap = TRUE;
					break;
				}
			}

			if(Leap == FALSE) {
				break;
			} else{
				BT = (PopCh_Stack0(stack)->Value);
			}
		}while(1);	
		printf("\n");
	} else {
		printf("Error:In the InorderTrav:");
		printf("The BinTree is empty\n");
	}
}
void PostorderTrav(PtrToBinTreeNode BT) {
	if(BT) {
		Ch_Stack0 *stack = MakeCh_Stack0();
		ElementTypeCh_Stack0* Data;
		status Leap;
		
		do{
			do{

				if(BT->Child[1]) {
					Data = MakeCh_StackData0(BT->Child[1],FALSE);
					PushCh_Stack0(stack,Data);
				}

				Data = MakeCh_StackData0(BT,FALSE);
				PushCh_Stack0(stack,Data);

				BT = BT -> Child[0];
			}while(BT);

			while((IsEmptyCh_Stack0(stack)) == FALSE) {
				Leap = FALSE;
				Data = PopCh_Stack0(stack);
				BT = Data->Value;

				if(BT->Child[1] && Data->Leap == FALSE) {
					PopCh_Stack0(stack);
					Data = MakeCh_StackData0(BT,TRUE);
					PushCh_Stack0(stack,Data);

					Leap = TRUE;
					break;
				} else {
					OperatNode(BT);
				}
			}

			if(Leap == FALSE) {
				break;
			} else{
				BT = BT -> Child[1];
			}
		}while(1);	

		printf("\n");
	} else {
		printf("Error:In the PostorderTrav:");
		printf("The BinTree is empty\n");
	}
}
void OperatNode(PtrToBinTreeNode p) {
	printf("%d ",p -> Data -> Value);
}
ElementTypeCh_Stack0* MakeCh_StackData0(BinTreeNode *BT,status Leap) {
	ElementTypeCh_Stack0 *p = (ElementTypeCh_Stack0*) malloc (sizeof(ElementTypeCh_Stack0));
	p -> Value = BT;
	p -> Leap = Leap;

	return p;
}
