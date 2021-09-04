//표준 입력으로 정수 네 개각 입력됩니다. 다음 소스 코드를 완성하여 입력된 정수만큼 좌표를 이동시키도록 만드세요.
//첫 번째 정수는 점의x, 두 번째 정수는 점의y, 세 번째 정수는 이동할 x값, 네 번째 정수는 이동할 y값입니다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Point2D {
	int x;
	int y;
};

int movePoint2D(struct Point2D *p, int X, int Y)
{
	p->x = p->x + X;
	p->y = p->y + Y;
}

int main()
{
	struct Point2D p1;
	int offsetX, offsetY;

	scanf("%d %d %d %d", &p1.x, &p1.y, &offsetX, &offsetY);

	movePoint2D(&p1, offsetX, offsetY);

	printf("%d %d\n", p1.x, p1.y);

	return 0;
}