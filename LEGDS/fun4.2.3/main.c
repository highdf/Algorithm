#include "main.h"

int main() {
	BinTreeNode *p;
	FILE *fp = fopen("in","r");

	if(fp) {
		p = CreatBT(fp);
		printf("SeqTrav\n");
		SeqTrav(p);
		printf("PreorderTrav\n");
		PreorderTrav(p);
		printf("InorderTrav\n");
		InorderTrav(p);
		printf("PostorderTrav\n");
		PostorderTrav(p);
	} else {
		printf("Error:File in is empty\n");
	}
	return 0;
}
//funcation
