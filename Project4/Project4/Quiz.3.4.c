//표준 입력으로 길이 30 이하의 어떤 문자열이 입력됩니다. 입력된 문자열의 길이를 출력하는 프로그램을 만드세요.

#include <stdio.h>
#include <string.h>

int main()
{
	char s1[30];
	int ret;

	printf("문자열을 입력하세요: ");
	gets(s1);

	ret = strlen(s1);

	printf("%d\n", ret);

	return 0;
}