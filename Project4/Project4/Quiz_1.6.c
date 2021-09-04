//표준 입력으로 길이 30 이하의 어떤 문자열이 입력됩니다. 다음 소스 코드를완성하여 입력된 문자열 뒤에 "th"가 붙어서 출력되게 만드세요.

#include <stdio.h>
#include <string.h>

int main()
{
	char s1[40];

	gets(s1);

	strcat(s1, "th");

	printf("%s\n", s1);

	return 0;
}