#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* word1 = malloc(sizeof(char) * 50);
	char* word2 = malloc(sizeof(char) * 50);
	int equal;
	int i = 0;
	int num;

	printf("���ڿ� 2���� �Է��ϼ���: ");
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
		printf("���ڿ� 2���� ����.");
		break;
	case 0:
		printf("���ڿ� 2���� �ٸ���.");
		break;
	}

	free(word1);
	free(word2);

	return 0;
}