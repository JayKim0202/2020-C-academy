#include <stdio.h>

//hello와 x를 붙여서 호출하는 EXECUTER 매크로 정의
#define EXECUTER(x) hello##x()

void hello1()
{
	printf("hello 1\n");
}

void hello2()
{
	printf("hello 2\n");
}

int main()
{
	EXECUTER(1);

	EXECUTER(2);

	return 0;
}