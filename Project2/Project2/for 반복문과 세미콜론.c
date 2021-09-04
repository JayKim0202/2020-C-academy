#include <stdio.h>

int main()
{
	for (int i = 0; i < 100; i++); //:을 쓸 경우 널문이 되어 반복되지 않는다.
	{
		printf("Hello, world!\n");
	}

	return 0;
}