#include <stdio.h>

int main()
{
	int num1 = 5;

	if (num1 == 10); //;을 붙이는 경우, if와 상관없이 printf가 출력된다.
	{
		printf("10입니다.\n");
	}
	
	return 0;
}