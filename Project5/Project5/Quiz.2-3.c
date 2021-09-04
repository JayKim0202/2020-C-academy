/*표준 입력으로 x, y 좌표 4개가 입력되어 Point2D 구조체 배열에 저장됩니다. 여기서 점 4개는 첫 번째 점부터 마지막 점까지 순서대로 이어져 있습니다.
다음 소스 코드를 완성하여 첫번째 점부터 마지막 점까지 연결된 선의 길이가 출력되게 만드세요.*/

#include <stdio.h>
#include <math.h>

struct Point2D {
	int x;
	int y;
};

int main()
{
	struct Point2D p[4];
	double length = 0.0f;
	int a[3];
	int b[3];

	for (int i = 0; i < sizeof(p) / sizeof(struct Point2D); i++)
	{
		printf("p[%d].x, p[%d].y를 입력해 주세요.", i, i);
		scanf("%d %d", &p[i].x, &p[i].y);
	}

	for (int i = 0; i < sizeof(p) / sizeof(struct Point2D) - 1; i++)
	{
		a[i] = p[i + 1].x - p[i].x;
		b[i] = p[i + 1].y - p[i].y;
	}

	for (int i = 0; i < sizeof(p) / sizeof(struct Point2D) - 1; i++)
	{
		length += sqrt((a[i] * a[i]) + (b[i] * b[i]));
	}

	printf("네점의 길이: %f", length);

	return 0;
}