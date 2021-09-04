//position.txt에는 "x 30 y 20"저장되어 있습니다. 다음 소스 코드를 완성하여 30 20을 출력하세요.

#include <stdio.h>

int main()
{
	char c1, c2;
	int x, y;

	FILE* fp = fopen("position.txt", "w");

	fprintf(fp, "%c %d %c %d", 'x', 30, 'y', 20);

	fclose(fp);

	return 0;
}