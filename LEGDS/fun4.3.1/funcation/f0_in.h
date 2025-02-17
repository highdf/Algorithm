#include <stdlib.h>
#include <stdio.h>
#include "/home/luky/Algorithm/Include/status.h"
#include "struction/Tree.h"
#include "struction/BinTree.h"
#include "struction/Ch_Stack.h"

#include "struction/Ch_Stack_out.h"
#include "struction/Tree_out.h"
#include "struction/BST_out.h"

ElementTypeTree* 	Tree(char *str,int num);
ElementTypeCh_Stack0* 	ElementCh_Stack0(char *str,int num);

int 	OperatLine(char **str);
void 	ComPath(PtrToCh_Stack0 stack,ElementTypeTree *Datatree);
