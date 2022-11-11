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
		int err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
		if (err == -1)
		{
			printf("Could not find program to execute!\n");
			return (2);
		}
	} else {
		// Parent process
		int wstatus;
		wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			int statusCode = WEXITSTATUS(wstatus);
			if (statusCode == 0)
			{
				printf("Success!\n");
			} else {
				printf("Failure with status code %d\n", statusCode);
			}
		}
	}

	printf("Some post processing goes here\n");
	return (0);
}