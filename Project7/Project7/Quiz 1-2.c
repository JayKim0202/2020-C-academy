//다음 소스 코드를완성하여 0.900000이 출력되게 만드세요.

#include <stdio.h>

float sub(float a, float b)
{
	return a - b;
}

int main()
{
	float num1;

	num1 = sub(1.0f, 0.1f);

	printf("%f\n", num1);

	return 0;
}