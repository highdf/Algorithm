#include "fun4.1.6.h"

int main() {
	int n;
	FILE *fp;		//用于指向存放输入的文件

	fp = fopen("in","r");

	if(fp) {
		BinTreeNode *T = NULL;
		fscanf(fp,"%d",&n);
		if(n > 0) { 
			char *Name;
			int i;
			ElementTypeBT *p = (ElementTypeBT*)malloc(sizeof(ElementTypeBT));
			
			fscanf(fp,"%s",Name);
			p = CreatElement(Name);
	//		for(i = 0;Name[i] != '\0';i++) {
	//			p -> Name[i] = Name[i];
	//		}
	//		p -> Name[i] = '\0';
	//		p -> Count = 1;
	//		T = InsertBST(T,p);
			T = InsertBST(T,p);

			for(int i = 1;i < n;i ++) {
				fscanf(fp,"%s",Name);
				F0(T,Name);
			}
			Print(T,n);
		} else {
			printf("Error:In the main:n is error\n");
		}
	} else {
		printf("Error:in the main:In file is empty\n");
	}
	return 0;
}
//funcation
void F0(PtrToBinTreeNode T,char *Name) {
	BinTreeNode *q;		//用于存放进行查找操作后的结果

	if((q = FindBST(T,Name)))  {
		q -> Data -> Count++;	
	} else {
		ElementTypeBT *p;
		p = CreatElement(Name);
		InsertBST(T,p);
	}
}
void Print(BinTreeNode *B,int n) {
	if(B) {
		Print(B->Child[0],n);
		printf("%s %.6lf%%\n",B->Data->Name,((double)B->Data->Count/n)*100);
		Print(B->Child[1],n);
	}
}
ElementTypeBT* CreatElement(char *Name) {
	int i;

	ElementTypeBT *p = (ElementTypeBT*)malloc(sizeof(ElementTypeBT));
	for(i = 0;Name[i] != '\0';i++) {
		p -> Name[i] = Name[i];
	}
	p -> Name[i] = '\0';
	p -> Count = 1;

	return p;
}
