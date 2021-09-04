/*ǥ�� �Է����� x, y ��ǥ 4���� �ԷµǾ� Point2D ����ü �迭�� ����˴ϴ�. ���⼭ �� 4���� ù ��° ������ ������ ������ ������� �̾��� �ֽ��ϴ�.
���� �ҽ� �ڵ带 �ϼ��Ͽ� ù��° ������ ������ ������ ����� ���� ���̰� ��µǰ� ���弼��.*/

#include <stdio.h>
#include <math.h>

struct Point2D {
	int x;
	int y;
};

int main()
{
	struct Point2D p[4];
	double length = 0.0f;
	int a[3];
	int b[3];

	for (int i = 0; i < sizeof(p) / sizeof(struct Point2D); i++)
	{
		printf("p[%d].x, p[%d].y�� �Է��� �ּ���.", i, i);
		scanf("%d %d", &p[i].x, &p[i].y);
	}

	for (int i = 0; i < sizeof(p) / sizeof(struct Point2D) - 1; i++)
	{
		a[i] = p[i + 1].x - p[i].x;
		b[i] = p[i + 1].y - p[i].y;
	}

	for (int i = 0; i < sizeof(p) / sizeof(struct Point2D) - 1; i++)
	{
		length += sqrt((a[i] * a[i]) + (b[i] * b[i]));
	}

	printf("������ ����: %f", length);

	return 0;
}