//다음 소스 코드를 완성하여 사각형의 넓이가 출력되게 만드세요.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Rectangle {
	int x1, y1;
	int x2, y2;
};

int main()
{
	struct Rectangle rect;
	int area;

	rect.x1 = 20;
	rect.y1 = 20;
	rect.x2 = 40;
	rect.y2 = 30;

	//abs절댓값

	int width = abs(rect.x2 - rect.x1);
	int height = abs(rect.y2 - rect.y1);

	area = width * height;

	printf("%d\n", area);

	return 0;
}