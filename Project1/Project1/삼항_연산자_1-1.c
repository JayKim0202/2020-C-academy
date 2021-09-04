#include <stdio.h>

int main()
{
	int num1 = 5; //0이 아니면 모두 참
	int num2;

	num2 = num1 ? 100 : 200;

	printf("%d\n", num2);
	
	return 0;
}