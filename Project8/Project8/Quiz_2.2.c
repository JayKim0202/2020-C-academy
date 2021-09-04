//표준 입력으로 정수 한 개가 입력됩니다. 다음 소스 코드를 완성하여 입력된 정수만큼 2차원 좌표가 이동하게 만드세요. 최초 좌표(x, y)는 10, 20입니다.

/*
12 22
14 24
16 26
*/

#define _CRT_SECURE_NO_WANINGS
#include <stdio.h>

struct Point2D {
	int x, y;
};

struct Point2D movePoint(int num)
{
	static struct Point2D p1 = { 10, 20 };

	p1.x = p1.x + num;
	p1.y = p1.y + num;

	num += 2;

	return p1;
}


int main()
{
	int num1;
	struct Point2D p;

	scanf("%d", &num1);

	p = movePoint(num1);
	printf("%d %d\n", p.x, p.y);

	p = movePoint(num1);
	printf("%d %d\n", p.x, p.y);

	p = movePoint(num1);
	printf("%d %d\n", p.x, p.y);

	return 0;
}