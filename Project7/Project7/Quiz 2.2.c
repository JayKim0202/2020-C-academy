//다음 소스 코드를 완성하여 "Mars"가 출력되게 만드세요.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getName()
{
	char* str = malloc(sizeof(char) * 20);

	strcpy(str, "Mars");

	return str;
}

int main()
{
	char* name;

	name = getName();

	printf("%s\n", name);

	free(name);

	return 0;
}