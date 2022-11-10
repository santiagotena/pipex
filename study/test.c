#include <stdio.h>

int main(void)
{
	char str[] = "Santiago";

	printf("%d", (int)(sizeof(str) / sizeof(char)) - 1);
	return (0);
}