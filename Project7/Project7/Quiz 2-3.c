//ǥ�� �Է����� ���� �� ���� �Էµ˴ϴ�(�Է� ���� ������ int�� ������ ����). ���� �ҽ� �ڵ带 �ϼ��Ͽ� �Էµ� �� ������ �������� �� ��� �������� ��µǰ� ���弼��.
//�Լ��� ��ȯ���� �Ű������� ��� Ȱ���Ͽ� ���� �����;� �մϴ�.

//10 3
//3 1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int getQuotientAndRemainder(int a, int b, int* r)
{
	*r = a % b;

	return a / b;
}


int main()
{
	int num1;
	int num2;
	int quotient;	//��
	int remainder;	//������

	scanf("%d %d", &num1, &num2);	//10 3

	quotient = getQuotientAndRemainder(num1, num2, &remainder);

	printf("%d %d\n", quotient, remainder);

	return 0;
}