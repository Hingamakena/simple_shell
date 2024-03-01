#include "main.h"

int main(__attribute__ ((unused))int argc, __attribute__((unused))char **argv)
{
	pid_t my_pid;
	ssize_t nread;
	size_t len = 0;
	char *line = NULL;
	char *ts;

	my_pid = getpid();

	write(1,"$: ",3);

	if((nread = getline(&line, &len, stdin)) == -1)
	{
		printf("error reading input command");
	}	
	fwrite(line, nread, 1, stdout);

	ts = strtok(line, " ");

	printf("\n");
	printf("%s", ts);
	printf("\n");

	printf("my pid is %u\n",my_pid);

	free(line);
	exit(EXIT_SUCCESS);
}
