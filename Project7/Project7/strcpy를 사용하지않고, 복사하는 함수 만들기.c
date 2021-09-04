#include <stdio.h>
#include <stdlib.h>

void copyCharacter(char* s1, char* s2)
{
	int i = 0;

	while (1)
	{
		if (s1[i] != NULL)
		{
			s2[i] = s1[i];
		}
		else if (s1[i] == NULL)
		{
			s2[i] = s1[i];
			break;
		}
		i++;
	}
}

int main()
{
	char* c1 = malloc(sizeof(char) * 50);
	char* c2 = malloc(sizeof(char) * 50);

	printf("단어를 입력하세요:");
	gets(c1);

	copyCharacter(c1, c2);

	printf("%s\n", c2);

	free(c1);
	free(c2);

	return 0;
}