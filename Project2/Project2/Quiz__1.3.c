#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*표준 입력으로 정수가 입력됩니다(입력 값의 범위는 0~1000). 다음 소스코드를 완성하여 0부터 입력된 숫자까지의 합이 출력되게 만드세요.*/

	int num1;
	int sum = 0;

	scanf("%d", &num1);

	int i = 0;
	do
	{
		sum = sum + i; //기존 값 + 변수 후 다시 저장
		i++;
	} while (i <= num1);

	printf("%d\n", sum);

	return 0;
}