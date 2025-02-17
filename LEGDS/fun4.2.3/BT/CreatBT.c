#include "CreatBT_in.h"
#include "CreatBT_out.h"

//用Data,N1,N2的描述方式生成
PtrToBinTreeNode CreatBT(FILE *fp) {
	BinTreeNode *re;
	int n;
	if(fp) {
		fscanf(fp,"%d",&n);
	}

	if(n > 0) {
		Type0 T[n];
		int RootNum;

		for(int i = 0;i < n;i ++) {
			WriteData(&T[i],fp);
			fscanf(fp,"%d %d ",&T[i].Num[0],&T[i].Num[1]);
		}
	
		RootNum = FindRoot(T,n);
		re = CtBT(T,RootNum);
	} else if(n == 0) {
		re = NULL;
	} else {
	
		re = NULL;
		printf("n is error\n");
	}

	return re;
}
int FindRoot(Type0 *p,int n) {
	int i;
	int Leap[n];

	for(i=0;i < n;i ++ ) {
		Leap[i] = 0;
	}
	for(i = 0;i < n;i ++) {
		for(int j = 0;j < 2;j ++) {
			if(p[i].Num[j] != -1) {
				Leap[p[i].Num[j]] = 1;
			}
		}
	}

	for(i = 0;Leap[i] == 1;i++)
		;

	return i;	
}
BinTreeNode* CtBT(Type0 *p,int K) {
	BinTreeNode *re;
	if(K >= 0) {
		re = (BinTreeNode*) malloc(sizeof(BinTreeNode));
		re-> Data = p[K].Data;
		re-> Child[0] = CtBT(p,p[K].Num[0]);
		re-> Child[1] = CtBT(p,p[K].Num[1]);
	} else {
		re = NULL;
	}
	return re;
}
void WriteData(Type0 *P,FILE *fp) {
	ElementTypeBT *p = (ElementTypeBT*)malloc (sizeof(ElementTypeBT));
	fscanf(fp,"%d ",&p->Value);

	P->Data = p;
}
