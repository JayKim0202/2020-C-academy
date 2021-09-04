#include <stdio.h>
#include <string.h> //memset 함수가 선언된 헤더파일

struct Point2D {
	int x;
	int y;
};

int main()
{
	struct Point2D p1;

	memset(&p1, 0, sizeof(struct Point2D));

	printf("%d %d\n", p1.x, p1.y);

	return 0;
}