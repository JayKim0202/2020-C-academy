#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int checkLeapYear(int y)
{
	int leapYear;

	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
	{
		leapYear = 1;
	}
	else
	{
		leapYear = 0;
	}

	return leapYear;
}

void entirety(int year)
{
	int month = 1;
	int lastday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int startday;
	int allday = 0;
	int leapyear;
	int plusDays;

	leapyear = checkLeapYear(year);

	if (leapyear == 1)
	{
		lastday[2] = 29;
	}

	allday += ((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400);

	plusDays = allday;

	printf("%d\n", year);
	

	while (1)
	{
		printf("\n======================================");
		printf("\n%d\n", month);
		printf("+++++++++++++++++++++++++++++++++++++\n");
		printf("월\t화\t수\t목\t금\t토\t일\n");
		
		plusDays += lastday[month - 1];
		startday = plusDays % 7;
		for (int i = 0; i < startday; i++)
		{
			printf("\t");
		}
		for (int i = 1; i <= lastday[month]; i++)
		{
			printf("%d\t", i);

			if ((i + startday) % 7 == 0)
			{
				printf("\n");
			}
		}
		month++;
		if (month == 13)
		{
			break;
		}
	}

	if (leapyear == 1)
	{
		printf("\n%d년도는 윤단이 포함되어 있습니다.", year);
	}
}

void month(int year)
{
	int month = 1;
	int lastday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int startday;
	int allday = 0;
	int leapyear;
	int plusDays;
	int empty;

	leapyear = checkLeapYear(year);

	if (leapyear == 1)
	{
		lastday[2] = 29;
	}

	allday += (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;

	plusDays = allday;

	printf("출력할 월을 입력하세요: ");
	scanf("%d", &month);
	scanf("%c", &empty);

	printf("%d\n", year);
	printf("======================================\n");

	printf("%d\n", month);
	printf("+++++++++++++++++++++++++++++++++++++\n");
	printf("월\t화\t수\t목\t금\t토\t일\n");

	for (int i = 0; i < month; i++)
	{
		plusDays += lastday[i];
	}
	startday = plusDays % 7;

	for (int i = 0; i < startday; i++)
		{
		printf("\t");
		}
	for (int i = 1; i <= lastday[month]; i++)
		{
		printf("%d\t", i);

		if ((i + startday) % 7 == 0)
			{
			printf("\n");
			}
		}

	if (leapyear == 1 && month == 2)
	{
		printf("\n%년도 2월은 윤달입니다.", year);
	}
}


int main()
{
	int year;
	char empty;
	char option;
	char button;

	while (1)
	{
		printf("년도를 입력하세요: ");
		scanf("%d", &year);
		scanf("%c", &empty);

		printf("전체를 보시겠습니까? (y/n)");
		scanf("%c", &option);
	

		switch (option)
		{
		case'y':
		{
			entirety(year);
			scanf("%c", &empty);
			break;
		}
		case'n':
		{
			month(year);
			break;
		}
		}

		printf("\n종료하시려면 q를 눌러주세요.\n");
		printf("계속하려면 아무키나 눌러주세요.\n");
		scanf("%c", &button);
		if (button == 'q')
		{
			break;
		}
	}

	return 0;
}