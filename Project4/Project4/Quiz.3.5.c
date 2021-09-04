//표준 입력으로 길이 30 이하의 문자열 두 개가 입력됩니다. 두 문자열이 같은지 다른지 비교 결과를 정수로 출력하는 프로그램을 만드세요.

#include <stdio.h>
#include <string.h>

int main()
{
	char s1[30];
	char s2[30];

	printf("문자열을 두 개 입력하세요: ");
	gets(s1);
	gets(s2);

	printf("%d\n", strcmp(s1, s2));

	return 0;
}