#include <stdio.h>

int main()
{
	/*ǥ�� �Է����� �� ������ ���� �ϳ��� �Էµ˴ϴ�. �Էµ� ������ �� �ڸ����� �������� ����ϴ� ���α׷��� ���弼��(scanf �Լ� ���� ���ڿ��� ����ϸ� �� �˴ϴ�).
	���� ��� 43561�̶�� 1 6 5 3 4�� ����ϸ� �˴ϴ�. �� �ڸ����� �������� ��켼��.*/

	int num1;
	int num11;
	int num2;
	int num22;
	int num3;
	int num33;
	int num4;
	int num44;
	int num5;

	scanf("%d", &num1); //43561

	num11 = num1 % 10; //1
	printf("%d ", num11); //1
	num2 = num1 / 10; //4356

	num22 = num2 % 10; //6
	printf("%d ", num22); //6
	num3 = num2 / 10; //435

	num33 = num3 % 10; //5
	printf("%d ", num33); //5
	num4 = num3 / 10; //43

	num44 = num4 % 10; //3
	printf("%d ", num44); //3
	num5 = num4 / 10; //4

	printf("%d\n", num5); //4

	//��ĵ, ������, ��  3���� �����θ��� ����

	return 0;
}