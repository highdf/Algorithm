#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t child_pid = fork();

	if(child_pid < 0) {
		printf("The child process is failed\n");
	} else if(child_pid == 0) {
		fclose(stdout);
		FILE *fp = fopen("out","r+");
		fprintf(fp,"I'm child process\n");
	} else {
		wait(NULL);
		printf("I'm parent process\n");
	}
	return 0;
}
