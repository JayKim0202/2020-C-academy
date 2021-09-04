//다음 소스 코드를 완성하여 00000008과 00000014가 각 줄에 출력되게 만드세요.

#include <stdio.h>

int main()
{
	int* numPtrA = NULL;

	printf("%p\n", numPtrA + 2);
	printf("%p\n", numPtrA + 5);
}