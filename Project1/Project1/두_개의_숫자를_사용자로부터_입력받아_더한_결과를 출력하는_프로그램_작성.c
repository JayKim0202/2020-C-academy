#include <stdio.h>

int main()
{
	int num1;
	int num2;
	int num3;

	printf("두 개의 숫자를 입력하시오: ");
	scanf("%d", &num1);
	scanf("%d", &num2);

	num3 = num1 + num2;

	printf("%d\n", num3);

	return 0;
}