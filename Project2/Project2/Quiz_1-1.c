#include <stdio.h>

int main()
{
	/*ǥ�� �Է����� �� ������ �Էµ˴ϴ�. ���� ������� ������ �� ����� ��µǰ� ���弼��.
	1. num1�� num2�� ���ϱ�
	2. 1�� ����� 10�� ���ϱ�
	3. 2�� ������� num3�� ����*/

	int num1;
	int num2;
	int num3;

	scanf("%d", &num1);
	scanf("%d", &num2);
	scanf("%d", &num3);

	printf("%d\n", (num1 + num2) * 10 - num3);

	return 0;
}