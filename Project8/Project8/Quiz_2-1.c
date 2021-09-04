/*1.c
2.d
3.a
4.d
5.a
6.b,d,e
7.b,e*/

//다음 소스 크도를 완성하여 문자열을 hello.txt 파일로 저장하세요.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[20] = "안녕하세요.";

	FILE* fp = fopen("hello.txt", "w");

	fputs(s1, fp);
	//fwrite(s1, strlen(s1), 1, fp);

	fclose(fp);

	return 0;
}