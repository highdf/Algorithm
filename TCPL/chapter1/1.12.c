#include <stdio.h>

#define OUT 1
#define IN 0

int main() {
	int state = OUT;
	char c;

	while( (c = getchar()) != EOF) {
		if(c == ' ' || c == '\t' || c == '\n') {
			(state == IN)?(state = OUT,putchar('\n')):(1);
		} else {
			putchar(c);
			(state == OUT)?(state = IN):(1);
		}
	}
}
