#include <stdio.h>
#include <math.h>

int main()
{
	int num1; //������ �ݾ�       60000��
	int num2; //�����ؾ��� �ݾ�   59661��
	int remainder; //�Ž�����          339��
	int num4; //500��            0��
	int num5; //100��            3��
	int num6; //50��             0��
	int num7; //10��             3��

	printf("������ �ݾ�: ");
	scanf("%d", &num1); //Ű���� 60000�� �Է�
	printf("�����ؾ��� �ݾ�: ");
	scanf("%d", &num2); //Ű���� 59661�� �Է�

	remainder = num1 - num2;
	printf("�Ž�����: %d\n", remainder); //339��
	
	num4 = remainder / 500;
	printf("500��: %d��\n", num4); //0
	remainder = remainder - (num4 * 500); //339 - 0

	num5 = remainder / 100;
	printf("100�� : %d\n", num5); //3��
	remainder = remainder - (num5 * 100); //339 - 3 * 100 = 39

	num6 = remainder / 50;
	printf("50��: %d\n", num6); //0��
	remainder = remainder - (num6 * 50); //39 - 0 * 50 = 39

	num7 = remainder / 10;
	printf("10��: %d\n", num7); //3��
	remainder = remainder - (num7 * 10); //39 - 3 * 10 = 9

	printf("1��: %d\n", remainder); //9

	return 0;
}