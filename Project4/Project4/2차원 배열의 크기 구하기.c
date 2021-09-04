#include <stdio.h>

int main()
{
	int numArr[3][4] = {
		{ 11, 22, 33, 44 },
		{ 55, 66, 77, 88 },
		{99, 110, 121, 132}
	};												//세로 크기 3, 가로 크기 4인 int형 2차월 배열 선언

	printf("%d\n", sizeof(numArr));					//48: 4바이트의 크기의 요소가 4 * 3 개 이므로 48

	int col = sizeof(numArr[0]) / sizeof(int);		//4: 2차원 배열의 가로 크기를 구할 때는 가로 한줄의 크기를 요소의 크기로 나눠줌
													//( 4 * 4 ) / 4 = 4

	int row = sizeof(numArr) / sizeof(numArr[0]);	//3: 2차원 배열의 세로 크기를 구할 때는 배열이 차지하는 전체 공간을 가로 할 줄의 크기로 나눠줌
													//( 4 * 4 * 3 ) / ( 4 * 4 )

	printf("%d\n", col); //4
	printf("%d\n", row); //3

	return 0;
}