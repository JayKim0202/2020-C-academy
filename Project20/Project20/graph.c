#include <stdio.h>

//enum Alphabet { A, B, C, D };

int main()
{
	int graph[4][4] = { 0 };
	int row;
	int col;
	int q = 0;

	while (1)
	{
		printf("row : ");
		scanf("%d", &row);
		printf("column: ");
		scanf("%d", &col);
		getchar();

		graph[row - 1][col - 1] = 1;

		/*printf("�����Ϸ��� q�� ��������...(�ƴ϶��  ���͸� ��������)");
		scanf("%c", &q);*/

		if (row == 4)
		{
			printf("1�� ������ ����˴ϴ�.");
			scanf("%d", &q);
		}
		if (q == 1)break;
	}

	for (int i = 0; i < 4; i++)
	{
		printf("%d : ", i + 1);

		for (int j = 0; j < 4; j++)
		{
			if (graph[i][j] == 1)
			{
				printf("\t%d", j + 1);
			}
		}
		printf("\n");
	}

	return 0;
}

/*int graph[4][4] = { 0 };

	graph[0][0] = 0;
	graph[0][1] = 1;
	graph[0][2] = 1;
	graph[0][3] = 1;

	graph[1][0] = 1;
	graph[1][1] = 0;
	graph[1][2] = 1;
	graph[1][3] = 0;

	graph[2][0] = 1;
	graph[2][1] = 1;
	graph[2][2] = 0;
	graph[2][3] = 1;

	graph[3][0] = 1;
	graph[3][1] = 0;
	graph[3][2] = 1;
	graph[3][3] = 0;*/