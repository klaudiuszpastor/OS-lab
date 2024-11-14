#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid;

	printf("Main program started\n");

	pid = fork();
	if (pid < 0) {
		fprintf(stderr, "Fork failed\n");
		return 1;
	}
	else if (pid == 0) {
		printf("Child process started : PID = %d, parent PID = %d\n", getpid(), getppid());
	}
	else {
		printf("Parent process started : PID = %d, child PID = %d\n", getpid(), pid);
	}
	
	sleep(5);

	return 0;
}
