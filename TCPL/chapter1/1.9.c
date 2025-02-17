#include <stdio.h>

int main() {
	char c;
	char Label = 0;

	while((c = getchar()) != EOF) {
		if(c != ' ') {
			putchar(c);
			(Label == 1)?(Label = 0):(1);
		} else if(Label == 0) {
			putchar(c);
			Label = 1;
		}
	}
	printf("the ehd\n");
	return 0;
}
