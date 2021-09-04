#include <stdio.h>

int main()
{
	int numArr[10];

	numArr[0] = 11;
	numArr[1] = 22;
	numArr[2] = 33;
	numArr[3] = 44;
	numArr[4] = 55;
	numArr[5] = 66;
	numArr[6] = 77;
	numArr[7] = 88;
	numArr[8] = 99;
	numArr[9] = 110;

	printf("%d\n", numArr[-1]); //음수이므로 잘못된 인덱스
	printf("%d\n", numArr[10]); //배열의 범위를 벗어난 인덱스
	printf("%d\n", numArr[20]); //배열의 범위를 벗어난 인덱스
}