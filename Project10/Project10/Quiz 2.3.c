//ǥ�� �Է����� ���� �� ���� �Էµ˴ϴ�(�Է� ���� ������ 10~30). ���� �ҽ� �ڵ带 �ϼ��Ͽ� �Էµ� ������ �ش��ϴ� �Ǻ���ġ ���� ��µǰ� ���弼��.
// �Ǻ���ġ ���� 0�� 1�� �����ϸ�, ������ �Ǻ���ġ ���� �ٷ� ���� �� �Ǻ���ġ ���� ���Դϴ�.

/*
10
55*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fib(int n)
{
	if (n == 0)
		return 0;

	return n + fib(n - 1);
}

int main()
{
	int num1;
	scanf("%d", &num1);

	printf("%d\n", fib(num1)); //10

	return 0;
}