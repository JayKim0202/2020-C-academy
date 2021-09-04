#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void get_lcm_gcd(int x, int y, int* p_lcm, int* p_gcd);

int main()
{
	int x, y, lcm, gcd;

	printf("�ΰ��� ������ �Է��Ͻÿ�: ");
	scanf("%d %d", &x, &y);

	get_lcm_gcd(x, y, &lcm, &gcd);

	printf("�ּҰ������ %d�Դϴ�.\n", lcm);
	printf("�ִ������� %d�Դϴ�.\n", gcd);

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