#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Called functions via this method overtake the whole main process.
// If something is downstream of their call, it does not get excecuted.
// We can fork in order to avoid not completing the program.

int main(int argc, char **argv )
{
	int pid = fork();
	if (pid == -1)
		return (1);
	// Be careful not to run exec within parent processes.
	// This can lead to zombie processes.
	if (pid == 0) // Child process
	{
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
	} else {
		// Parent process
		wait(NULL);
		printf("Success!\n");
	}

	printf("Some post processing goes here\n");
	return (0);
}