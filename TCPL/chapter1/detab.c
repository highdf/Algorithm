#include <stdio.h>

#define TABLEN 8
#define MAXLINE 30
        
int main() {
	int i = 0;
	char str[MAXLINE],c;

	while( (c = getchar()) != EOF) {
		if(c == '\t') {
			int space = TABLEN - (i % TABLEN);
			for(;space > 0;space --) {
				str[i++] = ' ';
			}	
		} else if(c == '\n') {
			str[i] = '\0';
			printf("%s\n",str);
			i = 0;
		} else {
			str[i++] = c;
		}
	}

	return 0;
}
//funcation

