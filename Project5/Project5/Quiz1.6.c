//3차원 좌표 구조체 Point3D가 정의되어 있습니다. 다음 소스 코드를 완성하여 좌표 정보가 출력되게 만드세요.

#include <stdio.h>

struct Point3D {
	float x;
	float y;
	float z;
};

int main()
{
	struct Point3D p1 = { 10.0f, 20.0f, 30.0f };
	struct Point3D* ptr;

	ptr = &p1;

	printf("%f %f %f\n", ptr->x, ptr->y, ptr->z);

	return 0;
}