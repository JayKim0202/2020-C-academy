#include <stdio.h>

#define PRINT_NUM3(x) printf("%d\n", x);\ //ù�ٸ� if�� ������ ����
printf("%d\n", x + 1);\	//�� ��° ����° ���� if�� ���ǰ��� ������� ������ �����
printf("%d\n", x + 2);\

int main()
{
	int num1 = 1;

	if (num1 == 2)
		PRINT_NUM3(10);	//�� ��°�� �� ��° �ٵ� if�� ������ �ް� �Ϸ��� �߰�ȣ�� ���������.

	return 0;
}