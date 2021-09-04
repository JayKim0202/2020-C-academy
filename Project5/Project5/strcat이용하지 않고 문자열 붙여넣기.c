#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* c1 = malloc(sizeof(char) * 50);
	char* c2 = malloc(sizeof(char) * 50);
	int length;

	printf("앞에 올 문자열: ");
	gets(c2); //hello

	printf("뒤에 올 문자열: ");
	gets(c1); //world!

	length = strlen(c2);

	for (int i = 0;; i++)
	{
		c2[i + length] = c1[i];

		if (c1[i] == NULL)
		{
			break;
		}
	}
	
	printf("%s\n", c2);

	free(c1);
	free(c2);
	return 0;
}