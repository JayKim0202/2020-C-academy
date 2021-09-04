#include <stdio.h>

int main()
{
	int num1;
	int num2;

	scanf("%d", &num1);
	scanf("%d", &num2);

	num1 /= num2;
	printf("%d(quotient)\n", num1);

	num1 %= num2;
	printf("%d(remainder)\n", num1);
	
	return 0;
}