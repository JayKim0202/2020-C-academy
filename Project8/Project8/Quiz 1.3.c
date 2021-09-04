//다음 소스 코드를 완성하여 배열의 크기(요소의 개수)가 출력되게 만드세요.

/*
10
5
3
*/

#include <stdio.h>

struct Point2D {
	float x, y;
};

#define ARRSIZE(x) sizeof(x) / sizeof(x[0])

int main()
{
	int numArr1[10];
	long long numArr2[5];
	struct Point2D p[3];

	printf("%d\n", ARRSIZE(numArr1));
	printf("%d\n", ARRSIZE(numArr2));
	printf("%d\n", ARRSIZE(p));

	return 0;
}