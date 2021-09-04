#include <stdio.h>

int main()
{
	/*표준 입력으로 국어, 영어, 수학, 과학 접수가 입력됩니다. 여기서 네 과목의 평균 점수가 85점 이상일 때 합격이라고 정했습니다.
	평균 점수에 따라 "합격", "불합격"을 출력하는 프로그램을 만드세요.
	단, 점수는 0점부터 100점까지만 입력받을 수 있으며 범위를 벗어났다면 "잘못된 점수"를 출력하고 함격, 불합격 여부는 출력하지 않아야 합니다.
	
	ex1) 표준 입력 : 95 80 87 82
	     표준 출력 : 합격
		 
	ex2) 표준 입력 : 95 79 83 81
	     표준 출력 : 불합격*/

	int kor;
	int math;
	int eng;
	int sci;
	int num1;

	scanf("%d", &kor);
	scanf("%d", &math);
	scanf("%d", &eng);
	scanf("%d", &sci);

	num1 = (kor + math + eng + sci) / 4;

	if (num1 >= 85 && num1 <=100)
		printf("합격");
	else if (num1 < 85)
		printf("불합격");
	else if (kor > 100 || math > 100 || eng > 100 || sci > 100)
		printf("잘못된 점수");

	return 0;

}