// 문자열이 저장된 hello1.txt 파일이 주어집니다. 다음 소스 코드에서 getData 함수를 완성하여 hello1.txt에서 읽은 문자열을 출력하고,
// 그다음 줄에 읽은 크기를 출력하는 프로그램을 완성하세요.

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