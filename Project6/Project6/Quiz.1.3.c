//���� �ҽ� �ڵ带 �ϼ��Ͽ� 12�� ��µǰ� ���弼��.

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