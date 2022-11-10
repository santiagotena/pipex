#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>


// Best practice is to create processes only from parent process
// The example bellow is not best practice
int main(int argc, char ** argv)
{
	int id1 = fork();
	int id2 = fork();
	if (id1 == 0)
	{
		if (id2 == 0)
			printf("We are process y\n");
		else
			printf("We are process x\n");
	}
	else {
		if (id2 == 0)
			printf("We are process z\n");
		else
			printf("We are the parent process\n");
	}
	while (wait(NULL) != -1 || errno != ECHILD)
		printf("Waited for a child to finish\n");
	return (0);
}