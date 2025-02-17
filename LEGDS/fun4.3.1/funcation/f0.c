#tinclude "f0_in.h"
#include "f0_out.h"


TreeNode* CreatTree(BinTreeNode **BST,FILE *fp,int N) {
	TreeNode *tree = NULL;
	ElementTypeTree *Data;

	char str0[MAXLINE];
	char *str = str0;

	ElementTypeBT *DataBT = NULL;

	Ch_Stack0 *stack = MakeCh_Stack0();
	ElementTypeCh_Stack0 *Datastack = NULL;
	
	for(int i = 0;i < N;i ++) {
		int num;;

		Getline(str,fp);
		num = OperatLine(&str);

		Data = Tree(str,num);

		if(num == 0) {
			tree = MakeTreeRoot(Data);

			DataBT = ElementBST(Data->Name,tree);	
			(*BST) = MakeBSTRoot(DataBT);
		} else{
			ComPath(stack,Data);
			tree = InsertTree(*BST,Data,stack);

			DataBT = ElementBST(Data->Name,tree);	
			InsertBSTNode(*BST,DataBT);
		}

		Datastack = ElementCh_Stack0(Data->Name,Data->num);
		PushCh_Stack0(stack,Datastack);
	}

	return tree;
}
void Getline(char *str,FILE *fp) {
	int i = 0;
	char c;

	fscanf(fp,"%c",&c);
	for(;c != '\n';i ++) {
		str[i] = c;
		fscanf(fp,"%c",&c);
	}

	str[i] = '\0';
}
ElementTypeTree* Tree(char *str,int num) {
	ElementTypeTree *Data = (ElementTypeTree*)malloc (sizeof(ElementTypeTree));
	Data->num = num;

	for(int i = 0;str[i] != '\0';i++ ) {
		Data -> Name[i] = str[i];
	}

	return Data;
}

ElementTypeCh_Stack0* ElementCh_Stack0(char *str,int num) {
	ElementTypeCh_Stack0* Data = (ElementTypeCh_Stack0*)malloc(sizeof(ElementTypeCh_Stack0));

	Data->num = num;

	for(int i = 0;str[i] != '\0';i++ ) {
		Data -> Name[i] = str[i];
	}

	return Data;
}

int OperatLine(char **str) {
	int count = 0;
	int i;

	for(i = 0;(*str)[i] == ' ';i ++) {
		count ++;
	}

	*str = &((*str)[i]);

	return count / 2;
}
void ComPath(PtrToCh_Stack0 stack,ElementTypeTree *Datatree) {
	ElementTypeCh_Stack0 *Datastack = PopCh_Stack0(stack);

	if(Datastack->num == Datatree->num) {
		free(Datastack);
	} else if(Datastack->num == (Datatree->num-1)) {
		PushCh_Stack0(stack,Datastack);
	} else if(Datastack->num > Datatree->num) {
		int k = Datastack->num - Datatree->num;

		free(Datastack);
		for(int i = 0;i < k;i ++) {
			Datastack = PopCh_Stack0(stack);
			free(Datastack);
		}
	}
}
