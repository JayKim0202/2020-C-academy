/*1.c,d
2.a,e
3.b,d,e
4.e*/

//다음 소스 코드를 완성하여 10 20과 30 40이 각 줄에 출력되게 만드세요.

#include <stdio.h>

struct Point2D {
	int x;
	int y;
};

struct Point2D p1 = { 10, 20 };

void printPoint2D()
{
	printf("%d %d\n", p1.x, p1.y);
}

int main()
{
	printf("%d %d\n", p1.x, p1.y);

	p1.x = 30;
	p1.y = 40;
	printPoint2D();

	return 0;
}