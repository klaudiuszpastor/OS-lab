#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>

#define FIFO_PATH "fifo"
#define NUM_PROCESSES 6


int main() {
	if (mkfifo(FIFO_PATH, 0666) == -1) {
		perror("mkfifo");
		return 1;
	}
	
	pid_t pid;
	char message[100];

	for (int i = 0; i < NUM_PROCESSES; i++) {
		pid = fork();

		if (pid < 0) {
			perror("fork");
			return 1;
		} else if (pid == 0) {
			int fifo_fd = open(FIFO_PATH, O_WRONLY);
			if(fifo_fd == -1) {
				perror("open");
				return 1;
			}
			//printf("Hello from process %d (PID %d)\n", i+1, getpid());	
			snprintf(message, sizeof(message),"Hello from process %d (PID %d)\r\n",i+1, getpid());
			write(fifo_fd, message, sizeof(message));
			close(fifo_fd);
			exit(0);
		}
	}

	for (int i = 0; i < NUM_PROCESSES; i++) {
		wait(NULL);
	}

	printf("All processes have finished\n");
	unlink(FIFO_PATH);

	return 0;
}
