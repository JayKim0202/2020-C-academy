//ǥ�� �Է����� ���� �� ���� �Էµ˴ϴ�. ���� �ҽ� �ڵ带 �ϼ��Ͽ� �Էµ� ������ŭ ��ǥ�� �̵���Ű���� ���弼��.
//ù ��° ������ ����x, �� ��° ������ ����y, �� ��° ������ �̵��� x��, �� ��° ������ �̵��� y���Դϴ�.

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