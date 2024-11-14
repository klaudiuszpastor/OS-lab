#include <stdio.h>
#include <unistd.h>

int fd, i = 0;
char buf[32];
int main() {
	fd = open("fifo", O_WRONLY);
	while (1) {
		sprintf(buf, "Hello, World! %d", i++);
		write(fd, buf, sizeof(buf));
		sleep(1);
	}
	return 0;
}
