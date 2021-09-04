#include <stdio.h>

int main()
{
	/*표준 입력으로 만 단위의 정수 하나가 입력됩니다. 입력된 정수의 각 자릿수를 역순으로 출력하는 프로그램을 만드세요(scanf 함수 전에 문자열을 출력하면 안 됩니다).
	예를 들어 43561이라면 1 6 5 3 4를 출력하면 됩니다. 각 자릿수는 공백으로 띄우세요.*/

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

	//스캔, 나머지, 몫  3가지 변수로만도 가능

	return 0;
}