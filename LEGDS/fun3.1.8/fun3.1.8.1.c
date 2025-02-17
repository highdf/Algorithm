#include <stdio.h>
#include "Ch_List3.1.8.h"
#include "status.h"
#include "Ch_Stack3.1.8.h"

//Global Variable
Ch_ListNode1 *p0,*p1;
char u = 0;

//funcation Declaration
void JS(PtrToCh_ListHead1 q);
status Validation(PtrToCh_ListHead1 p);
void F0(void);
void F2(PtrToCh_Stack1,char w,char n);
char F1(void);
void Op(PtrToCh_Stack1 h);
void Get(void);
void Jump(void);

int main() {
	status Leap;
	Ch_ListNode1 *Head0,*Head1;

	Head0 = MakeCh_ListHead1();
	Head1 = MakeCh_ListHead1();

	printf("Please enter... \n");
	Leap = Validation(Head0);

//	printf("%d\n",Leap);
	if(Leap == TRUE) {
			p0 = Head0 -> Next;
			p1 = Head1;
			F0();
			
//			p1 = Head1;
//			p1 = p1 -> Next;
//			while( p1 != NULL) {
//				printf("%c",p1 -> Data);
//				p1 = p1 -> Next;
//			}
			JS(Head1);
	}

	return 0;
}
//funcation
status Validation(PtrToCh_ListHead1 p) {
	char w;
	int i = 1;
	status Leap1 = FALSE;
	status Leap0 = FALSE;
	status Leap[2];

	Leap[0] = TRUE;
	while( (w = getchar()) != '=' && Leap1 != TRUE) {
		if(w == ' ') {
			;
		} else if(w >= '0' && w <= '9') {
			if(Leap0 == TRUE) {
				(w == '0')?( Leap1 = TRUE):(1);
				Leap0 = FALSE;
			}
			if( Leap1 == FALSE) {
				p = InsertCh_List1(p,&w);
			}
		} else if(w != '=') {
			switch(w) {
				case '+':Leap[1] =FALSE;break;
				case '-':((Leap[0] | Leap[1]) != 0)?(w = 'a'):(1);break;
				case '*':Leap[1] = FALSE;break;
				case '/':Leap0 = TRUE;Leap[1] = FALSE;break;
				case '(':Leap[1] = TRUE;break;
				case ')':Leap[1] = FALSE;break;
				case '.':Leap[1] = FALSE;break;
				default:Leap1 = TRUE;
		}
			Leap[0] = FALSE;
			if( Leap1 == FALSE) {
				p = InsertCh_List1(p,&w);
			}
		}
	} 

	w = '=';
	if( Leap1 == FALSE) {
		p = InsertCh_List1(p,&w);
	}
		
	return (Leap1 == TRUE)?(FALSE):(TRUE);
}
void F0(void) {
	Ch_Stack1 *h = MakeCh_Stack1();
	char s;

	while(p0 -> Data != '=') {

		if(p0 -> Data >= '0' && p0 -> Data <= '9' || p0 -> Data == '.') {
			Get();
		} else if(p0 -> Data != '=') {
			Op(h);	
		}
	}
	
	while( IsEmptyCh_Stack1(h) != TRUE) {
		 s = h -> Top -> Data.w;
		p1 = InsertCh_List1(p1,&s);
		PopCh_Stack1(h);
		s = ' ';
		p1 = InsertCh_List1(p1,&s);
	}
	s = '=';
	p1 -> Data = s;
}

//funcation1
void Get(void) {
	char w;
	do{
		w = p0 -> Data;
		p1 = InsertCh_List1(p1,&w);
		p0 = p0 -> Next;
	}while(p0 -> Data >= '0' && p0 -> Data <= '9' || p0 -> Data == '.');
	w = ' ';
	p1 = InsertCh_List1(p1,&w);
	
}
void Op(PtrToCh_Stack1 h) {

	if((p0 -> Data == '(') || (p0 -> Data == ')')) {
		(p0 -> Data == '(')?(u += 5):(u -= 5);
	} else {
		char n = F1();
		while( IsEmptyCh_Stack1(h) == FALSE && (h->Top->Data.n) >= n) {
			char d = h->Top->Data.w;
			p1 = InsertCh_List1(p1,&d);
			d = ' ';
			p1 = InsertCh_List1(p1,&d);
			PopCh_Stack1(h);
		}
		F2(h,p0->Data,n);
	}
	p0 = p0 -> Next;
}
char F1(void) {
	char t = p0 -> Data;
	char n;

	switch(t) {
		case '+':n = u ;break;
		case '-':n = u ;break;
		case '*':n = u + 1;break;
		case '/':n = u + 1;break;
		case 'a':n = u + 2;break;
	}
	
	return n;
}
void F2(PtrToCh_Stack1 h,char w,char n) {
	T0 r;
	r.w = w;
	r.n = n;
	
	PushCh_Stack1(h,&r);
}
