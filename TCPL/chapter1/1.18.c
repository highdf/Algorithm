#include <stdio.h>

#define OVERFLOW -2

void Operat(char *str,int Len);
int GetLine(char *str,int n);
int main() {
	int Len,n = 20;
	char str[n];

	while( (Len = GetLine(str,n)) > 0) {
		Operat(str,Len);

		if(str[0] != '\0') {
			printf("%s\n",str);
		}
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
void Operat(char *str,int Len) {
	for(int i = Len-1;str[i] == ' ';i--) {
		str[i] = str[i+1];
	}
}
