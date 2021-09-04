#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return (y, x % y);
}

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d", gcd(x, y));

	return 0;
}