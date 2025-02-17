#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int x = 100;

	printf("Welcome:\n");
	int child_pid = fork();

	if(child_pid < 0) {
		printf("The child process is failed\n");
	} else if(child_pid == 0) {
		printf("I'm child process (PID:%d)\n",getpid());
		printf("x is %d\n",x);
		printf("new x \n");
		x = 20;
		printf("x = %d\n",x);
	} else {
		wait(NULL);
		printf("In the parent process (PID:%d)\n",getpid());
		printf("x is %d\n",x);
		printf("new x \n");
		x = 12;
		printf("x = %d\n",x);
	}
	return 0;
}
