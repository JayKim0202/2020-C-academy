#include <stdio.h>

#define PRINT_NUM3(x) printf("%d\n", x);\ //첫줄만 if의 영향을 받음
printf("%d\n", x + 1);\	//두 번째 세번째 줄은 if의 조건과는 상관없이 무조건 실행됨
printf("%d\n", x + 2);\

int main()
{
	int num1 = 1;

	if (num1 == 2)
		PRINT_NUM3(10);	//두 번째와 세 번째 줄도 if의 영햐을 받게 하려면 중괄호로 묶어줘야함.

	return 0;
}