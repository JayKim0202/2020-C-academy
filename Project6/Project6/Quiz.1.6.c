//ǥ�� �Է����� *����Ʈ ũ���� 16�� ������ �Էµ˴ϴ�. ���� �ҽ� �ڵ带 �ϼ��Ͽ� 16�� ������ ���� �ڸ��� 4����Ʈ�� ��µǰ� ���弼��.

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned long long* numPtr1 = malloc(sizeof(unsigned long long));
	unsigned int* numPtr2;

	scanf("%llx", numPtr1);

	numPtr2 = (unsigned int*)numPtr1;

	printf("0x%x\n", *numPtr2);

	free(numPtr1);

	return 0;
}