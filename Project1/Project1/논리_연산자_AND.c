#include <stdio.h>

int main()
{
	//&& = AND(논리곱), 양쪽 모두 참일 때 참
	printf("%d\n", 1 && 1);
	printf("%d\n", 1 && 0);
	printf("%d\n", 0 && 1);
	printf("%d\n", 0 && 0);

	printf("%d\n", 2 && 3);

	return	0;
}