#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* numPtr = malloc(sizeof(int));
	int* cPtr;

	*numPtr = 0x12345678;

	printf("0x%x\n", *(char*)numPtr);	// 0x78: numPtr을 char 포인터로 변환한 뒤 역참조
	printf("0x%x\n", *(int*)numPtr);	// 0x12345678: numPtr을 int 포인터로 변환한 뒤 역참조
	printf("0x%x\n", *(short*)numPtr);	// 0x5678: numPtr을 short 포인터로 변환한 뒤 역참조

	free(numPtr);

	return 0;
}