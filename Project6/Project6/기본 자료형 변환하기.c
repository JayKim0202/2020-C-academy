#include <stdio.h>

int main()
{
	int num1 = 32;
	int num2 = 7;
	float num3;

	num3 = num1 / num2;
	printf("%f\n", num3);

	num3 = (float)num1 / num2; //num1À» float·Î 
	printf("%f\n", num3);

	return 0;
}