#include <stdio.h>

int main()
{
	int num1 = 2;
	int num2 = 2;
	
	printf("%d %d\n", num1++, num2--); //%d�� num1�� num2�� ������ +-
									   //2 2
	printf("%d %d\n", num1, num2);     //3 1

	return 0;
}