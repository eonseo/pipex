#include <stdio.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
	char cmd[] = "/bin/ls"; // 실행할 파일 위치
	char *argVec[] = {"ls", "-a", NULL}; // 명령어 detalis
	char *envVec[] = {NULL};
	int filefd;

	filefd = open("test.txt", O_RDWR);
	printf("%d\n", filefd);
	if (filefd < 0)
		perror("filefd");
	dup2(filefd, STDOUT_FILENO);
	printf("Start of execve call %s: \n", cmd);
	printf("====================\n");
	if (execve(cmd, argVec, envVec) == -1)
		perror("Could not execute execve");
	printf("execve");
	return 0;
}