#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* c1 = malloc(sizeof(char) * 50);
	char* c2 = malloc(sizeof(char) * 50);
	int i = 0;

	gets(c1);

	while (1)
	{
		c2[i] = c1[i];

		if (c1[i] == NULL)
		{
			c2[i] = c1[i];
			break;
		}
		i++;
	}

	printf("%s", c2);

	free(c1);
	free(c2);

	return 0;
}