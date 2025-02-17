#include "fun3.3.2.h"

int BinSearch(Friend* p,int num) {
	status leap = FALSE;
	int i;
	
	for(i = 0;i < (p->MaxSize) && leap == FALSE;i ++) {
		int left = 0,right = (p->Data[i]->MaxSize-1);
		do{
			int btween = (left+right)/2;
			if(p->Data[i]->Data[btween] == num) {
				leap = TRUE;
			} if(p->Data[i]->Data[btween] > num) {
				right = btween - 1;
			} else {
				left = btween + 1;
			}
		}while(leap == FALSE && (left <= right));
	}
	 return (leap == TRUE)?(i-1):(-1);
}
void Sort(Friend *p) {
	int i,j,k;

	for(i = 0;i < (p->MaxSize);i ++) {
		for(j = 0;j < (p->Data[i]->MaxSize-1);j++) {
			int h = j,t;
			for(k=j+1;k < (p->Data[i]->MaxSize);k++) {
				if((p->Data[i]->Data[h]) > (p->Data[i]->Data[k])) {
					h = k;
				      }	
			}
			t = (p->Data[i]->Data[j]),p->Data[i]->Data[j] = (p->Data[i]->Data[h]),p->Data[i]->Data[h] = t;
		}
	}
}
void CSHFriend(PtrToCh_ListHead0 Head,Friend *q,int n) { 
	int w[n];
	Ch_ListNode0 *p;
	int i = 0;

	p = Head -> Next;
	while(p != NULL) {
		int num = Str_Num(p->Data.Name,3);
		w[i++] = BinSearch(q,num);
		p = p -> Next;
	}
//	for(i = 0;i < n;i++) 
//		printf("w[%d] = %d ",i,w[i]);

//	putchar('\n');

	p = Head -> Next;
	for(i = 0;i < n;i++,p=p->Next) {
		if(w[i] != -1) 	{
			int n = (q->Data[w[i]]->MaxSize-1);
			F0(w,i,p,n);
			w[i] = -1;
		}
	}
}

void F0(int *a,int i,PtrToCh_ListNode0 p0,int n) {
	Ch_ListNode0 *p1 = p0;
	int k = i + 1,j;

	while(n > 0) {
		for(j = k;a[j] != a[i]; j++) 
			;
//		printf("j = %d,i = %d\n",j,i);
		p1 -> PFriend = AccessCh_List0(p0,j-i);
		p1 = p1 -> PFriend;
		a[j] = -1;
		k = j+1;
		n --;
	}
}
void CL(PtrToCh_ListHead0 Head,int n) {
	int time = 0;
	double SumWait = 0;
	Ch_ListNode0 *p = Head -> Next;

	while(p != NULL) {
		Ch_ListNode0 *temp = p;
		if((time - (p->Data.Gtime)) > 0) { 
			SumWait += (time - (p->Data.Gtime));
		} else {
			time = p->Data.Gtime;
		}
		printf("%s\n",p->Data.Name);
		time += (p->Data.Dtime);
		if((p->PFriend) != NULL) {
			SumWait += (QCL(Head,p->PFriend,&(time)));
		}
		p = p -> Next;
		D(Head,temp);
	}
	printf("Wait time is %.1lf\n",SumWait/n);
}
void D(PtrToCh_ListHead0 p,PtrToCh_ListNode0 q) {
	while((p->Next) != q) {
		p = p -> Next;
	}
	p -> Next = q -> Next;
	free(q);
}
double QCL(PtrToCh_ListHead0 Head,PtrToCh_ListNode0 p,int *time) {
	double SumWait = 0;
	status Leap = FALSE;

	while(Leap == FALSE) {
		Ch_ListNode0 *temp = p;
		if((*time) >= (p->Data.Gtime)) {
			if(((*time) - (p->Data.Gtime)) > 0) {
				SumWait += ((*time) - (p->Data.Gtime));
			} else {
				(*time) = (p->Data.Gtime);
			}
			printf("%s\n",p->Data.Name);
			(*time) += (p->Data.Dtime);
			if((p->PFriend) != NULL) {
				p = p -> PFriend;
			} else {
				Leap = TRUE;
			}
			D(Head,temp);
		} else {
			Leap = TRUE;
		}
	}

	return SumWait;
}
