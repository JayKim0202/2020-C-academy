//다음 소스 코드를 완성하여 1 2 3 4 5 6 7 8 9 10 11 12가 출력되게 만드세요.

#include <stdio.h>

typedef enum _Month {
	Jan = 1,
	Feb,
	Mar,
	Apr,
	May,
	Jun,
	Jul,
	Aug,
	Sep,
	Oct,
	Nov,
	Dec,
	MonthCount
} Month;

int main()
{
	for (Month i = Jan; i < MonthCount; i++)
	{
		printf("%d ", i);
	}

	return 0;
}