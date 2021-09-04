#include <stdio.h>
#include <string.h>

int main()
{
	char* s1 = "Hello";
	char* s2 = "";

	strcpy(s2, s1);

	printf("%s\n", s1);

	return 0;
}