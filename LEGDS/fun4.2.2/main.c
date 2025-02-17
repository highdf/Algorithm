#include "main.h"

int main() {
	FILE *fp;
	BinTreeNode *BT = NULL;

	fp = fopen("in","r");
	if(fp) {
		BT = CreatBT(fp);

		SeqTrav(BT);
	}
	return 0;
}
