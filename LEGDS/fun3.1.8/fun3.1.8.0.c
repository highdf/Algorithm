#include "Ch_Stack3.1.8.0.h"
#include "Ch_List3.1.8.h"
#include <stdio.h>

void JS(PtrToCh_ListHead1 q);
PtrToCh_ListNode1 Jump1(PtrToCh_ListNode1 p);
status Op1(PtrToCh_Stack2 p,char w);
PtrToCh_ListNode1 GetNum(double *t,PtrToCh_ListNode1 q);
status Op_Double(PtrToCh_Stack2 p,char w);
status Op_One(PtrToCh_Stack2 p,char w);

//funcaton
void JS(PtrToCh_ListHead1 q) {
	status Leap = TRUE;
	Ch_Stack2 *p = MakeCh_Stack2();
	double Num;

	q = q -> Next;
	while(q -> Data != '=' && Leap != FALSE) {
		if( q -> Data == ' ') {
			q = q -> Next;
			q = Jump1(q);
		}

		if(q -> Data >= '0' && q -> Data <= '9') {
			double Num;
			q = GetNum(&Num,q);
			PushCh_Stack2(p,&Num);
		} else if(q -> Data != '=') {
			char w = q -> Data;
			Leap = Op1(p,w);
			q = q -> Next;
		
		}
	}

	if(Leap == TRUE) {
		printf("result is %.2lf \n",(p -> Top -> Data));
	} else {
		printf("ERROR\n");
	}

}
PtrToCh_ListNode1 Jump1(PtrToCh_ListNode1 p) {
	while(p != NULL && p -> Data  == ' ') {
		p = p -> Next;
	}
	
	return p;
}
PtrToCh_ListNode1 GetNum(double *t,PtrToCh_ListNode1 q) {
	double sum = 0;
	char c = q -> Data;
	double p = 1;
	status Leap1 = FALSE;

	while(c >= '0' && c <= '9' || c == '.') {
		if( c != '.') {
			int n = c - '0';
			(Leap1 == TRUE)? (p *= 0.1):(1);
			sum = sum * 10 + n;
		} else {
			Leap1 = TRUE;
		}
		q = q -> Next;
		c = q -> Data;
	}

	(*t) = sum * p;
	return q;
}
status Op_Double(PtrToCh_Stack2 p,char w) {
	double Num0,Num1;
	status Leap = TRUE;
	(IsEmptyCh_Stack2(p) == TRUE)?(Leap = FALSE):(Num1 = (p -> Top -> Data),PopCh_Stack2(p));
	(IsEmptyCh_Stack2(p) == TRUE)?(Leap = FALSE):(Num0 = (p -> Top -> Data),PopCh_Stack2(p));


	if(Leap == TRUE) {
		switch(w) {
			case '+':Num0 = Num0 + Num1;break;
			case '-':Num0 = Num0 - Num1;break;
			case '*':Num0 = Num0 * Num1;break;
			case '/':(Num0 = Num0 / Num1);break;
		}
	
			PushCh_Stack2(p,&Num0);
	}

	return Leap;
}
status Op1(PtrToCh_Stack2 p,char w) {
	char n;
	status Leap;

	switch(w) {
		case '+':n = 2;break;
		case '-':n = 2;break;
		case '*':n = 2;break;
		case '/':n = 2;break;
		case 'a':n = 1;break;
	}

	Leap = (n == 1)?(Op_One(p,w)):(Op_Double(p,w));

	return Leap;	
}
status Op_One(PtrToCh_Stack2 p,char w) {
	double n;
	status Leap =TRUE;

	(IsEmptyCh_Stack2(p) != TRUE)?(n = p -> Top -> Data,PopCh_Stack2(p)):(Leap =FALSE);

	if(Leap != FALSE) {
		switch(w) {
			case 'a':n *= -1;break;
		}
		PushCh_Stack2(p,&n);
	}

	return Leap;
}
