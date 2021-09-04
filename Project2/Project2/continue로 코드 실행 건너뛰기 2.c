#include <stdio.h>

int main()
{
	int i = 1;
	while (i <= 100);
	{
		i++;
		if (i % 2 != 0)
			continue;

		printf("%d\n", i);
	}

	return 0;
}