#include "fun4.1.4.h"

int main() {
	int n,m;
	Heap *h;

	printf("Please enter N and M\n");
	scanf("%d%d",&n,&m);

	h = MakeHeap(n);
	printf("Please enter Data of Heap\n");
	for(int i = 0;i < n;i ++) {
		int num;
		scanf("%d",&num);
		InsertHeap(h,num);
	}
		
	int List[m];

	printf("Please enter indexes \n");

	for(int i = 0;i < m;i ++) {
		scanf("%d",&List[i]);
	}

	F1(h,List,m);
	return 0;
}
//funcation
void F0(Heap* h,int *List,int m) {
	for(int i = 0;i < m;i++) {
		//此层循环用来遍历路径起始索引数组
		for(int j = List[i];j <= (h->Size) && j != 0;j = j/2) {
			//从指定索引出发，遍历到哨兵为止
			printf("%d%c",h->Data[j],(j == 1)?('\n'):(' '));
		}
	}
}
void F1(Heap *h,int *List,int m){
	for(int i = 0;i < m;i ++) {
		int a[h -> Size];
		//用于存放一条路经结点的序号
		int j = 0;
		//求起点序号为1，终点序号为LIST【I】的路径上结点的序号
		do {
			a[j++] = List[i];
			List[i] /= 2;
		}while(List[i] != 0);
		//打印该路经上结点的DATA
		for(int k = j-1;k >= 0;k --) {
			printf("%d%c",h->Data[a[k]],(k == 0)?('\n'):(' '));
		}
	}	
}	
