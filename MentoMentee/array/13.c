#include <stdio.h>

int main()
{
	int n = 32;
	int binary[32] = { 0 };
	int count = 0;

	printf("%d->", n);

	for (int i = 0; i < 32 && n > 0; i++)
	{
		binary[i] = n % 2;
		n = n / 2;
		count++;
	}

	for (int i = count - 1; i >= 0; i--)
	{
		printf("%d", binary[i]);
	}

	return 0;
}