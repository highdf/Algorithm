#include "f1_in.h"
#include "f1_out.h"

status Operat(BinTreeNode *BST,char *str,TreeNode *tree) {
	status Label;
	int Type;
	char re[2][20];

	TreeNode *TreeX,*TreeY;
	Type = Is(str,re);

//	printf("Type = %d\n",Type);
//	printf("re[0] = %s,re[1] = %s\n",re[0],re[1]);
	TreeX = FindTreeNode (BST,re[0]);
	TreeY = FindTreeNode (BST,re[1]);
//	printf("TreeX = %d,TreeY = %d\n",TreeX->Data->num,TreeY->Data->num);
//	printf("TreeX = %s,TreeY = %s\n",TreeX->Data->Name,TreeY->Data->Name);

	switch(Type) {
		case 0:Label = Method0(TreeX,TreeY);break; 
		case 1:Label = Method1(TreeX,TreeY);break;
		case 2:Label = Method2(TreeX,TreeY);break;
		case 3:Label = Method3(TreeX,TreeY);break;
		case 4:Label = Method4(TreeX,TreeY);break;
	}

	return Label;
}
int Is(char *str,char (*re)[20]) {
	int result;
	char sent[5][MAXLINE] = { {"* is a child of *"},
				  {"* is the parent of *"},
				  {"* is a sibling of *"},
				  {"* is a descendant of *"},
				  {"* is an ancestor of *"},
				};

	for(int i = 0; i < 5;i ++) {
		int stri = 0,senti = 0;
		int rei = 0,rej = 0;

		for(;sent[i][senti] != '\0' && str[stri] != '\0';stri++,senti++) {
			if(sent[i][senti] == '*') {
				stri = GetName(&str[stri],re[rei++]) + stri;
				stri --;
			} else if(sent[i][senti] != str[stri]) {
				break;
			}
		}

		if(sent[i][senti] == '\0' && str[stri] == '\0') {
			result = i;
			break;
		}
		//printf("str[i] %c,sent[i] %c \n",str[stri],sent[i][senti]);

	}

	return result;
}
TreeNode* FindTreeNode (BinTreeNode *BST,char *str) {
	ElementTypeBT *DataBT;
	TreeNode *re;

	DataBT = ElementBST(str,NULL);
	BST = FindBSTNode(BST,DataBT);

	re = BST -> Data -> ptree;

	return re;
}

status Method0(TreeNode *Tree0,TreeNode *Tree1) {
	status re = (((Tree0->Data->num)-1) == (Tree1->Data->num))?(TRUE):(FALSE);

	return re;
}
status Method1(TreeNode *Tree0,TreeNode *Tree1) {
	return ((Tree0->Data->num+1) == (Tree1->Data->num))?(TRUE):(FALSE);
}
status Method2(TreeNode *Tree0,TreeNode *Tree1) {
	return ((Tree0->Data->num) == (Tree1->Data->num))?(TRUE):(FALSE);
}
status Method3(TreeNode *Tree0,TreeNode *Tree1) {
	return ((Tree0->Data->num) > (Tree1->Data->num+1))?(TRUE):(FALSE);
}
status Method4(TreeNode *Tree0,TreeNode *Tree1) {
	return ((Tree0->Data->num) < (Tree1->Data->num-1))?(TRUE):(FALSE);
}
int GetName(char *str,char *re) {
	int i;
	for(i = 0;IsChar(str[i]) == TRUE;i++) {
		re[i] = str[i];
	}
	re[i] = '\0';

	return i;
}
status IsChar(char c) {
	return ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))?(TRUE):(FALSE);
}
