
//Data
typedef struct TreeElement{
	char Name[20];
	int num;
}ElementTypeTree;

//Type
typedef struct TreeNode{
	ElementTypeTree *Data;
	struct TreeNode *Child[2];
}TreeNode;
