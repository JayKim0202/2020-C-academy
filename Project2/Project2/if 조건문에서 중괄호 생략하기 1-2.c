#include <stdio.h>

int main()
{
	int num1 = 10;

	if (num1 == 10)
		printf("if 조건문\n"); //if에서 중괄호를 생략하면 첫 번쨰 줄만 실행된다.
		printf("10입니다.\n"); //중괄호가 없으므로 if의 결과와 상관없이 항상 실행된다.

	return 0;
}