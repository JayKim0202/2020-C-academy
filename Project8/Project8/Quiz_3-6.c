//���ڿ� ������ hello1.txt ������ �־����ϴ�.
//������ ���� �� ������ �Ųٷ� �����ϴ� ���α׷��� ���弼��. ����� fwirte �Լ��� stdout�� �����ϸ� �˴ϴ�.

/*
Hello, world!
!dlrow ,olleH
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
	char buffer[30] = { 0, };
	int size;

	FILE* fp = fopen("hello1.txt", "r");

	size = getFileSize(fp);

	for (int i = 0; i < size + 1; i++)
	{
		fseek(fp, -i, SEEK_END);
		fread(buffer, sizeof(char), 1, fp);

		printf("%s", buffer);

		memset(buffer, 0, 30);
	}

	fclose(fp);

	return 0;
}