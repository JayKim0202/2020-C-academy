#include <stdio.h>

int main()
{
	int year = 2020;
	int month;
	int day;

	printf("%d\n", year);

	for (month = 1; month <= 12; month++)
	{
		for (int i = 0; i < 25; i++)
		{
			printf("-");
		}

		printf("\n%d\n", month);

		for (int i = 0; i < 25; i++)
		{
			printf("-");
		}

		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			for (day = 1; day < 31; day++)
			{
				printf("\n%d\n", day);
			}
		}
		else if (month == 2)
		{
			for (day = 1; day < 29; day++)
			{
				printf("\n%d\n", day);
			}
		}
		else
		{
			for (day = 1; day < 30; day++)
			{
				printf("\n%d\n", day);
			}
		}


	}

	return 0;
}