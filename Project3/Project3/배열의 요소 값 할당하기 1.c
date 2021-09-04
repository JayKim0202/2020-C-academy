#include <stdio.h>

int main()
{
	int numArr[10]; //크기가 10인 배열 선언

	numArr[0] = 11; //인덱스가 0인 배열의 요소에 값 할당
	numArr[1] = 22;
	numArr[2] = 33;
	numArr[3] = 44;
	numArr[4] = 55;
	numArr[5] = 66;
	numArr[6] = 77;
	numArr[7] = 88;
	numArr[8] = 99;
	numArr[9] = 110;

	printf("%d\n", numArr[0]);
	printf("%d\n", numArr[5]);
	printf("%d\n", numArr[9]);

	return 0;
}