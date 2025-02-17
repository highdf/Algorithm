#include "MSort_in.h"
#include "MSort_out.h"

void MSort(int *Arr,int Len) {
	int MerLen = 1;
			   
	while(MerLen < Len ) {
		printf("MaxLen = %d\n",MerLen);
		for(int i = 0;i < Len;i += MerLen*2) {
			int len = Len - i;	//求出剩余未合并元素的个数
		  	Merge(&Arr[i],MerLen,len);
		}

		//Print(Arr,Len);

		MerLen *= 2;
	}

  	//Print(Arr,Len);
}

void Merge(int *Arr,int MerLen,int Len) {
	//求出合并组的实际总长度
	int OverallLen = (Len >= (2*MerLen))?(2*MerLen):(Len);

	//当两个组都存在时，进行合并
	if(OverallLen > MerLen) {
		int fi = 0,si = MerLen;
		int end1 = MerLen,end2 = OverallLen;

		for(;fi < end1 && si < end2;) {
			if(Arr[fi] >= Arr[si]) {
				for(int j = si;j > fi;j --) {
					int t = Arr[j-1];
					Arr[j-1] = Arr[j];
					Arr[j] = t;
				}
				si ++;
				fi ++;
				//增加end1的原因是，组1的长度没有发生改变，因此，fi与end1需要同时增加
				end1 ++;
			} else {
				fi ++;
			}
		}
	}

	Print(Arr,OverallLen);
}
void Print(int *Arr,int Len) {

  	for(int i = 0;i < Len;i ++) {
		char c = (i == (Len-1))?('\n'):(' ');
		printf("%d%c",Arr[i],c);
 	}
}
