#include "fun4.2.5_in.h"
#include "fun4.2.5_out.h"

status Operat(char *str,Heap *heap) {
	int result[3];	//用于存储命题类型判断函数的返回值，0号，1号分别存放命题中的数
			//3号用于存放命题的类型值
	status re;

	Is(str,result);

	switch(result[2]) {
		case 0:re = Method_0(heap,result[0]);break;
		case 1:re = Method_1(heap,result[0],result[1]);break;
		case 2:re = Method_2(heap,result[0],result[1]);break;
		case 3:re = Method_3(heap,result[0],result[1]);break;
	}

	return re;
}
void Is(char *str,int *re) {
	char *answer[4];

	//枚举命题所有一般形式
	answer[0] = "x is the root";
	answer[1] = "x and y are siblings";
	answer[2] = "x is the parent of y";
	answer[3] = "x is a child of y";

	//遍历每一类命题，
	for(int i = 0;i < 4;i ++ ) {
		int d = 0;
		int j=0,k=0;

		//将每一类命题与stt进行匹配
		for(;answer[i][j] != '\0' && str[k] != '\0';j ++,k++) {
			if( (IsNum(str[k])) && (IsXorY(answer[i][j])) ) {
				//转化str中的数，并更新最新的索引k
				k = getNum(&str[k],&re[d++]) + k;
				k --;
			} else if(answer[i][j] != str[k]) {
				break;
			}
		}

		//判断是否匹配成功
		if((answer[i][j] == '\0') && (str[k] == '\0')) {
			re[2] = i;
			break;
		}
	}

}
status IsNum(char s) {
	status re;

	if( (s >= '0') && (s <= '9') ) {
		re = TRUE;
	} else if(s == '-') {
		re = TRUE;
	} else {
		re = FALSE;
	}

	return re;
}
status IsXorY(char s) {
	return ( (s == 'x') || (s == 'y'))?(TRUE):(FALSE);
}
status Method_0(Heap *heap,int val) {
	return (heap->Data[1].Value == val)?(TRUE):(FALSE);
}
status Method_1(Heap *heap,int val0,int val1) {
	int i0,i1;
	status re;

	i0 = FindHeap(heap,val0) / 2;
	i1 = FindHeap(heap,val1) / 2;

	re = (i0 == i1)?(TRUE):(FALSE);

	return re;
}
status Method_2(Heap *heap,int val0,int val1) {
	int i0,i1;

	i0 = FindHeap(heap,val0);
	i1 = FindHeap(heap,val1);

	return ( (i1/2) == (i0))?(TRUE):(FALSE);
}
status Method_3(Heap *heap,int val0,int val1) {
	int i0,i1;

	i0 = FindHeap(heap,val0);
	i1 = FindHeap(heap,val1);

	return ( (i0/2) == i1)?(TRUE):(FALSE);
}
int FindHeap(Heap *heap,int val){
	int i = 0;
	for(;(i <= (heap->Size)); i++ ) {
		if(heap->Data[i].Value == val) {
			break;
		}	
	}
	
	return i;
}
ElementTypeHeap* MakeElementHeap(int val){
	ElementTypeHeap *Data = (ElementTypeHeap*) malloc (sizeof(ElementTypeHeap));
	Data -> Value = val;

	return Data;	
}
int getNum(char *str,int *re) {
	int sum = 0;
	int i = 0;
	int sign = (str[i] == '-')?(i++,-1):(1);

	for(;(IsNum(str[i])) == TRUE;i ++){
		sum = sum * 10 + (str[i] - '0');
	}

	sum = sign * sum;
	*re = sum;

	return i;
}
