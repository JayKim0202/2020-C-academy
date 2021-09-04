#include <stdio.h>

static int num1 = 10;	//파일 제한(extern사용 불가)

void printNumber()
{
	printf("%d\n", num1);	//정적 전역 변수 num1의 값 출력
}