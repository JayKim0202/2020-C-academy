#include <stdio.h>
#include <stdlib.h>

int* ten()
{
	int* numPtr = malloc(sizeof(int));

	*numPtr = 10;

	return numPtr;	//포인터 반환, malloc으로 메모리를 할당하면 함수가 끝나도 사라지지 않음
}

int main()
{
	int* numPtr;
	
	numPtr = ten();

	printf("%d\n", *numPtr);	//10 : 메모리를 해제하기 전까지 안점함

	free(numPtr);		//다른 함수에서 할당한 메모라도 반드시 해제해야 함.

	return 0;
}