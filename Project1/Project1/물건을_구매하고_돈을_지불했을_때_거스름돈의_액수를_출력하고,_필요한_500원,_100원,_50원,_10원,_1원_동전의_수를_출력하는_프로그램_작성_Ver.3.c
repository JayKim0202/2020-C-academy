#include <stdio.h>
#include <math.h>

int main()
{
	int paid;
	int need;
	int quotient;
	int num;

	printf("������ �ݾ�: ");
	scanf("%d", &paid);
	printf("������ �ݾ�: ");
	scanf("%d", &need);

	quotient = paid - need;
	printf("�Ž����� : %d��\n", quotient);

	num = quotient / 500;
	printf("500��: %d��\n", num);
	quotient %= 500;

	num = quotient / 100;
	printf("100��:%d��\n", num);
	quotient %= 100;

	num = quotient / 50;
	printf("50��: %d��\n", num);
	quotient %= 50;

	num = quotient / 10;
	printf("10��: %d��\n", num);
	quotient %= 10;

	num = quotient / 5;
	printf("5��: %d��\n", num);
	quotient %= 5;

	printf("1��: %d��\n", quotient);

	return 0;
}