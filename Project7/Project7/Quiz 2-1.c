/*1.e
2.c
3.b,d,e,*/

//���� �ҽ� �ڵ带 �ϼ��Ͽ� 10 20 30�� ��µǰ� ���弼��. �Լ��� ��ȯ������ ���� �� �� ������ �Ű������� ���� �� �� ������ �մϴ�.

#include <stdio.h>

int getNumber(int* a, int* b)
{
	*a = 10;
	*b = 20;
	return *a + *b;
}



int main()
{
	int num1 = 0;
	int num2 = 0;
	int result = 0;

	result = getNumber(&num1, &num2);

	printf("%d %d %d\n", num1, num2, result);

	return 0;
}