/*���� �ҽ� �ڵ带 �ϼ��Ͽ� 2���� �¤Ф� x, y�� ǥ���ϴ� ����ü�� �����ϰ�, 10 20�� ��µǰ� ���弼��.
��ǥ�� �ڷ����� int�Դϴ�.*/
#include <stdio.h>

typedef struct _Point2D {
	int x;
	int y;
} Point2D;

int main()
{
	Point2D p1;

	p1.x = 10;
	p1.y = 20;

	printf("%d %d\n", p1.x, p1.y);

	return 0;
}