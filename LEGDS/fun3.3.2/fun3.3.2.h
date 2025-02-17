#include "Se_List.h"
#include "Ch_List.h"
#include "status.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Friend{
		PtrToSe_List0 *Data;
		int MaxSize;
}Friend;

int Str_Num(char *c,int n);

void Scan1(Friend* p,int n,FILE *fp);

Friend* MakeFriend(int n);

void Scan2(PtrToCh_ListHead0 p,int n,FILE *fp);

int BinSearch(Friend* p,int Num);

void Printf0(Friend *p);

void Printf1(PtrToCh_ListHead0 p);

void Sort(Friend *p);

void F0(int *a,int i,PtrToCh_ListNode0 p0,int n);

void CSHFriend(PtrToCh_ListHead0 p,Friend *q,int N);

void CL(PtrToCh_ListHead0 Head,int n);

void D(PtrToCh_ListHead0 p,PtrToCh_ListNode0 q);

double QCL(PtrToCh_ListHead0 Head,PtrToCh_ListNode0 p,int *time);
