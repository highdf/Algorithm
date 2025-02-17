#include <stdio.h>

#define OVERFLOW -2

int GetLine(char *str,int n);
void reverse(char *str,int Len);
int main() {
	int Len,n = 40;
	char str[n];

	while( (Len = GetLine(str,n)) > 0) {
		reverse(str,Len);
		printf("%s\n",str);
	}

	return 0;
}
//funcation
int GetLine(char *str,int n) {
	int i = 0;
	char c;

	for(;(c = getchar()) != '\n' && (c != EOF) && (i < n); i++) {
		str[i] = c;
	}

	if(c == '\n') {
		str[i] = '\0';
	} else if(c == EOF) {
		i = EOF;
	} else {
		i = OVERFLOW;
	}

	return i;
}
void reverse(char *str,int Len) {
	for(int i = 0,j = Len -1;i < j;i++,j--) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
