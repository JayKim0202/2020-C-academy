//다음 소스 코드를 완성하여 "Neptune"이 출력되게 만드세요.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Name {
	char name[20];
};

struct Name* getName()
{
	struct Name* N = malloc(sizeof(struct Name));

	strcpy(N->name, "Nemptune");

	return N;
}

int main()
{
	char* name;

	name = getName();

	printf("%s\n", name);

	free(name);

	return 0;
}