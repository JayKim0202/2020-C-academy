//���� �ҽ� �ڵ带 �ϼ��ϸ鼭 hello1.txt ������ ������ ����ϸ鼭 hello2.txt ���Ϸ� ����ǰ� ���弼��.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int count;
	char buffer[5] = { 0, };

	FILE* src = fopen("hello1.txt", "r");
	FILE* dest = fopen("hello2.txt", "w");

	while (feof(src) == 0)
	{
		count = fread(buffer, sizeof(char), 4, src);
		printf("%s", buffer);
		fwrite(buffer, sizeof(char), count, dest);
		memset(buffer, 0, 5);
	}

	fclose(dest);
	fclose(src);

	return 0;
}