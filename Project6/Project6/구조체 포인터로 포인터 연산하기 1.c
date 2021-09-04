#include <stdio.h>

struct Data {
	int num1;
	int num2;
};

int main()
{
	struct Data d[3] = { { 10, 20 }, { 20, 40 }, { 50, 60 } };
	struct Data* ptr;

	ptr = d;

	printf("%d %d\n", (ptr + 1)->num1, (ptr + 1)->num2);	//30 40: 구조체 배열에서 멤버의 값 출력

	printf("%d %d\n", (ptr + 1)->num1, (ptr + 2)->num2);	//50 60: 구조체 배열에서 멤버의 값 출력

	return 0;
}