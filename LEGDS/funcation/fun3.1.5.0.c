#include <stdio.h>
#include "status.h"
void F(void);

int main()
{
	printf("Please enter code\n");

	F();[
	]

	return 0;
}
//funcation
void F(void) {
	char w;
	int op1,op2,op3,op4;
	status Leap0 = TRUE;

	op1 = op2 = op3 = op4 = 0;

	while( (w = getchar()) != EOF) {
		if(w == '\n') {
			if(op3 != 0) {
				(op3 > 0)?(printf("[ ~ Right\n")):(printf("Left ~ ]\n"));
				op3 = 0;
				Leap0 = FALSE;
			}
		}
		switch(w) {
			case '(':op1 ++;break;
			case ')':op1 --;break;
			case '{':op2 ++;break;
			case '}':op2 --;break;
			case '[':op3 ++;break;
			case ']':op3 --;break;
		}
	}
	if(op1 != 0 || op2 != 0 || Leap0 != TRUE) {
		printf("no\n");
		(op1 > 0)?(printf("( ~ Right\n")):(printf("Left ~ )]\n"));
		(op2 > 0)?(printf("{ ~ Right\n")):(printf("Left ~ }]\n"));
	} else {
		printf("yes\n");
	}
		
}
