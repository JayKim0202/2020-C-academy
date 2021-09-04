#include <stdio.h>

int main()
{
	int num1;
	float num2;
	char c1;

	scanf("%d %f %c", &num1, &num2, &c1); //1 1.0 d

	num1++;
	num2++;
	c1--;

	printf("%d %f %c\n", num1, num2, c1); //2 2.000000 c

	return 0;
}