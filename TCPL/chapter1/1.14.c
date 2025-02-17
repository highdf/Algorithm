#include <stdio.h>

#define TRUE 1
#define FALSE 0

int IsChar(char w);
int IsA(char w);
void PrintTable(char (*Arr)[26]);
void Print(int n);

int main() {
	char Arr[2][26] = {0};
	char c;

	while( (c = getchar()) != EOF) {
		if(IsChar(c) == TRUE) {
			(IsA(c) == TRUE)?(Arr[1][c-'A']++):(Arr[0][c-'a']++);
		}
	}

	PrintTable(Arr);
	return 0;
}
//funcation
int IsChar(char w) {
	return ((w >= 'a' && w <= 'z') || (w >= 'A' && w <= 'Z'))?(TRUE):(FALSE);
}
int IsA(char w) {
	return (w >= 'A' && w <= 'Z')?(TRUE):(FALSE);
}
void PrintTable(char (*Arr)[26]) {
	for(int i = 0;i < 2; i++) {

		for(int j = 0; j < 26;j ++) {
			if(i == 0) {
				printf("%c ",j + 'a');
				Print(Arr[i][j]);
			} else {
				printf("%c ",j + 'A');
				Print(Arr[i][j]);

			}
		}
	}
}
void Print(int n) {
	for(int i = 0;i < n;i ++) {
		printf("*");
	}
	printf("\n");
}
