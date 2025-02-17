#include <stdio.h>

#define MAXLINE 100
#define TABSIZE 8

int F0(char *str,int n);
int main() {
	char c;
	char str[MAXLINE];
	int i = 0,Len = 0;

	while( (c = getchar()) != EOF) {
		if( c != '\n') {
			if((Len != 0) && (Len % TABSIZE == 0) ) {
				printf("this i = %d\n",i);
				(str[i-1] == ' ')?(i -= (F0(str,i)-1)):(0);
				printf("before i = %d\n",i);
			}

			str[i++] = c;
			(c == '\t')?(Len = Len+(TABSIZE-(Len%TABSIZE))):(Len++);
		} else {
			str[i] = '\0';
			//printf("i = %d\n",i);
			printf("%s\n",str);
			i = 0;
			Len = 0;
		}
	}
	return 0;
}
//funcation
int F0(char *str,int n) {
	int j;

	for(j = 2;j < 9;j ++) {
		if(str[n-j] != ' ') {
			break;
		}
	}

	str[n-j+1] = '\t';

	return j - 1;
}
