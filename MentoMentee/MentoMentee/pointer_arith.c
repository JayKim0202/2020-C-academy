#include <stdio.h>

main()
{
	int i = 10;
	int* pi = &i;

	printf("i = %d, pi = %p\n", i, pi);
	(*pi)++;	// pi�� ����Ű�� ����� ����
	printf("i = %d, pi = %p\n", i, pi);

	printf("i = %d, pi = %p\n", i, pi);
	*pi++;	// pi�� ����
	printf("i = %d, pi = %p\n", i, pi);

	return 0;
}