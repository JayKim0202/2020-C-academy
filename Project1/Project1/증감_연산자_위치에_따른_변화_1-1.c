#include <stdio.h>

int main()
{
	int num1 = 2;
	int num2 = 2;
	int num3;
	int num4;

	num3 = num1++; //num3에 num1을 넣어준 뒤 + 1 그러므로 num3 = 2
	num4 = num2--; //num4에 num2를 넣어준 뒤 - 1 그러므로 num4 = 2

	printf("%d %d\n", num3, num4); //2 2

	return 0;
}