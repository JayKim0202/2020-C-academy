//다음 소스 코드를 완성하여 1.0 2.0 3.0이 출력되게 만드세요.

#include <stdio.h>

struct Point3D {
	float x, y, z;
};

#define INIT_POINT3D(var, x, y, z) struct Point3D var = { x, y, z }

int main()
{
	INIT_POINT3D(p1, 1.0f, 2.0f, 3.0f);

	printf("%.1f %.1f %.1f\n", p1.x, p1.y, p1.z);

	return 0;
}