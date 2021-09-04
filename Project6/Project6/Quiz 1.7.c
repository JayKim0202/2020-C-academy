//표준 입력으로 x, y, z 좌표 3개가 입력되어 Point3D 배열에 저장됩니다. 다음 소스 코드를 완성하여 구조체 배열에서 두 번째 요소의 x멤버와 세 번째 요소의 z멤버가 출력되게 만드세요.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Point3D {
	float x;
	float y;
	float z;
};

int main()
{
	void* ptr = malloc(sizeof(struct Point3D) * 3);
	struct Point3D p[3];
	float result1, result2;

	scanf("%f %f %f %f %f %f %f %f %f",
		&p[0].x, &p[0].y, &p[0].z,
		&p[1].x, &p[1].y, &p[1].z,
		&p[2].x, &p[2].y, &p[2].z);

	memcpy(ptr, p, sizeof(struct Point3D) * 3);
	memset(p, 0, sizeof(struct Point3D) * 3);

	result1 = ((struct Point3D*)ptr)[1].x;
	result2 = ((struct Point3D*)ptr)[2].z;

	printf("%.1f %.1f\n", result1, result2);

	free(ptr);

	return 0;
}