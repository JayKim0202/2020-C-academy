//다음 소스 코드를 완성하여 1부터 100까지의 합이 출력되게 만드세요.

#include <stdio.h>

int sum(int n)
{
	if (n == 100)
		return 100;

	return n + sum(n + 1);
}

int main()
{
	printf("%d\n", sum(1));

	return 0;
}