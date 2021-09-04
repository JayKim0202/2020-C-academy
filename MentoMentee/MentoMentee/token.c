#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = { "I am the king of the world!" };
	char* token;
	char seps[] = " .,\n\t";

	token = strtok(str, seps);
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, seps);
	}

	return 0;
}