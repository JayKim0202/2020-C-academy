#include <stdio.h>

int main()
{
	/*ǥ�� �Է����� ������ �Էµ˴ϴ�. ���� �ҽ� �ڵ带 �ϼ��Ͽ� �Էµ� ������ ��µǰ� ���弼��.*/

	int* numPtr1;
	int num1;

	scanf("%d", &num1);

	numPtr1 = &num1;

	printf("%d", *numPtr1);

	return 0;
}