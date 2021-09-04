//표준 입력으로 정수 두 개가 입력됩니다(입력 값의 범위는 int의 범위와 같음). 다음 소스 코드를 완성하여 입력된 두 정수를 나누었을 때 몫과 나머지가 출력되게 만드세요.
//함수의 반환값과 매개변수를 모두 활용하여 값을 꺼내와야 합니다.

//10 3
//3 1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int getQuotientAndRemainder(int a, int b, int* r)
{
	*r = a % b;

	return a / b;
}


int main()
{
	int num1;
	int num2;
	int quotient;	//몫
	int remainder;	//나머지

	scanf("%d %d", &num1, &num2);	//10 3

	quotient = getQuotientAndRemainder(num1, num2, &remainder);

	printf("%d %d\n", quotient, remainder);

	return 0;
}