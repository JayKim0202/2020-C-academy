#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp = fopen("hello.txt", "w");		// hello.txt ������ ���� ���(w)�� ����
											// ���� �����͸� ��ȯ
	fputs("Hello, world!", fp);		// ���Ͽ� ���ڿ� ����

	fclose(fp);

	return 0;
}