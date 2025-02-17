//Data Declaratoin
typedef struct {
	int Value;
}ElementTypeBT;
typedef ElementTypeBT* PtrToElementTypeBT;

//Type Declaraton
typedef struct BinTreeNode{
	PtrToElementTypeBT Data;
	struct BinTreeNode *Child[2];
}BinTreeNode;

//General Declaration
typedef BinTreeNode* PtrToBinTreeNode;

//Declaration
