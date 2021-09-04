//표준입력으로 두 정수가 입력됩니다(입력 값의 범위는 long long의 범위와 같음). 다음 소스 코드를완성하여 두 정수의 합이 출력되게 만드세요.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long add(long long a, long long b)
{
	return a + b;
}

int main()
{
	long long num1, num2;

	scanf("%lld %lld", &num1, &num2);	//1586727174858192858 4581287173895719283

	printf("%lld\n", add(num1, num2));

	return 0;
}