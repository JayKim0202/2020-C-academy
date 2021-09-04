#include <stdio.h>

int main()
{
	float num1; //자료형이 double일때는 %1f

	printf("실수를 입력하세요: ");
	scanf("%f", &num1);

	printf("%f\n", num1);

	return 0;
}