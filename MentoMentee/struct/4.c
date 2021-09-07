#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct complex {
	double real;
	double imag;
};

struct complex complex_add(struct complex c1, struct complex c2);

int main()
{
	struct complex c1;
	struct complex c2;
	struct complex result;
	char temp;

	c1.real = 1;
	c1.imag = 2;
	c2.real = 2;
	c2.imag = 3;
	//scanf("%lf%c%lf%c", &c1.real, &temp, &c1.imag, &temp);
	//scanf("%lf%c%lf%c", &c2.real, &temp, &c2.imag, &temp);
	printf("%lf+%lfi\n", c1.real, c1.imag);
	printf("%lf+%lfi\n", c2.real, c2.imag);
	result = complex_add(c1, c2);
	printf("%lf+%lfi", result.real, result.imag);

	return 0;
}

struct complex complex_add(struct complex c1, struct complex c2)
{
	struct complex result;
	
	result.real = c1.real + c2.real;
	result.imag = c1.imag + c2.imag;

	return result;
}