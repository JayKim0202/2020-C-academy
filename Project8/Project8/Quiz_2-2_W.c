//position.txt���� "x 30 y 20"����Ǿ� �ֽ��ϴ�. ���� �ҽ� �ڵ带 �ϼ��Ͽ� 30 20�� ����ϼ���.

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