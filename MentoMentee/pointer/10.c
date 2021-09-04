#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void get_lcm_gcd(int x, int y, int* p_lcm, int* p_gcd);

int main()
{
	int x, y, lcm, gcd;

	printf("두개의 정수를 입력하시오: ");
	scanf("%d %d", &x, &y);

	get_lcm_gcd(x, y, &lcm, &gcd);

	printf("최소공배수는 %d입니다.\n", lcm);
	printf("최대공약수는 %d입니다.\n", gcd);

	return 0;
}

void get_lcm_gcd(int x, int y, int* p_lcm, int* p_gcd)
{
	int temp, mod;
	int mul = x * y;

	if (x < y)
	{
        temp = x;
        x = y;
        y = temp;
	}

    while (y != 0)
    {
        mod = x % y;
        x = y;
        y = mod;
    }

    *p_gcd = x;
	*p_lcm = mul / *p_gcd;
}