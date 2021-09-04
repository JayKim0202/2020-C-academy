#include <stdio.h>
#include <math.h>

int main()
{
	int num1; //지불한 금액       60000원
	int num2; //지불해야할 금액   59661원
	int remainder; //거스름돈          339원
	int num4; //500원            0개
	int num5; //100원            3개
	int num6; //50원             0개
	int num7; //10원             3개

	printf("지불한 금액: ");
	scanf("%d", &num1); //키보드 60000원 입력
	printf("지불해야할 금액: ");
	scanf("%d", &num2); //키보드 59661원 입력

	remainder = num1 - num2;
	printf("거스름돈: %d\n", remainder); //339원
	
	num4 = remainder / 500;
	printf("500원: %d개\n", num4); //0
	remainder = remainder - (num4 * 500); //339 - 0

	num5 = remainder / 100;
	printf("100원 : %d\n", num5); //3개
	remainder = remainder - (num5 * 100); //339 - 3 * 100 = 39

	num6 = remainder / 50;
	printf("50원: %d\n", num6); //0개
	remainder = remainder - (num6 * 50); //39 - 0 * 50 = 39

	num7 = remainder / 10;
	printf("10원: %d\n", num7); //3개
	remainder = remainder - (num7 * 10); //39 - 3 * 10 = 9

	printf("1원: %d\n", remainder); //9

	return 0;
}