#include <stdio.h>

int main()
{
	//���� �ҽ� �ڵ带 �ϼ��Ͽ� 1 �� 103 ������ ���� �� 3���� ������ ���ڸ� ��µǰ� ���弼��.

	int i = 1;

	for (;;)
	{
		if (i % 10 != 3)
		{
			i++;
			continue;
		}

		if (i > 103)
			break;

		printf("%d ", i);
		i++;
	}

	return 0;
}