#include <stdio.h>
#include <math.h>

int main()
{
	int num1; //������ �׼�
	float num2; //�Ž������� �׼�
	float num3; //500�� ����
	float num4; //100�� ����
	float num5; //50�� ����
	float num6; //10�� ����
	int num7; //�����ؾ� �� �׼�

	printf("������ �׼�: ");
	scanf("%d", &num1);
	
	printf("�����ؾ� �� �׼�: ");
	scanf("%d", &num7);

	num2 = num1 - num7;

	printf("�Ž����� : %f��\n", num2);

	num3 = num2 / 500;
	printf("500�� : %f��\n", num3);

	num4 = num2 / 100;
	printf("100�� : %f��\n", num4);

	num5 = num2 / 50;
	printf("50�� : %f��\n", num5);

	num6 = num2 / 10;
	printf("10�� : %f��\n", num6);

	printf("1�� : %f��\n", num2);

	return 0;
}