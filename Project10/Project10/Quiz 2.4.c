//표준 입력으로 정수 한 개가 입력됩니다(입력 값의 범위는 3~100). 다음 소스 코드를 완성하여 1부터 입력된 정수까지의 합이 출력되게 만드세요. 단, 재귀호출을 사용해야 합니다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int n)
{
	if (n == 1)
		return 1;

	return n + sum(n - 1);
}

int main()
{
	int n = 0;

	scanf("%d", &n);

	printf("%d\n", sum(n));

	return 0;
}