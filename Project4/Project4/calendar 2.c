#include <stdio.h>

int main()
{
	int year = 2020;
	int month;
	int i;
	int day;

	printf("%d��\n", year);

	for (month = 1; month <= 12; month++)
	{
		for (i = 0; i < 50; i++)
		{
			printf("-");
		}

		printf("\n\n%d��\n", month);

		for (i = 0; i < 50; i++)
		{
			printf("-");
		}

		printf("\n��\t��\tȭ\t��\t��\t��\t��\n");

		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			for (day = 1; day < 32; day++)
			{
				if (day % 8 == 0)
					printf("\n");
				else if (day != 31)
					printf("%d\t", day);
				else if (day == 31)
					printf("%d\n", day);
			}
		}

		else if (month == 2)
		{
			for (day = 1; day < 30; day++)
			{
				if (day % 8 == 0)
					printf("\n");
				else if (day != 29)
					printf("%d\t", day);
				else if (day == 29)
					printf("%d\n", day);
			}
		}

		else
		{
			for (day = 1; day < 31; day++)
			{
				if (day % 8 == 0)
					printf("\n");
				else if (day != 30)
					printf("%d\t", day);
				else if (day == 30)
					printf("%d\n", day);
			}
		}
	}



	return 0;
}