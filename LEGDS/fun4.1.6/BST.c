#include "fun4.1.6.h"

PtrToBinTreeNode InsertBST (PtrToBinTreeNode BT,ElementTypeBT *val) {
	if(BT) {
		BinTreeNode *Last;
		int i;
		while( BT != NULL) {
			if(strcmp(BT->Data->Name,val->Name) > 0) {
				Last = BT;
				i = 0;
				BT = BT -> Child[0];
			} else if(strcmp(BT->Data->Name,val->Name) <= 0) {
				Last = BT;
				i = 1;
				BT = BT -> Child[1];
			}
		}
		BT = (BinTreeNode*)malloc (sizeof(BinTreeNode));
		BT -> Data = val;
		BT -> Child[0] = BT -> Child[1] = NULL;
		Last -> Child[i] = BT;
	} else {
		BT = (BinTreeNode*)malloc (sizeof(BinTreeNode));
		BT -> Data = val;
		BT -> Child[0] = BT -> Child[1] = NULL;
	}
	 
	return BT;
}
PtrToBinTreeNode FindBST(PtrToBinTreeNode BT,char* Name) {
	if(BT) {
		while (BT) {
			if(strcmp(BT->Data->Name,Name) > 0) {
				BT = BT -> Child[0];
			} else if(strcmp(BT->Data->Name,Name) < 0) {
				BT = BT -> Child[1];
			} else {
				break;
			}
		}
	} else {
		printf("In the FindBST:This bintree is empty\n");
	}
	 
	return BT;
}
int strcmp(char *s1,char *s2) {
	int re;
	int i;
	int Leap = FALSE;	//标记循环推出的出口

	for(i = 0;(s1[i] != '\0') && (s2[i] != '\0');i++) {
		if(s1[i] != s2[i]) {
			Leap = TRUE;
			break;
		}
	}

	if(Leap == TRUE) {
		(s1[i] > s2[i])?(re = 1):(re = -1);
	} else {
		if(s1[i] == s2[i]) {
			re = 0;
		} else if(s1[i] == '\0') {
			re = -1;
		} else {
			re = 1;
		}
	}

	return re;
}
