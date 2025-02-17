#include <stdio.h>

#define MAXLINE 1000
#define OVERFLOW -1

int GetLine(char *str);
void Print(char *Arr);
int main() {
	char str[MAXLINE];
	int Len;
	
	while ((Len = GetLine(str)) > 0) {
		printf("%d\n",Len);
		if(Len > 10) {
			Print(str);
		}
	}
	return 0;
}
//funcation
int GetLine(char *str) {
	int i;
	char c;
	
	c = getchar();
	for(i = 0;(i < MAXLINE) && (c  != '\n') && (c != EOF);i++) {
//		printf("i = %dc = %c\n ",i,c);
		str[i] = c;
		c = getchar();
	}

//	printf("c = %d",c);
	if(c == '\n') {
		str[i] = '\0';
	} else if(c == EOF) {
		i = EOF;
	} else {
		i = OVERFLOW;
	}

	return i;
}

void Print(char *Arr) {
	for(int i = 0;Arr[i] != '\0';i++) {
		printf("%c",Arr[i]);
	}
	printf("\n");
}
