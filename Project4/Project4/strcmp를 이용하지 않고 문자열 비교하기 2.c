#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* word1 = malloc(sizeof(char) * 50);
	char* word2 = malloc(sizeof(char) * 50);
	int equal;
	int i = 0;
	int num;

	printf("문자열 2개를 입력하세요: ");
	gets(word1);
	gets(word2);
	
	while (1)
	{
		if (word1[i] == word2[i])
		{
			equal = 1;
			if (word1[i] == NULL)
			{
				break;
			}
		}
		else if (word1[i] != word2[i])
		{
			equal = 0;
			break;
		}
		i++;
	}

	switch (equal)
	{
	case 1:
		printf("문자열 2개가 같다.");
		break;
	case 0:
		printf("문자열 2개가 다르다.");
		break;
	}

	free(word1);
	free(word2);

	return 0;
}