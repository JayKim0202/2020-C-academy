#include <stdio.h>

int main()
{
	/*ǥ�� �Է����� �ﰢ���� ���̰� �Էµ˴ϴ�.(�Է� ���� ������ 3~10). �Էµ� ����ĭŭ �� ������� ���� ����ϴ� ���α׷��� ���弼��.
	�̶� ��� ����� ������ ��Ȯ�� ��ġ�ؾ� �մϴ�. ����� ������ �����̳� �� ���� �� ���� Ʋ�� ������ ó���˴ϴ�.*/

	int i;
	int j;
	int height; 

	scanf("%d", &height);

	for (i = 0; i < height; i++) 
	{
		for (j = 0; j <= (10 / 2) - i; j++)
		{
			printf(" ");
		}
		for (j = 10 / 2 - i; j <= (10 / 2) + i; j++)
		{
			printf("*");
		}

		printf("\n");
	}

	return 0;
}

/*for (j = 0; j <= height ; j++)
		{
			if (j )
				printf(" ");
			else if
				printf("*");
			else if
				printf(" ");
		}
		
		
		length = height + 2 * i*/