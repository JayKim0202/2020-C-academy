#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void binary(int x)
{
	if (x > 0)
	{
		binary(x / 2);
		printf("%d", x % 2);
	}
}

int main()
{
	int x;

	scanf("%d", &x);
	binary(x);

	return 0;
}