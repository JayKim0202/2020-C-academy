//달력 (윤년 함수, 출력 함수) 년도 입력, 년도 전체보기, 년도 월 입력, 종료, 윤년 여부확인;

#define _CRT_SECUCRE_NO_WARNINGS
#include <stdio.h>

int checkLeapYear(int y, int *leapYear)
{
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
    {
        leapYear = 1;
    }
    else
    {
        leapYear = 0;
    }
}

int year()
{
    int year;
    int month[13] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int totalday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int leapYear;
    int lastYear;
    int allday;

    printf("년도를 입력하세요: ");
    scanf("%d", &year);

    checkLeapYear(year, &leapYear);

    if (leapYear == 1 && month[2])
    {
        totalday[2] = 29;
    }

    lastYear = year - 1;
    allday = lastYear + (lastYear / 4) - (lastYear / 100) + (lastYear / 400) + 1;

    for (int i = 1; i < month; i++)
    {
        allday += (totalday[i]);
    }


}


int main()
{
    int option;

	printf("다음 옵션을 선택하세요 : 1. 전체 달력보기, 2.월 달력보기\n");
    printf("1/2\n");
    scanf("%d", &option);

    switch (option)
    {
    case(1):
    {
        year();
        break;
    }
    case(2):
    {
        break;
    }
    }
}