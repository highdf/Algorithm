#include "main.h"

void Print(BinTreeNode *tree);
int main() {
	TreeNode *tree = NULL;
	int N,M;
	FILE *fp;

	fp = fopen("in","r");

	if(fp) {
		char str[MAXLINE];
		status TrueValue[M];
		BinTreeNode *BST = NULL;

		fscanf(fp,"%d %d ",&N,&M);
		tree = CreatTree(&BST,fp,N);

		for(int i = 0;i < M;i ++) {
			Getline(str,fp);
			TrueValue[i] = Operat(BST,str,tree);	
		}

		for(int i = 0;i < M;i ++) {
			char c = (TrueValue[i] == TRUE)?('T'):('F');
			printf("%c%c",c,(i == M-1)?('\n'):(' '));
		}
	} else {
		printf("The in is empty\n");
	}

	return 0;
}
//funcation

