//문자열 비교하기. 두개가 같다 다르다로만 출력
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* word1 = malloc(sizeof(char) * 50);
	char* word2 = malloc(sizeof(char) * 50);
	int count = 0;
	int num = 0;
	int i = 0;
	int j = 0;

	printf("문자열을 두개 입력하세요: ");
	gets(word1);
	gets(word2);

	while (word1[j] != NULL)
	{
		if (word1[j] != NULL)
		{
			num += 1;
		}
		j++;
	}

	while (word2[i] != NULL)
	{
		if (word1[i] == word2[i])
		{
			count += 1;
		}
		else
		{
			count = count;
		}
		i++;
	}

	/*for (int i = 0; word1[i] == NULL; i++)
	{
		if (word1[i] == word2[i])
		{
			count += 1;
		}
		else if (word1[i] != word2[i])
		{
			count = count;
		}
	}*/


	if (num == count)
	{
		printf("word1 과 word2는 같다.");
	}
	else if (num != count)
	{
		printf("word1과 word2는 다르다.");
	}

	free(word1);
	free(word2);

	return 0;
}


