//표준 입력으로 길이 10 이하의 문자열이 10개 입력됩니다(중복 값은 없습니다).
//다음 소스 코드를 완성하여 입력된 문자열이 내림차순으로 정렬되도록 만드세요.

/*
india delta bravo kilo alfa echo hotel juliett golf charlie
kilo juliett india hotel golf echo delta charlie bravo alfa
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b)
{
	int num = strcmp((char*)a, (char*)b);

	if (num > 0)
		return -1;
	else if (num < 0)
		return 1;

	return 0;
}

int main()
{
	char s1[10][20];

	for (int i = 0; i < 10; i++)
	{
		scanf("%s", s1[i]);
	}

	qsort(s1, sizeof(s1) / sizeof(s1[0]), sizeof(s1[10]), compare);

	for (int i = 0; i < 10; i++)
	{
		printf("%s ", s1[i]);
	}

	printf("\n");

	return 0;
}