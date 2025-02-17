#include "QSort_in.h"
#include "QSort_out.h"

void QSort(int *Arr,int Len) {
	if(Len > 1) {
		Ch_Stack0 *stack = MakeCh_Stack0();

		int start = 0;
		ElementTypeCh_Stack0 *Data = ElementCh_Stack0(start,Len);
		PushCh_Stack0(stack,Data);

		do{
			Data = PopCh_Stack0(stack);

			int K = F0(&(Arr[Data->start]),Data->Len);
			int LeftLen = K;
			int RightLen = Data->Len - (1 + LeftLen);
			ElementTypeCh_Stack0 *Data0;

			if(LeftLen > 1) {
				start = Data->start;
				Data0 = ElementCh_Stack0(start,LeftLen);
				PushCh_Stack0(stack,Data0);
			}

			if(RightLen > 1) {
				start = Data->start + K + 1;
				Data0 = ElementCh_Stack0(start,RightLen);
				PushCh_Stack0(stack,Data0);
			}
		} while( (IsEmptyCh_Stack0(stack)) == FALSE);
	}

	Print(Arr,Len);
}

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
ElementTypeCh_Stack0* ElementCh_Stack0(int start,int Len) {
	ElementTypeCh_Stack0* Data = (ElementTypeCh_Stack0*) malloc (sizeof(ElementTypeCh_Stack0));

	Data->start = start;
	Data->Len = Len;

	return Data;
}
