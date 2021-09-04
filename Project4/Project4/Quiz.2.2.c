#include <stdio.h>

int main()
{
	char s1[10];

	printf("문자열을 임력하세요: ");
	gets(s1);

	printf("%s\n", s1);

	return 0;
}