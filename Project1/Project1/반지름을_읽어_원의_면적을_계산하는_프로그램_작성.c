#include <stdio.h>
#include <math.h>

int main()
{
	float diameter;
	float radius = 3.14;
	float area;

	scanf("%f", &diameter);
	
	area = (diameter / 2) * (diameter / 2) * radius;

	printf("%f\n", area);

	return 0;
}