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

	printf("���� �߽���: ");
	scanf("%d %d", &c.center.x, &c.center.y);
	printf("���� ������: ");
	scanf("%lf", &c.radius);

	A = area(c);
	P = perimeter(c);

	printf("���� ����=%lf, ���� �ѷ�=%lf", A, P);

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