//strlen�� �̿����� �ʰ�, ������ ���ڸ� ���� �ڵ� ����
//Hint : NULL

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* s1 = malloc(sizeof(char) * 50);
	int count = 0;
	int i = 0;

	gets(s1);

	// s1[i]�� NULL�� �ƴ� ��, count + 1
	while (s1[i] != NULL)
	{
		if (s1[i] != NULL)
		{
			count += 1;
		}
		i++;
	}

	printf("%d", count);

	free(s1);

	return 0;
}