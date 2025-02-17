#include <stdio.h>

int main() {
	char c;

	while( (c = getchar()) != EOF) {
		if(c == '\t') {
			putchar('\\');
			putchar('t');
		} else if(c == '\b'){
			putchar('\\');
			putchar('b');
		} else {
			putchar(c);
		}
	}
	return 0;
}
