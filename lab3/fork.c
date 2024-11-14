#include <stdio.h>
#include <string.h>
#include <unistd.h>

int fd[2];
int main() {
	printf("Parent process, getpid=%d\n", getpid());
	pipe(fd);
	pid_t pid = fork();
	if (pid == 0) {
		char *msg = "Message from child process to parent process\n";
		printf("I'm child process, getpid=%d\n", getpid());
		close(fd[0]);
		write(fd[1], msg, strlen(msg)+1);
	} else {
		printf("I'm parent process, getpid=%d\n", getpid());
		close(fd[1]);
		char buf[100];
		read(fd[0], buf, sizeof(buf));
	}
	return 0;
}
