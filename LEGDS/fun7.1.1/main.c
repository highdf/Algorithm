#include "main.h"

int main() {
	int N,C;
	FILE *fp;

	fp = fopen("in","r");

	if(fp != NULL) {
		fscanf(fp,"%d %d",&N,&C);

		Table tab[N];
		int len[3] = {7,9,4};
		for(int i = 0;i < N;i ++) {
			for(int j = 0;j < 3;j ++) {
				tab[i].student[j] = (char*)malloc(sizeof(char) * len[j]);
				fscanf(fp,"%s",tab[i].student[j]);
				if(j == 2) {
					//将成绩字符串转化为右对齐，左边补0
					F0(tab[i].student[j]);
				}
			}	
		}

		MSort(tab,N,C);

		Print(tab,N);
	} else {
		printf("Error:In the main:");
		printf("file name is in error\n");
	}
	return 0;
}
//funcation
void F0(char *str) {
	int i,j;
	//找到字符结束符
	for(i = 0;str[i] != '\0';i ++) {
		;
	}

	//将字符串平移至右边
	for(j = 3;i >= 0;j --,i --) {
		str[j] = str[i];
	}

	//左边补0
	for(i = 0;i <= j;i ++) {
		str[i] = '0';
	}
}
void F1(char *str,char *grade)  {
	int i,j;

	//找到非零字符的索引
	for(i = 0;grade[i] == '0';i ++) {
		;
	}

	//将grade后续的字符写入str中
	for(j = 0;grade[i] != '\0';j ++,i ++) {
		str[j] = grade[i];
	}
}
void Print(Table *tab,int N) {
	printf("Number\tName\tGrade\n");
	char str[4];

	for(int i = 0;i < N;i ++) {
		printf("%s\t%s\t",tab[i].student[0],tab[i].student[1]);
		//将其转化为左对齐格式
		F1(str,tab[i].student[2]);
		printf("%s\n",str);
	}
}
