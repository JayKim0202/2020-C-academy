#include <stdio.h>
#include <math.h>

int main()
{
	int num1;
	int num2; 
	int num3; 

	scanf("%d", &num1);
	
	num2 = num1 / 1000;
	num3 = num1 / 500;

	printf("1õ�� : %d��\n", num2);
	printf("500�� : %d��\n", num3);

	return 0;
}