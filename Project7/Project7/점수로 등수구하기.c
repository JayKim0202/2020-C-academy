//���� �Է��� ��� ���ϱ�. ����迭, �����迭 ����, �ִ� Ȱ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int rank(int *s)
{
	int biggestNumber;

	biggestNumber = s[0];

	for (int i = 0; i < 5; i++)
	{
		if (biggestNumber < s[i])
		{
			biggestNumber = s[i];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (biggestNumber == s[i])
		{
			s[i] = 0;
		}
	}

	return biggestNumber;
}


int main()
{
	int score[5];

	printf("������ 5�� �Է����ּ���: ");

	for (int i = 0; i < sizeof(score) / sizeof(int); i++)
	{
		scanf("%d", &score[i]);
	}

	for (int i = 0; i < sizeof(score) / sizeof(int); i++)
	{
		printf("%d�� : %d\n", i + 1, rank(score));

	}


	return 0;
}