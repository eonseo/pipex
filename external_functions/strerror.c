#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
	FILE *stream = NULL;

	stream = fopen("mylib/myfile", "r");
	if (stream == NULL)
		printf("%s\n", strerror(errno));
	return 0;
}