/*1.c
2.d
3.a
4.d
5.a
6.b,d,e
7.b,e*/

//���� �ҽ� ũ���� �ϼ��Ͽ� ���ڿ��� hello.txt ���Ϸ� �����ϼ���.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[20] = "�ȳ��ϼ���.";

	FILE* fp = fopen("hello.txt", "w");

	fputs(s1, fp);
	//fwrite(s1, strlen(s1), 1, fp);

	fclose(fp);

	return 0;
}