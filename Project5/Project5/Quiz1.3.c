//3���� ��ǥ ����ü _Point3D�� ���ǵǾ� �ֽ��ϴ�. ���� �ҽ� �ڵ带 �ϼ��Ͽ� 10.000000 20.000000 30.000000�� ��µǰ� ���弼��.

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