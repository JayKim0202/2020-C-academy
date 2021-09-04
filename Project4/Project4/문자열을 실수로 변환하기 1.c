#include <stdio.h>
#include <stdlib.h> //atof 함수가 선언된 헤더 파일

int main()
{
	char* s1 = "35.283672";
	float num1;

	num1 = atof(s1);

	printf("%f\n", num1);

	return 0;
}