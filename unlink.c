#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int idx;

	if (argc == 1)
	{
		fprintf(stderr, "%s {file1} {file2} ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	for (idx = 1; idx < argc; idx++)
	{
		if (unlink(argv[idx]) == -1)
			fprintf(stderr, "%s file delete error: %s\n", argv[idx], strerror(errno));
		else
			printf("%s file has been deleted.\n", argv[idx]);
	}
	exit(EXIT_SUCCESS);
}