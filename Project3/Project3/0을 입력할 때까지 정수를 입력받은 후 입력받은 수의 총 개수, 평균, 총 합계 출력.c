#include <stdio.h>

int main()
{
	int i;
	int num = 0;
	int average;
	int sum = 0;

	do
	{
		scanf("%d", &i);
		sum = sum + i;

		if (i != 0)
		{
			num++;
		}

	} while (i != 0);

	average = sum / num;


		printf("개수 : %d, 평균 : %d, 합계 : %d\n", num, average, sum);

	return 0;
}