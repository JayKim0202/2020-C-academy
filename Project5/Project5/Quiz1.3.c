//3차원 좌표 구조체 _Point3D가 정의되어 있습니다. 다음 소스 코드를 완성하여 10.000000 20.000000 30.000000이 출력되게 만드세요.

#include <stdio.h>
#include <stdlib.h>

typedef struct _Point3D {
	float x;
	float y;
	float z;
} Point3D;

int main()
{
	Point3D* p1 = malloc(sizeof(Point3D));

	p1->x = 10.0f;
	p1->y = 20.0f;
	p1->z = 30.0f;

	printf("%f %f %f\n", p1->x, p1->y, p1->z);

	free(p1);

	return 0;
}