#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numArr[10];								//int형 요소 10개를 가진 배열 생성
	int* numPtr = malloc(sizeof(int) * 10);		//int 10개 크기만큼 메모리 할당

	numArr[0] = 10;		//배열을 인덱스로 접근하여 값 할당
	numArr[0] = 10;		//포인터를 인덱스로 접근하여 값 할당

	free(numPtr);		//메모리 해제

	return 0;
}