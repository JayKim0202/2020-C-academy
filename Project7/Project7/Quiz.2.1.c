/*1.10
2.e*/

//다음 소스 코드를완성하여 Point2D 구조체에 설정된 좌표가 출력되게 만드세요.

#include <stdio.h>

struct Point2D {
	int x;
	int y;
};

void printPoint2D(struct Point2D p)
{
	printf("%d %d\n", p.x, p.y);
}

int main()
{
	struct Point2D p1;

	p1.x = 10;
	p1.y = 20;

	printPoint2D(p1);

	return 0;
}