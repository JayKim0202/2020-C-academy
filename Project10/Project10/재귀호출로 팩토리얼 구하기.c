#include <stdio.h>

int factorial(int n)	
{
	if (n == 1)
		return 1;

	return n * factorial(n - 1);	// n�� factorial �Լ��� n - 1�� �־ ��ȯ�� ���� ����;
}

int main()
{
	printf("%d", factorial(6));

	return 0;
}