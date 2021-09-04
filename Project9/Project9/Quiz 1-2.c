//다음 소스 코드를 완성하여 문자열이 들어있는 배열의 값을 알파벳 순서(오름차순)로 정렬하세요.
//문자열 비교는 strcmp함수를 사용하세요.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b)
{
	return strcmp((char*)a, (char*)b);
}

int main()
{
	char s1[10][8] = {
		"india", "delta", "bravo", "kilo", "alfa",
		"echo", "hotel", "juliett", "golf", "charlie"
	};

	qsort(s1, sizeof(s1) / sizeof(s1[0]), sizeof(s1[0]), compare);

	for (int i = 0; i < 10; i++)
	{
		printf("%s ", s1[i]);
	}

	printf("\n");

	return 0;
}