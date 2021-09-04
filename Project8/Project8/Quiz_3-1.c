/*1.c
2.e
3.c
4.e
5.d*/

//다음 소스 코드를 완성하여 hello.txt파일에서 읽은 문자열을 출력하세요.

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