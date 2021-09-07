#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.14

typedef struct point {
	int x, y;
} P;

typedef struct circle {
	P center;
	double radius;
} C;

double area(C c);
double perimeter(C c);

int main()
{
	C c;
	double A;
	double P;

	printf("원의 중심점: ");
	scanf("%d %d", &c.center.x, &c.center.y);
	printf("원의 반지름: ");
	scanf("%lf", &c.radius);

	A = area(c);
	P = perimeter(c);

	printf("원의 면적=%lf, 원의 둘레=%lf", A, P);

	return 0;
}

double area(C c)
{
	return PI * c.radius * c.radius;
}

double perimeter(C c)
{
	return 2 * c.radius * PI;
}