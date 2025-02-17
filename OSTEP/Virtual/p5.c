#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	FILE *fp = fopen("out","r+");

	int child_pid = fork();

	if(child_pid < 0) {
		printf("The child process is faild\n");
	} else if (child_pid == 0 ) {
		wait(NULL);
		fprintf(fp,"I'm child process (PID:%d)\n",getpid());
	} else {
		fprintf(fp,"I'm parent process (PID:%d)\n",getpid());
	}
	return 0;
}
