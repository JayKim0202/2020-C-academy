/*1.c,d
2.c
3.720*/

//���� �ҽ� �ڵ带 �ϼ��Ͽ� 1, 2, 3�� �� �ٿ� ��µǰ� ���弼��.

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