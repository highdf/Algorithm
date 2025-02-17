#include <stdlib.h>
#include <stdio.h>

int* null();

int main() {
	int *re;

	re = null();

	printf("free defore\n");
	free(re);
	printf("free after\n");

	return 0;
}

//function
int* null() {
	return (int *)NULL;
}
