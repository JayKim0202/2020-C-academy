#include <stdio.h>

int main()
{
	char s1[10];
	float num1 = 38.972340f;

	sprintf(s1, "%f", num1);

	printf("%s\n", s1);

	return 0;
}