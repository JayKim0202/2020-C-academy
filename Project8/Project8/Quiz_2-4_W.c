//�ִ� ���� 100�� �̸��� ���ڿ��� ����� words.txt ������ �־����ϴ�. ���� �ҽ� �ڵ带 �ϼ��Ͽ� words.txt���� ���ڿ��� �е��� ���弼��.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char* s1 = "This speech caused a remarkable sensation among the party.";

	FILE* fp = fopen("words.txt", "w");

	fwrite(s1, strlen(s1), 1, fp);

	fclose(fp);

	return 0;
}