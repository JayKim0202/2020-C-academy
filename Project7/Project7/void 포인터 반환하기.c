#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* allocMemory()
{
	void* ptr = malloc(100);

	return ptr;
}

int main()
{
	char* s1 = (char*)allocMemory();	//void 포인터를 char 포인터에 넣어서 문자열처럼 사용
	strcpy(s1, "Hello, world!");		//s1에 Hello, world! 복사
	printf("%s\n", s1);					//Hello, world!
	free(s1);							//동적 메모리 해제

	int* numPtr1 = (int*)allocMemory();	//viod 포인터를 int 포인터에 넣어서 정수 배열처럼 사용
	numPtr1[0] = 10;					//첫 번째 요소에 10 저장
	numPtr1[1] = 20;					//두 번째 요소에 20 저장
	printf("%d %d\n", numPtr1[0], numPtr1[1]);	//10 20
	free(numPtr1);						//동적 메모리 해제

	return 0;
}