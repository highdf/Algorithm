#include <stdio.h>
#include "Ch_List.h"
void Poly_Multp(PtrToCh_ListHead f1,PtrToCh_ListHead f2, PtrToCh_ListHead f3);
void S(PtrToCh_ListHead f1);

int main()
{
	Ch_List *f1,*f2,*f3;
	Ch_List *p3;
	f1 = MakeCh_ListHead();
	f2 = MakeCh_ListHead();
	f3 = MakeCh_ListHead();

	printf("Please to polynomial initialization\n");
	printf("number one\n");
	S(f1);
	printf("number two\n");
	S(f2);
	printf("result\n");
	if(IsEmptyCh_List(f1) != TRUE && IsEmptyCh_List(f2) != TRUE) {
		Poly_Multp(f1,f2,f3);
		p3 = f3 -> Next;
		while(p3 != NULL) {
			printf("%d %lf ",p3->Data.Freq,p3->Data.Coef);
			p3 = p3 -> Next;
			putchar('\n');
		}	
		putchar('\n');
	} else {
		printf("0\n");
	}

	return 0;
}
//funcation
void Poly_Multp(PtrToCh_ListHead f1,PtrToCh_ListHead f2, PtrToCh_ListHead f3) {
	Ch_List *p0,*p1,*p2;
	int k;
	
	k = (f1 -> Next -> Data . Freq) + (f2 -> Next -> Data . Freq);
	p2 = f3;
	while(k >= 0) {
		p0 = f1 -> Next;
		double sum = 0;

		while(p0 && (p0->Data.Freq) > k ) {
			p0 = p0 -> Next;
		}

		if(p0 != NULL) {
			while(p0) {
				p1 = f2 -> Next;
				int c = k - (p0->Data.Freq);

				while(p1 && c < (p1->Data.Freq)) {
					p1 = p1 -> Next;
				}

				if(p1 != NULL) {
					(p1 -> Data.Freq == c)?(sum += (p1->Data.Coef *p0->Data.Coef)):(0);
				}

				p0 = p0 -> Next;
			}
		} else {
			break;
		}
		if(sum != 0) {
			MakeCh_ListNode(f3);
			p2 = p2 -> Next;
			p2 -> Data.Freq = k;
			p2 -> Data.Coef = sum;
		}
		k --;
	}	
}
void S(PtrToCh_ListHead f1) {
	Ch_List *p1;
	int a;
	double b;
	p1 = f1;
	while(1) {
		scanf("%d",&a);
		if(a >= 0) {
			scanf("%lf",&b);
			MakeCh_ListNode(f1);
			p1 = p1 -> Next;
			p1 -> Data.Freq = a;
			p1 -> Data.Coef = b;
		} else {
			break;
		}
	}
}
