//ǥ�� �Է����� ���� 10 ������ ���ڿ��� 10�� �Էµ˴ϴ�(�ߺ� ���� �����ϴ�).
//���� �ҽ� �ڵ带 �ϼ��Ͽ� �Էµ� ���ڿ��� ������������ ���ĵǵ��� ���弼��.

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