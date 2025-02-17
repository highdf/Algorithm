#include "BST_in.h"
#include "BST_out.h"
#include <stdio.h>

PtrToBinTreeNode MakeBSTRoot(ElementTypeBT *val) {
	BinTreeNode *BT = (BinTreeNode*)malloc (sizeof(BinTreeNode));
	BT -> Data = val;
	BT -> Child[0] = BT -> Child[1] = NULL;

	return BT;
}
PtrToBinTreeNode InsertBSTNode (PtrToBinTreeNode BT,ElementTypeBT *val) {
	if(BT) {
		BinTreeNode *Last;
		int i;
		while( BT != NULL) {
			if(Order(BT->Data,val) >= 0) {
				Last = BT;
				i = 0;
				BT = BT -> Child[0];
			} else if(Order(BT->Data,val) < 0) {
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
		printf("Error:In the InsertBSTNode:");
		printf("BST is empty\n");
	}

	return BT;
}
PtrToBinTreeNode FindBSTNode(PtrToBinTreeNode BT,ElementTypeBT* val) {
	if(BT) {
		while (BT) {
			if(Order(BT->Data,val) > 0) {
				BT = BT -> Child[0];
			} else if(Order(BT->Data,val) < 0) {
				BT = BT -> Child[1];
			} else {
				break;
			}
		} 
		if(!BT) {
			printf("Error:In the FindBST: Not found x in the bintree\n");
		}
	} else {
		printf("Error:In the FindBST:This bintree is empty\n");
	}

	return BT;
}
PtrToBinTreeNode FindBSTMix(PtrToBinTreeNode BT) {
	if(BT) {
		while(BT -> Child[0]) {
			BT = BT -> Child[0];
		}
	} else {
		printf("Error:In the FindBSTMix:This bintree is empty\n");
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
PtrToBinTreeNode DeleteBSTNode(PtrToBinTreeNode BT,ElementTypeBT* Value) {
	//不能删除某子树的根节点
	if(BT) {
		BinTreeNode *K = (BinTreeNode*) malloc(sizeof(BinTreeNode));
		BinTreeNode *P = K;
		int i;			//存放D节点上级节点的索引	
		K -> Child[0] = BT;   	//创建临时节点，并连接
		i = FindDNode(&P,Value);//找VALUE所在的上级节点地址，索引。	
		if( i != -1) {		//判断D节点是否存在。
			//此时P指向D节点的上级节点
			int Deg = 0; 	//存放D节点的度数
			int l;		//存放D节点度数为1时，拥有分支的索引
			for(int j = 0;j < 2;j ++) {
				(P -> Child[i] -> Child[j] != NULL)?(l = j,Deg ++):(0);
			}

			switch(Deg) {
				case 0:Method_0(P,i);break;
				case 1:Method_1(P,i,l);break;
				case 2:Method_2(P->Child[i]);break;
			}
			BT = K -> Child[0];	//刷新根节点的地址

		} else {
			printf("Cann't;In the DaleteBinTreeNode\n");
			printf("Not Found Node \n");
		}
	} else {
		printf("Error:In the DalatBinTreeNode\n");
		printf("BinTree is empty\n");
	}

	return BT;	//返回删除后，被操作树的根地址。
}
int FindDNode(PtrToBinTreeNode *BT,ElementTypeBT* val) {
	//查找特征值是val的结点的上级结点
	BinTreeNode *P0,*P1;
	int i = 0;				//用于存放D节点上级节点的索引

	P1 = *BT;				//获取临时节点地址
	P0 = P1 -> Child[0];	//获取根节点的地址

	while(P0) {
		if(Order(P0->Data,val) > 0) {
			P1 = P0;
			P0 = P0 -> Child[0];
			i = 0;
		} else if(Order(P0->Data,val) < 0) {
			P1 = P0;
			P0 = P0 -> Child[1];
			i = 1;
		} else {
			break;
		}
	}

	(P0 == NULL)?(i = -1):(0);	//判断循环退出的情况
	*BT = P1;
	return i;
}
void Method_0(PtrToBinTreeNode P,int i) {
	BinTreeNode *temp = P -> Child[i];

	P -> Child[i] = NULL;
	free(temp);
}
void Method_1(PtrToBinTreeNode P,int i,int l) {
	BinTreeNode *temp = P -> Child[i];
	P -> Child[i] = temp -> Child[l];
	free(temp);
}
void Method_2(PtrToBinTreeNode P) {
	BinTreeNode *temp = FindBSTMix(P -> Child[1]);
	ElementTypeBT *D = temp -> Data;
	P = DeleteBSTNode(P,temp->Data);
	P -> Data = D;
}
//整数序
int Order(ElementTypeBT *Data0,ElementTypeBT *Data1) {
	int re = 0;

	if(Data0->Value > Data1->Value) {
		re = 1;
	} else if(Data0->Value < Data1->Value) {
		re = -1;
	}

	return re;
}
//字符序
//int Order(ElementTypeBT *Data0,ElementTypeBT *Data1) {
//	char s1 = Data0->Value,s2 = Data1->Value;
//	int re;
//	int i;
//	int Leap = FALSE;	//标记循环推出的出口
//
//	for(i = 0;(s1[i] != '\0') && (s2[i] != '\0');i++) {
//		if(s1[i] != s2[i]) {
//			Leap = TRUE;
//			break;
//		}
//	}
//
//	if(Leap == TRUE) {
//		(s1[i] > s2[i])?(re = 1):(re = -1);
//	} else {
//		if(s1[i] == s2[i]) {
//			re = 0;
//		} else if(s1[i] == '\0') {
//			re = -1;
//		} else {
//			re = 1;
//		}
//	}
//
//	return re;
//}
