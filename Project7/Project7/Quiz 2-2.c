//다음 소스 코들르 완성하여 문자열이 같으면 "같음", 다르면 "다름"이 출력되게 만드세요.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compareString(char* s1, char* s2)
{
	if (*s1 == *s2)
	{
		printf("같음");
	}
	else if (*s1 != *s2)
	{
		printf("다름");
	}
}
/*
void compareString(char* s1, char* s2)
{
	if (strcmp(s1, s2) == 0)
		printf("같음");
	else
		printf("다름");
}
*/

int main()
{
	char* s1 = malloc(sizeof(char) * 10);

	strcpy(s1, "Venus");

	compareString(s1, "Venus");

	free(s1);

	return 0;
}