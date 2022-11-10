#include <unistd.h>
#include <stdio.h>

// One fork
// int main(int argc, char **argv)
// {
// 	int id = fork();
// 	printf("Hello from id: %d\n", id);
// 	if (id == 0)
// 		printf("Hello from the child process\n");
// 	else
// 		printf("Hello from the main process\n");
// 	return (0);
// }

// Several forks
// int main(int argc, char **argv)
// {
// 	fork();
// 	fork();
// 	printf("Hello\n");
// 	return (0);
// }

// Three processes
int main(int argc, char **argv)
{
	int id = fork();
	if (id != 0)
		fork();
	printf("Hello\n");
	return (0);
}
