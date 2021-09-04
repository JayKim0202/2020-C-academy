#include <stdio.h>

void hello()
{
	printf("Hello, world!\n");

	hello();	// hello 함수 안에서 hello 함수 호출
}

int main()
{
	hello();

	return 0;
}