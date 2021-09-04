#include <stdio.h>

void increaseNumber()
{
	int num1 = 0;				//static을 사용하지 않을 경우 increaseNuber 함수를 지나면 모든게 사라지기때문에 num1은 항상 0으로 정의된다.

	printf("%d\n", num1);

	num1++;
}

int main()
{
	increaseNumber();		// 0
	increaseNumber();		// 0
	increaseNumber();		// 0
	increaseNumber();		// 0

	return 0;
}