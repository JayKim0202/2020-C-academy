#include <stdio.h>
#include <math.h>

int main()
{
	int num1; //지불한 액수
	float num2; //거스름돈의 액수
	float num3; //500원 갯수
	float num4; //100원 갯수
	float num5; //50원 갯수
	float num6; //10원 갯수
	int num7; //지불해야 할 액수

	printf("지불한 액수: ");
	scanf("%d", &num1);
	
	printf("지불해야 할 액수: ");
	scanf("%d", &num7);

	num2 = num1 - num7;

	printf("거스름돈 : %f원\n", num2);

	num3 = num2 / 500;
	printf("500원 : %f개\n", num3);

	num4 = num2 / 100;
	printf("100원 : %f개\n", num4);

	num5 = num2 / 50;
	printf("50원 : %f개\n", num5);

	num6 = num2 / 10;
	printf("10원 : %f개\n", num6);

	printf("1원 : %f개\n", num2);

	return 0;
}