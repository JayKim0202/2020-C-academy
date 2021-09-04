#include <stdio.h>

int main()
{
	/*표준 입력으로 세 정수가 입력됩니다. 다음 순서대로 연산한 뒤 결과가 출력되게 만드세요.
	1. num1과 num2를 더하기
	2. 1번 결과에 10을 곱하기
	3. 2번 결과에서 num3을 빼기*/

	int num1;
	int num2;
	int num3;

	scanf("%d", &num1);
	scanf("%d", &num2);
	scanf("%d", &num3);

	printf("%d\n", (num1 + num2) * 10 - num3);

	return 0;
}