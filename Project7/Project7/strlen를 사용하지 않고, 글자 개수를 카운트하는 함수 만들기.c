#include <stdio.h>
#include <stdlib.h>

int countNumber(char* s)
{
	int count = 0;
	int i = 0;


	while (1)
	{
		if (s[i] != NULL)
		{
			count++;
		}
		else
			break;
		i++;
	}

	return count;
}

int main()
{
	char s1[100];

	gets(s1);

	printf("%d\n", countNumber(&s1));

	return 0;
}

//strcpy, strcat ¸¸µé±â