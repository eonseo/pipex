#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXLINE 100

int main()
{
	char	line[MAXLINE];
	int		fd[2], pid, n;

	pipe(fd);
	if ((pid == fork()) == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1); // 쓰기용 파이프를 표준출력에 복제
		close(fd[1]);
		// 표준출력에 쓴 내용은 파이프로 전달됨
		printf("hello world\n");
		printf("Good bye!\n");
	}
	else
	{
		close(fd[1]);
		printf("from child:\n");
		while ((n = read(fd[0], line, MAXLINE)) > 0)
			write(STDOUT_FILENO, line, n);
	}
	exit(0);
}