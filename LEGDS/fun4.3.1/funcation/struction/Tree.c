#include "Tree_in.h"
#include "Tree_out.h"

TreeNode* MakeTreeRoot(ElementTypeTree *Data) {
	TreeNode *tree = (TreeNode*) malloc (sizeof(TreeNode));

	tree -> Data = Data;
	tree -> Child[0] = NULL;

	return tree;
}

TreeNode* InsertTree(BinTreeNode* BST,ElementTypeTree *Data,Ch_Stack0 *stack) {
	TreeNode *re = (TreeNode*) malloc(sizeof(TreeNode));
	TreeNode *Father;

	BinTreeNode *BT;
	ElementTypeBT *DataBT;

	ElementTypeCh_Stack0 *Datastack;

	re -> Data = Data;
	re -> Child[0] = re -> Child[1] = NULL;
	Datastack = PopCh_Stack0(stack);

	DataBT = ElementBST(Datastack->Name,NULL);
	BT = FindBSTNode(BST,DataBT);
	Father = BT -> Data -> ptree;

	PushCh_Stack0(stack,Datastack);

	if(Father -> Child[0] != NULL) {
		TreeNode *P0 = Father -> Child[0];
		
		do{
			Father = P0;
			P0 = P0 -> Child[1];
		}while(P0);	

		Father -> Child[1] = re;
	} else {
		Father -> Child[0] = re;
	}

	return re;
}
ElementTypeBT* ElementBST(char *Value,TreeNode *ptree) {
	ElementTypeBT *DataBT = (ElementTypeBT*) malloc (sizeof(ElementTypeBT));

	DataBT -> ptree = ptree;

	for(int i = 0;Value[i] != '\0';i ++) {
		DataBT->Value[i] = Value[i];
	}

	return DataBT;
}
