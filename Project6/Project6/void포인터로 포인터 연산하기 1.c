#include <stdio.h>
#include <stdlib.h>

int main()
{
	void* ptr = malloc(100); //100만큼 메모리 할당

	printf("%p\n", ptr);

	printf("%p\n", ptr + 1); //컴파일 에러. void 포인터는 포인터 연산을 할 수 없음.

	free(ptr);

	return 0;
}