//���ڿ� ���ϱ�. �ΰ��� ���� �ٸ��ٷθ� ���
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

	printf("���ڿ��� �ΰ� �Է��ϼ���: ");
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
		printf("word1 �� word2�� ����.");
	}
	else if (num != count)
	{
		printf("word1�� word2�� �ٸ���.");
	}

	free(word1);
	free(word2);

	return 0;
}


