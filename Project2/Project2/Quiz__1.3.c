#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*ǥ�� �Է����� ������ �Էµ˴ϴ�(�Է� ���� ������ 0~1000). ���� �ҽ��ڵ带 �ϼ��Ͽ� 0���� �Էµ� ���ڱ����� ���� ��µǰ� ���弼��.*/

	int num1;
	int sum = 0;

	scanf("%d", &num1);

	int i = 0;
	do
	{
		sum = sum + i; //���� �� + ���� �� �ٽ� ����
		i++;
	} while (i <= num1);

	printf("%d\n", sum);

	return 0;
}