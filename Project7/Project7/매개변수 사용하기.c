#include <stdio.h>

void helloNumber(int num1)	//��ȯ�� ����, int�� �Ű����� �� �� ����
{
	printf("Hello, %d\n", num1);	//Hello, �� �Ű������� �����Ͽ� ���ڿ� ���
}

int main()
{
	helloNumber(10);
	helloNumber(20);

	return 0;
}