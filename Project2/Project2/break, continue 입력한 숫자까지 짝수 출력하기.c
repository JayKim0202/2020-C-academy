#include <stdio.h>

int main()
{
	int count;

	scanf("%d", &count);

	for (int i = 1; i <= count; i++)
	{
		if (i % 2 != 0)
			continue; //i�� 2�� �������� �� �������� 0�� �ƴϸ� ��, Ȧ���̸� �Ʒ� �ڵ带 �������� �ʰ� �ǳʶ�

			printf("%d\n", i);
	}

	return 0;
}