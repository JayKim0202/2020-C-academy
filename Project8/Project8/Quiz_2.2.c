//ǥ�� �Է����� ���� �� ���� �Էµ˴ϴ�. ���� �ҽ� �ڵ带 �ϼ��Ͽ� �Էµ� ������ŭ 2���� ��ǥ�� �̵��ϰ� ���弼��. ���� ��ǥ(x, y)�� 10, 20�Դϴ�.

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