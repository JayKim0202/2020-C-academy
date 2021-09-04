#include <stdio.h>

int main()
{
	char s1[10];
	int num1 = 283;

	sprintf(s1, "%d", num1);

	printf("%s\n", s1);

	return 0;
}