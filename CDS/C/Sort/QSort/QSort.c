#include "QSort_in.h"
#include "QSort_out.h"

void QSort(int *Arr,int Len) {
	//判断无序组是否需要排序
	if(Len > 1) {
		//创建一个栈，用来存储递归过程中的问题信息
		Ch_Stack0 *stack = MakeCh_Stack0();

		//初始化栈,栈的元素由一个起始索引与长度构成,它表示一个无序子组
		int start = 0;
		ElementTypeCh_Stack0 *Data = ElementCh_Stack0(start,Len);
		PushCh_Stack0(stack,Data);

		do{
			//处理栈顶元素
			Data = PopCh_Stack0(stack);

			//对出栈的子组进行划分
			//返回划分后基元在子组中的索引
			int K = F0(&(Arr[Data->start]),Data->Len);

			//求划分之后子组中左/右子组的长度与起始索引
			//返回K的原因是便于求出左子组的长度
			int LeftLen = K;
			int RightLen = Data->Len - (1 + LeftLen);
			ElementTypeCh_Stack0 *Data0;

			//因为长度为1的组，一定是有序的，所以不需要入栈处理
			if(LeftLen > 1) {
				start = Data->start;
				Data0 = ElementCh_Stack0(start,LeftLen);
				PushCh_Stack0(stack,Data0);
			}

			//原因如上
			if(RightLen > 1) {
				start = Data->start + K + 1;
				Data0 = ElementCh_Stack0(start,RightLen);
				PushCh_Stack0(stack,Data0);
			}
		} while( (IsEmptyCh_Stack0(stack)) == FALSE);	//当栈为空时，处理完毕
	}

	Print(Arr,Len);
}

//对子组进行划分
int F0(int *Arr,int Len) {
	int K = 0;

	for(int i = 1;i < Len;i ++) {
		if(Arr[i] < Arr[K]) {
			for(int j = i;j > K;j --) {
				int t = Arr[j-1];
				Arr[j-1] = Arr[j];
				Arr[j] = t;
			}
			K ++;
		}
	}

	return K;
}
void Print(int *Arr,int Len) {
	for(int i = 0;i < Len;i ++) {
		char c = (i == (Len-1))?('\n'):(' ');
		printf("%d%c",Arr[i],c);
	}
}
//用来构造栈元素
ElementTypeCh_Stack0* ElementCh_Stack0(int start,int Len) {
	ElementTypeCh_Stack0* Data = (ElementTypeCh_Stack0*) malloc (sizeof(ElementTypeCh_Stack0));

	Data->start = start;
	Data->Len = Len;

	return Data;
}
