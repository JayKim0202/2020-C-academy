#include <stdio.h>

int main()
{
	//다음 소스 코드를 완성하여 정수 2 5, 4 4, 8 3, 16 2, 32 1이 각줄에 출력되게 만드세요.

	for ( int i = 2, j = 5; i <= 32; i *= 2, j--)
	{
		printf("%d %d\n", i, j);
	}

	return 0;
}