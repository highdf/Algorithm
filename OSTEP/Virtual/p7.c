#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int child_pid = fork();

	if(child_pid < 0) {
		printf("The child process is faild\n");
	} else if(child_pid == 0) {
		char *myargs[3] = {"vim","--version",NULL};

		fclose(stdout);
		fopen("out","r+");
		execvp("vim",myargs);
	} else {
		wait(NULL);
	}

	return 0;
}
