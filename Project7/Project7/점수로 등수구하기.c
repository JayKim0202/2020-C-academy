//점수 입력후 등수 구하기. 등수배열, 점수배열 따로, 최댓값 활용
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

	printf("점수를 5개 입력해주세요: ");

	for (int i = 0; i < sizeof(score) / sizeof(int); i++)
	{
		scanf("%d", &score[i]);
	}

	for (int i = 0; i < sizeof(score) / sizeof(int); i++)
	{
		printf("%d등 : %d\n", i + 1, rank(score));

	}


	return 0;
}