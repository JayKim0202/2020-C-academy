//표준 입력으로 정수 한 개가 입력됩니다(입력 값의 범위는 10~30). 다음 소스 코드를 완성하여 입력된 정수에 해당하는 피보나치 수가 출력되게 만드세요.
// 피보나치 수는 0과 1로 시작하며, 다음번 피보나치 수는 바로 앞의 두 피보나치 수의 합입니다.

/*
10
55*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fib(int n)
{
	if (n == 0)
		return 0;

	return n + fib(n - 1);
}

int main()
{
	int num1;
	scanf("%d", &num1);

	printf("%d\n", fib(num1)); //10

	return 0;
}