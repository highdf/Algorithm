#include "Heap_Sort_in.h"
#include "Heap_Sort_out.h"

//-
void Heap_Sort(int *Arr,int Len,int M) {

	//将无序组组织为一个最大堆
	MakeHeap(Arr,Len);

	//通过堆的删除操作完成排序
	Conversion(Arr,Len,M);

	//Print(Arr,Len);
}
void MakeHeap(int *Arr,int Len) {
	for(int i = 1;i < Len;i ++) {
		//当前的数组索引
		int ci = i;
		//将其映射为堆索引
		int ciheap = ci + 1;

		do{
			//父结点的堆索引
			int piheap = ciheap / 2;
			//映射为数组索引
			int pi = piheap - 1;

			//比较是否需要调整
			if(Arr[ci] > Arr[pi]) {
				int temp = Arr[ci];
				Arr[ci] = Arr[pi];
				Arr[pi] = temp;
			} else {
				break;
			}

			//更新当前的数组索引,堆索引
			ci = pi;
			ciheap = piheap;
		}while(ciheap > 1);
	}
}
//-
void Conversion(int *Arr,int Len,int M) {

	//当堆的大小大于1时，使用删除来排序
	while(Len > 1 && M > 0) {
		//记录当前堆中的起始索引与末尾索引
		int start = 0;
		int last = Len-1;

		//交换起始与末位元素，完成一次删除,更新len的值
		{
			int temp = Arr[start];
			Arr[start] = Arr[last];
			Arr[last] = temp;
			Len --;
			M --;
		}

		//从起始元素开始，对堆进行调整
		{ 
			//pi指向在调整中被处理的元素
			//初始化
			int pi = start;

			do{
				//lefti指向当前的左子结点
				int lefti = pi + 1;

				//判断lefti的合法性
				if(lefti < Len) {
					//指向当前的右子结点
					int righti = lefti + 1;
					//指向左/右子结点中的最大者
					//初始化为lefti
					int maxi = lefti;

					//判断右子结点的合法性
					if(righti < Len) {	
						//判断并更新maxi的值
						(Arr[righti] > Arr[lefti])?(maxi = righti):(1);
					}
					
					if(Arr[pi] < Arr[maxi]) {	//判断大小关系并调整
						int t = Arr[pi];
						Arr[pi] = Arr[maxi];
						Arr[maxi] = t;	
					} else {  //无需调整，推出循环

						break;
					}

					//更新当前被处理的结点
					pi = maxi;
				} else {
					//lefti不合法，则无需调整
					break;
				}
			}while(1);
		}
	}			
}
