#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int pipefd[2];

	if(pipe(pipefd) == -1) {
		printf("The pipe is creat failed\n");
	} else {
		int Len = 5;
		pid_t child_pid  = fork();

		if(child_pid < 0) {
			printf("The child process is failed\n");
		} else if(child_pid == 0) {
				char str[10];
				int readend;
				close(pipefd[1]);

				readend = read(pipefd[0],str,Len);
				str[readend] = '\0';
				printf("%s,World\n",str);
		} else {
			close(pipefd[0]);

			write(pipefd[1],"Hello",Len);
		}
	}

	return 0;
}
