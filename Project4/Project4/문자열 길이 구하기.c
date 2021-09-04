#include <stdio.h>
#include <string.h> //strlen 함수가 선언된 헤더 파일

int main()
{
	char* s1 = "Hello";
	char s2[10] = "Hello";

	printf("%d\n", strlen(s1));
	printf("%d\n", strlen(s2));

	return 0;
}