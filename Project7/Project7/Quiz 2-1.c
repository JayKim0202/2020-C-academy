/*1.e
2.c
3.b,d,e,*/

//다음 소스 코드를 완성하여 10 20 30이 출력되게 만드세요. 함수의 반환값으로 값을 한 개 꺼내고 매개변수로 값을 두 개 꺼내야 합니다.

#include <stdio.h>

int getNumber(int* a, int* b)
{
	*a = 10;
	*b = 20;
	return *a + *b;
}



int main()
{
	int num1 = 0;
	int num2 = 0;
	int result = 0;

	result = getNumber(&num1, &num2);

	printf("%d %d %d\n", num1, num2, result);

	return 0;
}