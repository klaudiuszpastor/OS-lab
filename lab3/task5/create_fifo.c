#include <stdio.h>
#include <sys/stat.h>

int main() {
	const char *fifo_path = "fifo";
	if (mkfifo(fifo_path, 0666) == -1) {
		perror("mkfifo");
		return 1;
	}
	
	printf("FIFO created, path: %s\n", fifo_path);
	return 0;
}
