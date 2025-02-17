#include "fun4.1.1.h"

int main() {
	int n;

	printf("Please enter n\n");
	scanf("%d",&n);

	if( n > 0){ 
		int Mid[n],Beh[n];
		ScanArr(Beh,n);
		ScanArr(Mid,n);
		OpTree(Mid,Beh,n);
	} else {
		printf("This Tree is Empty\n");
	}

	return 0;
}
//funcation
void ScanArr(int *Arr,int n) {
	int i = 0;

	for(;i < n;i ++) {
		scanf("%d",&Arr[i]);
	}
}
int FindArr(int *Arr,int n,int D) {
	int i;
	for( i = 0;Arr[i] != D;i ++) {
		;
	}

	return i;
}
void CreatNode(PtrToSe_Stack0 Ps,int start0,int start1,int n) {
	//创建递归树的结点
	ElementTypeSe_Stack0 T;
	T.Start[0] = start0;
	T.Start[1] = start1;
	T.n = n;

	PushSe_Stack0(Ps,&T);
}
void OpTree(int *Mid,int *Beh,int n) {
	//由中序，后序生成对应树的先序。
	int Count = n;
	//用来记录打印的次数，实现打印格式控制
	int start[2] = {0,0};
	Se_Stack0 *Ps = MakeSe_Stack0(2 * n + 1);
	//递归树拥有的结点数是中/后序长度的2*N倍左右

	CreatNode(Ps,start[0],start[1],n);
	//创建第一个结点

	printf("Preorder ");
	do{
		ElementTypeSe_Stack0 T = PopSe_Stack0(Ps);
		//处理处于栈顶的结点
		if(T.n > 0) {
			//判断该结点是否满足转化条件
			int K,LNum,RNum;
			//用于求左/右子树的结点数，存储的是ROOT在中序列的序号
			int End = (T.Start[1] + T.n) - 1;
			//求结点对应的后序列尾项的序号
			int Root = Beh[End];
			//求根结点的值
			printf("%d%c",Root,(Count != 1)?(' '):('\n'));
			//打印先序结果
			Count --;
			K = FindArr(&Mid[T.Start[0]],T.n,Root);
			//求根结点在当前中序列中的序号
//			K += T.Start[0];
			//将其转化为初始中序列中的序号
//			LNum = K - T.Start[0];
//			LNUm = K;
			RNum = T.n - 1 -LNum;
			//求转化后左/右子树的结点数
			if(RNum > 0) {
				start[0] = K + 1;
				start[1] = T.Start[1] + LNum;
			} else {
				start[0] = start[1] = 0;
			}	
			CreatNode(Ps,start[0],start[1],RNum);
			CreatNode(Ps,T.Start[0],T.Start[1],LNum);
			//完成转化，并入栈
		}
		//挡不能转化时，操作集为空
	}while(IsEmptySe_Stack0(Ps) == FALSE);
}
void Print(int *Arr,int n) {
	//检查读入的数据列是否正确。
	for(int i = 0;i < n;i ++ ) {
		printf("%d",Arr[i]);
	}
	printf("\n");
}
