/*다음 소스 코드를 완성하여 2차원 좌ㅠㅛ x, y를 표현하는 구조체를 정의하고, 10 20이 출력되게 만드세요.
좌표의 자료형은 int입니다.*/
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