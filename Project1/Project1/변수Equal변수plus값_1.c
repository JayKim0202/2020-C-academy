#include <stdio.h>

int main()
{
	int num1 = 1;
	int num2 = 1;

	num1 = num1 + 2; //num1 = 1 + 2 = 3 (num1�� �ٽ� ����)
	num2 = num2 - 2; //num2 = 1 - 2 = -1 (num2�� �ٽ� ����)

	printf("%d\n", num1); // 3
	printf("%d\n", num2); // -1

	return 0;
}