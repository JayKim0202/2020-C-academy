#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_line(int x1, int y1, int x2, int y2, float* slope, float* y_intercept);

int main()
{
	int x1, x2, y1, y2;
	float slope, y_intercept;

	printf("x1: ");
	scanf("%d", &x1);
	printf("y1: ");
	scanf("%d", &y1);
	printf("x2: ");
	scanf("%d", &x2);
	printf("y2: ");
	scanf("%d", &y2);

	if (get_line(x1, y1, x2, y2, &slope, &y_intercept))
		printf("기울기 : %f, y절편 : %f\n", slope, y_intercept);
	else
		printf("error");

	return 0;
}

int get_line(int x1, int y1, int x2, int y2, float* slope, float* y_intercept)
{
	if (x1 == x2)
		return 0;

	*slope = (float)(y2 - y1) / (float)(x2 - x1);
	*y_intercept = (float)y1 - ((*slope) * (float)x1);

	return 1;
}