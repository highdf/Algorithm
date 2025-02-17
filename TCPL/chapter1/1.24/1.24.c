#include "1.24_in.h"
#include "1.24_out.h"

void PiPei(char *text) {
	int Lable0 = OUT,Lable1 = OUT;
	status Lable[3] = {FALSE,FALSE,FALSE};
	int ti = 0;
	int c[3] = {0,0,0};

	while(text[ti] != EOF) {
		if(Lable1 == OUT && text[ti] == '\'') {
			//printf("front = %c\n",text[ti-1]);
			(Lable0 == OUT)?(Lable0 = IN):(Lable0 = OUT);
		} else if(Lable0 == OUT && text[ti] == '"') {
			//printf("front = %c\n",text[ti-1]);
			(Lable1 == OUT)?(Lable1 = IN):(Lable1 = OUT);
		}

		if(Lable0 == OUT && Lable1 == OUT) {
			switch (text[ti]) {
				case '{':c[0] ++;break;
				case '(':c[1] ++;break;
				case '[':c[2] ++;break;
				case '}':if(c[0] == 0) {
						Lable[0] = TRUE;
					} else {
						c[0] --;
					}
					break;
				case ')':if(c[1] == 0) {
						 Lable[1] = TRUE;
					} else {
						c[1] --;
					}
					break;
				case ']':if(c[2] == 0) {
						 Lable[2] = TRUE;
					} else {
						c[2] --;
					}
					break;
				
			}
		}
		ti ++;


	}

	if(c[0] && Lable[0] == FALSE) {
		Lable[0] = TRUE;
	} else if(c[1] && Lable[1] == FALSE) {
		Lable[1] = TRUE;
	} else if(c[2] && Lable[2] == FALSE) {
		Lable[2] = TRUE;
	}

	if(Lable[0] == TRUE) {
		printf("'{' is false\n");
	} 
	if(Lable[1] == TRUE) {
		printf("'(' is false\n");
	} 
	if(Lable[2] == TRUE) {
		printf("'[' is false\n");
	} 
}
