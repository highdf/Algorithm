#include "fun4.1.2.h"

status IsBST(PtrToBinTreeNode T);
int main() {
	BinTreeNode *p;
	int n;
	FILE *fp = fopen("in","r");

	p = CreatBT(fp);
	(IsBST(p) == TRUE)?(printf("This is binary tree\n")):(printf("This isn't binary tree\n"));
	return 0;
}
//funcation
status IsBST(PtrToBinTreeNode T) {
	status re;
	status Leap[3]; 
	//用于标记非空二叉树是否满足性质1～3
	
	//在递归中的转化条件是被判断树非空
	if(T) {
		BinTreeNode *pl,*pr;
		//用分支来判断非空二叉树是否满足性质1
		if((T->Child[0]) && (T->Child[1])) {

			pl = FindBSTMax(T->Child[0]);
			pr = FindBSTMin(T->Child[1]);
			((pl->Data) <= (T->Data) && (T->Data) <= (pr->Data))?(Leap[0] = TRUE):(Leap[0] = FALSE);
		} else if((T->Child[0])) {
			pl = FindBSTMax(T->Child[0]);
			((pl->Data) <= (T->Data))?(Leap[0] = TRUE):(Leap[0] = FALSE);
		} else if(T->Child[1]) {
			pr = FindBSTMin(T->Child[1]);
			((T->Data) <= (pr->Data))?(Leap[0] = TRUE):(Leap[0] = FALSE);
		} else {
			Leap[0] = TRUE;
		}
		//用递归来判断非空二叉树是否满足性质2和3
			Leap[1] = IsBST(T -> Child[0]);
			Leap[2] = IsBST(T -> Child[1]);
			re = Leap[0] && Leap[1] && Leap[2];
	} else {
		re = TRUE;
	}	

	return re;
}
PtrToBinTreeNode FindBSTMin(PtrToBinTreeNode BT) {
	if(BT) {
		while(BT -> Child[0]) {
			BT = BT -> Child[0];
		}
	} else {
		printf("In the FindLeftMin:This bintree is empty\n");
	}
	 
	return BT;
}
PtrToBinTreeNode FindBSTMax(PtrToBinTreeNode BT) {
	if(BT) {
		while(BT ->Child[1]) {
			BT = BT -> Child[1];
		}
	} else {
		printf("Error:In the FindBSTMax\n");
		printf("This tree is empty\n");
	}
	
	return BT;
}
