// ���ڿ��� ����� hello1.txt ������ �־����ϴ�. ���� �ҽ� �ڵ忡�� getData �Լ��� �ϼ��Ͽ� hello1.txt���� ���� ���ڿ��� ����ϰ�,
// �״��� �ٿ� ���� ũ�⸦ ����ϴ� ���α׷��� �ϼ��ϼ���.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getFileSize(FILE* fp)
{
	int size;
	int currPos = ftell(fp);

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);

	fseek(fp, currPos, SEEK_SET);

	return size;
}

char* getData(int offset, int size, int* count, FILE* fp)
{
	char* buffer;

	buffer = malloc(size + 1);

	memset(buffer, offset, size + 1);

	fseek(fp, 0, SEEK_SET);
	fread(buffer, size, 1, fp);

	*count = strlen(buffer);
	
	return buffer;
}

int main()
{
	char* buffer;
	int size;
	int count;

	FILE* fp = fopen("hello1.txt", "r");

	size = getFileSize(fp);
	buffer = getData(0, size, &count, fp);

	printf("%s\n", buffer);
	printf("%d", count);

	fclose(fp);

	free(buffer);

	return 0;
}