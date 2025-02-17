#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	printf("Hello,World (PID:%d)\n",getpid());
	int rc = fork();
	if(rc < 0) {
		printf("Creak a process is failed\n");
	} else if(rc == 0) {
		close(STDOUT_FILENO);
		fopen("out","r+");

		char* myargs[3];

		myargs[0] = "wc";
		myargs[1] = "p3.c";
		myargs[2] = NULL;

		execvp(myargs[0],myargs);
	} else {
		printf("I'm wait's return value %d\n",wait(NULL));
		//printf("The parent is start \n");
		//printf("I'm parent (PID:%d)\n",getpid());
	}
}
