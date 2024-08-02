#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	int		fd1, ret;
	char	message[32] = "STDERR from fd1\n";

	fd1 = open("made_by_fd1", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd1 < 0)
	{
		perror("file open error\n");
		exit(1);
	}
	printf("file open\n");

	// 그림 2번
	// fd1의 파일 디스크립터가 명시한 STDOUT_FILENO의 파일 디스크립터로 복제됨
	ret = dup2(fd1, STDOUT_FILENO);
	printf("fd1: %d, ret: %d\n", fd1, ret);

	// 그림 3번
	ret = dup2(STDERR_FILENO, fd1);
	write(fd1, message, strlen(message));
	printf("Even though 'printf' was used, the output is written to a file.\n");

	close(fd1);
	return 0;
}