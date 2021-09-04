#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s1[20] = " 9th symphony";
	char s2[40] = "Beethoven";

	strcat(s2, s1);

	printf("%s\n", s2);

	return 0;
}