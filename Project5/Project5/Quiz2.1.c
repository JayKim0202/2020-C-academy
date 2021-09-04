//표준 입력으로 정수 4개가 입력되어 Point2D 구조체에 저장됩니다. 다음 소스 코드를 완성하여 두 점 사이의 거리가 출력되게 만드세요.

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

	printf("p1의 X좌표와 Y좌표를 입력하세요.");
	scanf("%d", &p1.x);
	scanf("%d", &p1.y);

	printf("p2의 X좌표와 Y좌표를 입력하세요.");
	scanf("%d", &p2.x);
	scanf("%d", &p2.y);

	int a = p2.x - p1.x;
	int b = p2.y - p1.y;

	double c = sqrt((a * a) + (b * b));

	printf("p1과 p2의 길이: %f\n", c);

	return 0;
}