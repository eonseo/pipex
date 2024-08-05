#include <stdio.h>
#include <unistd.h>

int main()
{
	char	*pathname = "./userscript.sh";
	int		mode = R_OK | W_OK;

	if (access(pathname, mode) == 0)
		printf("Able to read and write.\n");
	else
		printf("No permission or doesn't exist.\n");
}