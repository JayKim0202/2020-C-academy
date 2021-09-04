#include <stdio.h>
#include <stdbool.h>

float realNumber()
{
	return 1.234567f;
}

bool truth()
{
	return true;
}

int main()
{
	float num1;
	bool b1;

	num1 = realNumber();	//float형으로 반환했으므로 float형 변수에 저장
	b1 = truth();			//bool형으로 반환했으므로 bool형 변수에 저장

	printf("%f\n", num1);
	printf("%d\n", b1);

	return 0;
}