#include <stdio.h>

extern int num1;	//다른 소스 파일(외부)에 있는 전역 변수 num1을 사용
extern void printNumber();

int main()
{
	printf("%d\n", num1);
	printNumber();

	return 0;
}

//extern main를 사용하려면 extern print를 빌드에 추가해야 한다.