#include <stdio.h>

int main()
{
	int num1 = 2;
	int num2 = 2;
	int num3;
	int num4;

	num3 = ++num1; //num1 + 1 후 num3에 할당
	num4 = --num2; //num2 - 1 후 num4에 할당

	printf("%d %d\n", num3, num4); //3 1

	return 0;
}