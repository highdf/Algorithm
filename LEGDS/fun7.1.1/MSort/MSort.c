#include "MSort_in.h"
#include "MSort_out.h"

//-
void MSort(Table *Arr,int Len,int C) {
	int MerLen = 1;
			   
	while(MerLen < Len ) {
		//printf("MaxLen = %d\n",MerLen);
		for(int i = 0;i < Len;i += MerLen*2) {
			int len = Len - i;	//求出剩余未合并元素的个数
		  	Merge(&Arr[i],MerLen,len,C);
		}

		//Print(Arr,Len);

		MerLen *= 2;
	}

  	//Print(Arr,Len);
}
//-
void Merge(Table *Arr,int MerLen,int Len,int C) {
	//求出合并组的实际总长度
	int OverallLen = (Len >= (2*MerLen))?(2*MerLen):(Len);

	//当两个组都存在时，进行合并
	if(OverallLen > MerLen) {
		int fi = 0,si = MerLen;
		int end1 = MerLen,end2 = OverallLen;

		for(;fi < end1 && si < end2;) {
			int order = Order(Arr[fi].student[C],Arr[si].student[C]);
			if(order >= 0) {
				for(int j = si;j > fi;j --) {
					Table t = Arr[j-1];
					Arr[j-1] = Arr[j];
					Arr[j] = t;
				}

				if(order == 0 && Order(Arr[fi].student[0],Arr[fi+1].student[0]) > 0) {
					Table t = Arr[fi+1];
					Arr[fi+1] = Arr[fi];
					Arr[fi] = t;		
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

	//Print(Arr,OverallLen);
}
//+
int Order(char *s0,char *s1) {
	int re = 0;

	for(int i = 0;s0[i] != '\0' && s1[i] != '\0';i ++) {
		if(s0[i] < s1[i]) {
			re = -1;
			break;
		} else if(s0[i] > s1[i]) {
			re = 1;
			break;
		}
	}

	return re;
}
