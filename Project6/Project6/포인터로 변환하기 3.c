#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* numPtr = malloc(sizeof(int));
	int* cPtr;

	*numPtr = 0x12345678;

	printf("0x%x\n", *(char*)numPtr);	// 0x78: numPtr�� char �����ͷ� ��ȯ�� �� ������
	printf("0x%x\n", *(int*)numPtr);	// 0x12345678: numPtr�� int �����ͷ� ��ȯ�� �� ������
	printf("0x%x\n", *(short*)numPtr);	// 0x5678: numPtr�� short �����ͷ� ��ȯ�� �� ������

	free(numPtr);

	return 0;
}