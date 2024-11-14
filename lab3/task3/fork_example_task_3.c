#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid;
	int count = 0;
	int max_forks = 10;

	printf("Main program started\n");
	for (int i = 0; i < max_forks; i++) {
		pid = fork();
		if (pid < 0) {
			fprintf(stderr, "Fork failed\n");
			break;
		}
		else if (pid == 0) {
			printf("Child process %d started : PID = %d, parent PID = %d\n", count +1,getpid(), getppid());
			sleep(10);
			exit(0);
		}
		else {
			printf("Parent process started : PID = %d, child PID = %d\n", getpid(), pid);
			count++;
			wait(NULL);
		}
	}	

	printf("Created %d child processes\n", count);
	sleep(10);
	return 0;
}
