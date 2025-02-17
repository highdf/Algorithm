#include "fun4.1.5.h"

int main() {
	int n;

	printf("Pealse enter tree node number\n");
	scanf("%d",&n);

	int T[n+1];
	int n0,n1;

	printf("Please enter nodes info\n");

	for(int i = 1;i < n+1;i++) {
		scanf("%d",&T[i]);
	}
	printf("Please enter n0 and n1\n");
	scanf("%d%d",&n0,&n1);

	if((Isn(n0,n+1) == TRUE) && (Isn(n1,n+1) == TRUE)) {
		F0(T,n0,n1);
	} else {
		printf("n0 or n1 is error\n");
	}

	return 0;
}
//funcation
void F0(int *tree,int i,int j) {
	if((tree[i] != 0) && (tree[j] != 0)) {
		do{
//			printf("i = %d,j = %d\n",j,j);
			if(i > j) {
				i /= 2;
			} else if(i < j) {
				j /= 2;
			} else {
				break;
			}
		}while(1);	
		printf("%d,%d\n",i,tree[i]);
	} else if(tree[i] != 0) {
		printf("Error:T[%d] is NULL\n",j);	
	} else if(tree[j] != 0) {
		printf("Error:T[%d] is NULL\n",i);
	} else {
		printf("Error:T[%d] is NULL\n",j);	
		printf("Error:T[%d] is NULL\n",i);
	}
}
status Isn(int n0,int n) {
	status re;
	if((n0 >= 1) && (n0 <= n)) {
		re = TRUE;
	} else {
		re = FALSE;
	}

	return re;
}
