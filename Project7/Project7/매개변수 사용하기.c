#include <stdio.h>

void helloNumber(int num1)	//변환값 없음, int형 매개변수 한 개 지정
{
	printf("Hello, %d\n", num1);	//Hello, 와 매개변수를 조합하여 문자열 출력
}

int main()
{
	helloNumber(10);
	helloNumber(20);

	return 0;
}