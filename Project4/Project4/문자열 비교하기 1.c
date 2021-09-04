#include <stdio.h>
#include <string.h> //strcmp 함수가 선언된 헤더파일

int main()
{
	//strcmp(문자열1, 문자열2)==문자열 비교 결과를 반환
	char s1[10] = "Hello";
	char* s2 = "Hello";

	int ret = strcmp(s1, s2);

	printf("%d\n", ret);

	return 0;
}