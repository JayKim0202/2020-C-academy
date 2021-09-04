//표준 입력으로 길이 30이하의 어떤 문자열이 입력됩니다. 다음 소스 코드를 완성하여 두 printf가 같은 문자열을 출력하게 만드세요.

#include <stdio.h>
#include <string.h>

int main()
{
	char s1[31];
	char s2[31];

	gets(s1);

	strcpy(s2, s1);

	printf("%s\n", s1);
	printf("%s\n", s2);

	return 0;
}