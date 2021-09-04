#include <stdio.h>

int main()
{
	int i = 100;

	do
	{
		printf("Hello, world! %d\n", i);
		i--;
	} while (i > 0);

	return 0;
}