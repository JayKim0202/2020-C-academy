//ǥ���Է����� �� ������ �Էµ˴ϴ�(�Է� ���� ������ long long�� ������ ����). ���� �ҽ� �ڵ带�ϼ��Ͽ� �� ������ ���� ��µǰ� ���弼��.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long add(long long a, long long b)
{
	return a + b;
}

int main()
{
	long long num1, num2;

	scanf("%lld %lld", &num1, &num2);	//1586727174858192858 4581287173895719283

	printf("%lld\n", add(num1, num2));

	return 0;
}