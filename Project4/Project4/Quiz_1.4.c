#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* s1 = " Wonderland";
	char* s2 = malloc(sizeof(char) * 30);

	strcpy(s2, "Alice in");
	strcat(s2, s1);

	printf("%s\n", s2);

	free(s2);

	return 0;
}