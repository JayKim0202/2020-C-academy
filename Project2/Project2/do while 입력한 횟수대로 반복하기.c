#include <stdio.h>

int main()
{
	int count;

	scanf("%d", &count);

	int i = 0;
	do
	{
		printf("Hello, world! %d\n", i);
		i++;
	} while (i < count);

	return 0;
}