#include <stdio.h>
#include <stdlib.h>

int main()
{
	register int num1 = 10;		// ���� num1�� CPU�� �������͸� ���

	printf("%d\n", num1);
		// printf("%p\n", &num1);	// ������ ����. num1�� �޸𸮿� �����Ƿ� �޸� �ּҸ� ���� �� ����

	register int* numPtr = malloc(sizeof(int));

	// �������� ������ �޸� �ּҴ� ������ �� �����Ƿ� ������ �����ڸ� ����� �� ����
	*numPtr = 20;
	printf("%d\n", *numPtr);

	free(numPtr);

	return 0;
}