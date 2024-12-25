#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	FILE *fp = fopen("out","r+");
	int child_pid = fork();

	if(child_pid < 0) {
		printf("The child porcess is failed\n");
	} else if(child_pid == 0) {
		fprintf(fp,"Y");
		printf("Hello ");
	} else {
		char c;
		fscanf(fp,"%c",&c);
		if(c == 'Y') {
			printf("GoodDay\n");
		}

	}
	return 0;
}
