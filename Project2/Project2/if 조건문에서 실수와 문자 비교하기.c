#include <stdio.h>

int main()
{
	float num1 = 0.1f;
	char c1 = 'a';

	if (num1 == 0.1f)
		printf("0.1입니다.\n");

	if (c1 == 'a')
		printf("a입니다.\n");

	if (c1 == 97)
		printf("a입니다.\n");

	return 0;
}