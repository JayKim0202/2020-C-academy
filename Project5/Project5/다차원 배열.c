/* 강우량 데이터로부터 각 해의 총 강우량과 몇 년에 걸쳐 계산한 연평균 강우량, 각 달의 월평균 강우량을 구한다.*/
#include <stdio.h>
#define  MONTHS	12			//1년의 달수 
#define  YEARS 5			//데이터를 수집한 햇수

int main(void)
{
	// 2010년에서 2014년까지의 강우량 데이터의 초기화
	const float rain[YEARS][MONTHS] =
	{
		{4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
		{8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
		{9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
		{7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
		{7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
	};
	int year, month;
	float subtot, total;

	printf("년도	   강우량(인치)\n");
	for (year = 0, total = 0; year < YEARS; year++)
	{										//각 해에 대해 12달치 강우량을 더한다.
		for (month = 0, subtot = 0; month < MONTHS; month++)
			subtot += rain[year][month];
		printf("%5d %15.1f\n", 2010 + year, subtot);
		total += subtot;					//여러 해에 걸친 총 강우량을 구한다.
	}

	printf("\n연평균 강우량은 %.1f인치입니다.\n", total / YEARS);
	printf("월평균 강우량은 다음과 같습니다.\n\n");
	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");

	for ( month = 0; month < MONTHS; month++)
	{										//각 달에 대해 5년치 강우량을 더한다.
		for (year = 0, subtot = 0; year < YEARS; year++)
			subtot += rain[year][month];
		printf("%4.1f", subtot / YEARS);
	}
	printf("\n");

	return 0;
}