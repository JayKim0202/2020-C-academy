#include <stdio.h>

void increaseNumber()
{
	int num1 = 0;				//static�� ������� ���� ��� increaseNuber �Լ��� ������ ���� ������⶧���� num1�� �׻� 0���� ���ǵȴ�.

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