#include <stdio.h>

int main()
{
	/*ǥ�� �Է����� �� ������ ���� �ϳ��� �Էµ˴ϴ�. �Էµ� ������ �� �ڸ����� �������� ����ϴ� ���α׷��� ���弼��(scanf �Լ� ���� ���ڿ��� ����ϸ� �� �˴ϴ�).
	���� ��� 43561�̶�� 1 6 5 3 4�� ����ϸ� �˴ϴ�. �� �ڸ����� �������� ��켼��.*/

	int scan;
	int remainder; //������
	int quotient; //��

	printf("�ټ��ڸ����ڸ� �Է��Ͻÿ�: ");
	scanf("%d", &scan); // 43561

	remainder = scan % 10;
	printf("%d ", remainder);
	quotient = scan / 10; //4356

	remainder = quotient % 10;
	printf("%d ", remainder);
	quotient = quotient / 10; //435

	remainder = quotient % 10;
	printf("%d ", remainder);
	quotient = quotient / 10; //43

	remainder = quotient % 10;
	printf("%d ", remainder);
	quotient = quotient / 10; //4

	printf("%d\n", quotient);

	return 0;
}