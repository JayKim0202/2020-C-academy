#include <stdio.h>

int factorial(int n)	
{
	if (n == 1)
		return 1;

	return n * factorial(n - 1);	// n과 factorial 함수에 n - 1을 넣어서 반환된 값을 곱함;
}

int main()
{
	printf("%d", factorial(6));

	return 0;
}