
//Data Declaratoin
typedef struct BTElement{
	char Value[20];
	TreeNode *ptree;
}ElementTypeBT;
typedef ElementTypeBT* PtrToElementTypeBT;

//Type Declaraton
typedef struct BinTreeNode{
	PtrToElementTypeBT Data;
	struct BinTreeNode *Child[2];
}BinTreeNode;

//General Declaration
typedef BinTreeNode* PtrToBinTreeNode;
