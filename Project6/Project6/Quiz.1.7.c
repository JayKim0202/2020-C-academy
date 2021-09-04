//표준 입력으로 실수가 입력됩니다. 다음 소스 코드르롼성하여 입력된 실수가 그대로 출력되게 만드세요.

#define  _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>

int main()
{
	long double* numPtr1 = malloc(sizeof(long double));
	void* ptr;

	scanf("%Lf", numPtr1);

	ptr = numPtr1;

	printf("%Lf\n", *(long double*)ptr);

	free(numPtr1);

	return 0;
}