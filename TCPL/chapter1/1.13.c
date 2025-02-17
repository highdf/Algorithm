#include <stdio.h>

#define OUT 1
#define IN 0
#define LENGTH 10

void PrintTable(int *Arr,int Max);
int main() {
	int Arr[LENGTH],Len = 0;
	int Label = OUT;
	char c;
	int Max = 0;

	for(int i = 0;i < LENGTH;i ++) {
		Arr[i] = 0;
	}

	while( (c  =getchar()) != EOF) {
		if( (c=='\n') || (c==' ') || (c=='\r')) {
			if(Label == IN) {
				Label = OUT;
				Arr[Len] ++;
				(Max < Arr[Len])?(Max = Arr[Len]):(0);
				Len = 0;
			}
		} else {
			(Label == OUT)?(Label = IN):(0);
			Len ++;
		}
	}

//	for(int i = 0;i < LENGTH;i ++) {
//		printf("%d%c",Arr[i],(i == (LENGTH-1))?('\n'):(' '));
//	}
	PrintTable(Arr,Max);
	return 0;
}
//funcation
//void PrintTable(int *Arr) {
//	for(int i = 0;i < LENGTH;i ++) {
//		printf("Length = %d\t",i);
//		if(Arr[i] != 0) {
//			for(int j = 0;j < Arr[i];j ++) {
//				printf("*");
//			}
//		} else {
//			printf("#");
//		}
//		printf("\n");
//	}
//}
void PrintTable(int *Arr,int Max) {
	for(int i = 0;i < LENGTH;i ++) {
		printf("%d%c",i,(i == LENGTH-1)?('\n'):('\t'));
	}

	for(int j = 0;j < Max;j ++) {

		for(int i = 0; i < LENGTH;i ++) {
			if(Arr[i] > 0) {
				printf("*");
			}
			printf("%c",(i == LENGTH-1)?('\n'):('\t'));
		}
	}

}
