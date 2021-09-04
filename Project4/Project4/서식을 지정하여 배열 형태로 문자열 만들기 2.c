#include <stdio.h>

int main()
{
	char s1[30];

	sprintf(s1, "%c %d %f %e", 'a', 10, 3.2f, 1.23456e-21f);

	printf("%s\n", s1);

	return 0;
}