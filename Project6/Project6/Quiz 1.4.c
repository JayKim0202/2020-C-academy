//���� �ҽ� �ڵ带 �ϼ��Ͽ� 30 60�� ��µǰ� ���弼��.

#include <stdio.h>

struct Point2D {
	int x;
	int y;
};

int main()
{
	struct Point2D p[3] = { { 10, 20 }, { 30, 40 }, { 50, 60 } };
	struct Point2D* ptr;

	ptr = p;

	printf("%d %d\n", (ptr + 1)->x, (ptr + 2)->y);

	return;
}