#include "fun3.3.2.h"

int main() {
	int N,M;
	Friend *p;
	Ch_ListNode0 *Head = MakeCh_ListHead0();
	FILE *fp = fopen("fun3.3.2.d","r");
	
	if(fp) {
		fscanf(fp,"%d%d",&N,&M);
		if(M > 0) {
			p = MakeFriend(M);
			Scan1(p,M,fp);
			Sort(p);
	//		Printf0(p);
	//		rt \n");
	//		Printf0(p);
		}
		if(N > 0) {
			Scan2(Head,N,fp);
			
		}
	
		if(M > 0) {
			CSHFriend(Head,p,N);
			free(p);
		}
		CL(Head,N);
	} else {
		printf("Don't open \"read\"\n");
	}

	return 0;
}

//funcation
int Str_Num(char *c,int n) {
	int sum = 0;
	
	for(int i = 0;i < n;i++) {
		sum = sum + (c[i] - 'A');
	}
	 
	return sum;
}
void Scan1(Friend* p,int n,FILE *fp) {

	for(int i = 0;i < n;i ++){
		int l;
		fscanf(fp,"%d",&l);
		p->Data[i] = MakeSe_List0(l);
		for(int j = 0;j < l;j ++) {
			char c[3];
			int Num;
			fscanf(fp,"%s",c);
			Num = Str_Num(c,3);
			p->Data[i] -> Data[j] = Num;
		}	
	}
}
Friend* MakeFriend(int n) {
	Friend *q = (Friend*) malloc(sizeof(Friend));

	if(q != NULL) {
		q -> Data = (PtrToSe_List0*)malloc(sizeof(PtrToSe_List0) * n);
		if((q->Data) != NULL) {
			q -> MaxSize = n;
		} else {
			printf("Make Se_List0 is error\n");
		}
	} else {
		printf("Make Se_List0 is error\n");
	}
	return q;
}
void Scan2(PtrToCh_ListHead0 p,int n,FILE *fp) {
	for(int i = 0;i < n;i ++) {
		Band Per;
		fscanf(fp,"%s",Per.Name);
		fscanf(fp,"%d",&(Per.Gtime));
		fscanf(fp,"%d",&(Per.Dtime));
		if(Per.Dtime > 60) {
			Per.Dtime = 60;
		}
		p -> PFriend = NULL;
		p = AttachCh_List0(p,&Per);
		
	}
}
//void Printf0(Friend *p) {
//	printf("Friend is result\n");
//	for(int i = 0;i < (p->MaxSize);i ++){
//		for(int j = 0;j < (p->Data[i]->MaxSize);j++) {
//			printf("%d ",p->Data[i]->Data[j]);
//		}
//		putchar('\n');
//	}
//}
//void Printf1(PtrToCh_ListHead0 p) {
//	p = p -> Next;
//
//	printf("Data is result\n");
//	while(p != NULL) {
//		printf("%s\t%d\t%d\n",p->Data.Name,p->Data.Gtime,p->Data.Dtime);
//		p = p -> Next;
//	}
//}
