#include <stdio.h>

int main()
{
	int num1;
	int num2;

	scanf("%d %d", &num1, &num2);

	for (int i = num1; i <= num2; i++)
	{
		if (i % 2 == 0)
			printf("%d\n", i);
		else
			printf("");
	}

	return 0;
}