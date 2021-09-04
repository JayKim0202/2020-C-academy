#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void joinSentence(char* s1, char* s2)
{
	int i = 0;
	int length1;
	int length2;

	length1 = strlen(s1);
	length2 = strlen(s2);

	while (1)
	{
		s1[i + length1] = s2[i];
		if (i == length2)
		{
			break;
		}
		i++;
	}
}

int main()
{
	char* c1 = malloc(sizeof(char) * 50);
	char* c2 = malloc(sizeof(char) * 50);

	printf("앞에 올 문자열: ");
	gets(c1);

	printf("뒤에 올 문자열: ");
	gets(c2);

	joinSentence(c1, c2);

	printf("%s\n", c1);

	free(c1);
	free(c2);

	return 0;
}