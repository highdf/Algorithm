//------- >
#include <stdio.h>
#include "/home/luky/Algorithm/Include/status.h"
#include "struction/Tree.h"
#include "struction/BinTree.h"
#include "struction/Ch_Stack.h"

#include "struction/BST_out.h"
#include "struction/Tree_out.h"
#include "f0_out.h"

extern BinTreeNode *BST;
//------- >
int Is(char *str,char (*re)[20]);
TreeNode* FindTreeNode (BinTreeNode *BST,char *str);
status Method0(TreeNode *Tree0,TreeNode *Tree1);
status Method1(TreeNode *Tree0,TreeNode *Tree1);
status Method2(TreeNode *Tree0,TreeNode *Tree1);
status Method3(TreeNode *Tree0,TreeNode *Tree1);
status Method4(TreeNode *Tree0,TreeNode *Tree1);
int GetName(char *str,char *re);
status IsChar(char c);
