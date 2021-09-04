/*1.c
2.e
3.c
4.e
5.d*/

//���� �ҽ� �ڵ带 �ϼ��Ͽ� hello.txt���Ͽ��� ���� ���ڿ��� ����ϼ���.

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

int main()
{
	char* buffer;
	int size;

	FILE* fp = fopen("hello.txt", "r");

	size = getFileSize(fp);
	buffer = malloc(size + 1);
	memset(buffer, 0, size + 1);

	fread(buffer, size, 1, fp);

	printf("%s\n", buffer);

	fclose(fp);

	free(buffer);

	return 0;
}