#include "fun4.2.1.h"

int main() {
	BinTreeNode *P0,*P1;
	FILE *fp;

	fp = fopen("in","r");

	if(fp) {
		status ret;
		P0 = CreatBT(fp);
		P1 = CreatBT(fp);
		ret = IsIsom(P0,P1);

		(ret == TRUE)?(printf("Yes\n")):(printf("NO\n"));
	} else {
		printf("Error:In the main:in is empty\n");
	}
	return 0;
}
//funcation
status IsIsom(PtrToBinTreeNode BT0,PtrToBinTreeNode BT1) {
	status re;

	if( (BT0 && BT1) && (IsEqualsNode(BT0,BT1) == TRUE)) {
		status Leap[3];

		Leap[0] = IsIsom(BT0->Child[0],BT1->Child[0]);
		Leap[1] = IsIsom(BT0->Child[1],BT1->Child[1]);
		Leap[2] = Leap[0] && Leap[1];

		Leap[0] = IsIsom(BT0->Child[0],BT1->Child[1]);
		Leap[1] = IsIsom(BT0->Child[1],BT1->Child[0]);
		Leap[0] = Leap[0] && Leap[1];

		re = Leap[0] || Leap[2];
	} else {
		re = FALSE;
	}

	return re;
}
status IsEqualsNode(PtrToBinTreeNode p0,PtrToBinTreeNode p1){
	return ((p0->Data->Value) == (p1->Data->Value));
}
