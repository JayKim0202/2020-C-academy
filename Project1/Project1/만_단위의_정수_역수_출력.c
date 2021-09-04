#include <stdio.h>

int main()
{
	/*표준 입력으로 만 단위의 정수 하나가 입력됩니다. 입력된 정수의 각 자릿수를 역순으로 출력하는 프로그램을 만드세요(scanf 함수 전에 문자열을 출력하면 안 됩니다).
	예를 들어 43561이라면 1 6 5 3 4를 출력하면 됩니다. 각 자릿수는 공백으로 띄우세요.*/

	int scan;
	int remainder; //나머지
	int quotient; //몫

	printf("다섯자리숫자를 입력하시오: ");
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