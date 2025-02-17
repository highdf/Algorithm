#include "fun4.2.1.h"

//用Data,N1,N2的描述方式生成
PtrToBinTreeNode CreatBT(FILE *fp) {
	BinTreeNode *re;
	int n;

	fscanf(fp,"%d",&n);
	if(n > 0) {
		Type0 T[n];
		int RootNum;

		for(int i = 0;i < n;i ++) {
			int a[3];
			fscanf(fp,"%d%d%d",&T[i].Data.Value,&T[i].Num[0],&T[i].Num[1]);
			//printf("%d %d %d\n",T[i].Data.Value,T[i].Num[0],T[i].Num[1]);

		//	fscanf(fp,"%d%d%d",&a[0],&a[1],&a[2]);
		//	printf("%d %d %d\n",a[0],a[1],a[2]);
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
		PtrElementTypeBT q = (ElementTypeBT*)malloc(sizeof(ElementTypeBT));
		re = (BinTreeNode*) malloc(sizeof(BinTreeNode));

		q -> Value = p[K].Data.Value; 
		re -> Data = q;
		re-> Child[0] = CtBT(p,p[K].Num[0]);
		re-> Child[1] = CtBT(p,p[K].Num[1]);
	} else {
		re = NULL;
	}
	return re;
}
