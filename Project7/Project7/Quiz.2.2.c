//다음 소스 코드를 완성하여 좌표를 성정하는 함수를 만드세요.

#include <stdio.h>
#include <stdlib.h>

struct Point2D {
	int x;
	int y;
};

void setPoint2D(struct Point2D* p, int x, int y)
{
	p->x = x;
	p->y = y;
}

int main()
{
	struct Point2D* p1 = malloc(sizeof(struct Point2D));

	setPoint2D(p1, 10, 20);

	printf("%d %d\n", p1->x, p1->y);

	free(p1);

	return 0;
}