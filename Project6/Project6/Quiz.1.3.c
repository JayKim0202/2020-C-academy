//다음 소스 코드를 완성하여 12가 출력되게 만드세요.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* numPtr1 = malloc(sizeof(int));
	void* ptr;

	*numPtr1 = 12;

	ptr = numPtr1;

	printf("%llu\n", *(int*)ptr);

	free(numPtr1);

	return 0;
}