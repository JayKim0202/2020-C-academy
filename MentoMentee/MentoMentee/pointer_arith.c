#include <stdio.h>

main()
{
	int i = 10;
	int* pi = &i;

	printf("i = %d, pi = %p\n", i, pi);
	(*pi)++;	// pi가 가리키는 대상을 증가
	printf("i = %d, pi = %p\n", i, pi);

	printf("i = %d, pi = %p\n", i, pi);
	*pi++;	// pi를 증가
	printf("i = %d, pi = %p\n", i, pi);

	return 0;
}