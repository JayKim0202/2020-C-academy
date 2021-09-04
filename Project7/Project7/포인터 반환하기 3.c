#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* helloLiteral()
{
	char* s1 = "Hello, world!";

	return s1;		//문자열 Hello, Wordl!는 메모리에 저장되어 있으므로 사라지지 않음
					//문자열 포인터 리턴
}

char* helloDynamicMemory()
{
	char* s1 = malloc(sizeof(char) * 20);

	strcpy(s1, "Hello, world!");

	return s1;
}

int main()
{
	char* s1;
	char* s2;

	s1 = helloLiteral();
	s2 = helloDynamicMemory();

	printf("%s\n", s1);
	printf("%s\n", s2);

	free(s2);

	return 0;
}