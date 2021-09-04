/*1.c,d
2.c
3.720*/

//다음 소스 코드를 완성하여 1, 2, 3이 각 줄에 출력되게 만드세요.

#include <stdio.h>

void printNumber(int count)
{
	if (count == 4)
		return;

	printf("%d\n", count);

	printNumber(++count);
}

int main()
{
	int count = 1;

	printNumber(count);

	return 0;
}