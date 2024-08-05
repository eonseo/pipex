#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	int fd1, fd2;
	char message[32] = "message via fd2\n";

	fd1= open("made_by_fd1", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	// S_IRUSR | S_IWUSR: 파일에 대한 권한 설정.
	// 파일 소유자에게 읽기 및 쓰기 권한 부여
	if (fd1 < 0)
	{
		perror("File open error\n");
		exit(1);
	}

	fd2 = dup(fd1);
	write(fd2, message, strlen(message));
	printf("fd1: %d, fd2: %d\n", fd1, fd2);
	close(fd1);
	close(fd2);
	return 0;
}