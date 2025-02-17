#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	printf("Hello,World (PID:%d)\n",getpid());
	int rc = fork();
	if(rc < 0) {
		printf("Creak a process is failed\n");
	} else if(rc == 0) {
		printf("I'm child (PID:%d)\n",getpid());
	} else {
		printf("I'm parent (PID:%d)\n",getpid());
	}
}
