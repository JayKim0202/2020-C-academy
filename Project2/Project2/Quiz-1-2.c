#include <stdio.h>

int main()
{
	//���� �ҽ��ڵ带 �ϼ��Ͽ� ���ﰢ�� ������� ���� ��µǰ� ���弼��.

	int i;
	int j;
	
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (j < i)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}

	return 0;
}