#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int fd[2];
	pid_t pid;
	char message[] = "Hello, world!\n";
	char read_buffer[80];

	if (pipe(fd) == -1) {
		fprintf(stderr, "Pipe failed");
		return 1;
	}
	
	pid = fork();
	if (pid < 0) {
		fprintf(stderr, "Fork failed");
		return 1;
	} else if (pid == 0) {
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		read(STDIN_FILENO, read_buffer, sizeof(read_buffer));
		printf("Child read: %s", read_buffer);
	} else {
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		write(STDOUT_FILENO, message, sizeof(message));
		wait(NULL);
	}
	return 0;

}
