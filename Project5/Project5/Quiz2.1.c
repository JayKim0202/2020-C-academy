//ǥ�� �Է����� ���� 4���� �ԷµǾ� Point2D ����ü�� ����˴ϴ�. ���� �ҽ� �ڵ带 �ϼ��Ͽ� �� �� ������ �Ÿ��� ��µǰ� ���弼��.

#include <stdio.h>
#include <math.h>

typedef struct {
	int x;
	int y;
} Point2D;

int main()
{
	Point2D p1;
	Point2D p2;

	printf("p1�� X��ǥ�� Y��ǥ�� �Է��ϼ���.");
	scanf("%d", &p1.x);
	scanf("%d", &p1.y);

	printf("p2�� X��ǥ�� Y��ǥ�� �Է��ϼ���.");
	scanf("%d", &p2.x);
	scanf("%d", &p2.y);

	int a = p2.x - p1.x;
	int b = p2.y - p1.y;

	double c = sqrt((a * a) + (b * b));

	printf("p1�� p2�� ����: %f\n", c);

	return 0;
}