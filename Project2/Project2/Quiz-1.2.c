#include <stdio.h>

int main()
{
	//���� �ҽ� �ڵ带 �ϼ��Ͽ� ���� 2 5, 4 4, 8 3, 16 2, 32 1�� ���ٿ� ��µǰ� ���弼��.

	for ( int i = 2, j = 5; i <= 32; i *= 2, j--)
	{
		printf("%d %d\n", i, j);
	}

	return 0;
}