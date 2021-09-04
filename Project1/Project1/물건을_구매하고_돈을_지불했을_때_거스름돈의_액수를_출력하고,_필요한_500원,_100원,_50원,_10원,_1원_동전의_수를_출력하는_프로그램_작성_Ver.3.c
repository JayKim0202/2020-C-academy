#include <stdio.h>
#include <math.h>

int main()
{
	int paid;
	int need;
	int quotient;
	int num;

	printf("지불한 금액: ");
	scanf("%d", &paid);
	printf("지불할 금액: ");
	scanf("%d", &need);

	quotient = paid - need;
	printf("거스름돈 : %d원\n", quotient);

	num = quotient / 500;
	printf("500원: %d개\n", num);
	quotient %= 500;

	num = quotient / 100;
	printf("100원:%d개\n", num);
	quotient %= 100;

	num = quotient / 50;
	printf("50원: %d개\n", num);
	quotient %= 50;

	num = quotient / 10;
	printf("10원: %d개\n", num);
	quotient %= 10;

	num = quotient / 5;
	printf("5원: %d개\n", num);
	quotient %= 5;

	printf("1원: %d개\n", quotient);

	return 0;
}