#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp = fopen("Hello.txt", "w");		// hello.txt ������ ���� ���(w)�� ����, ���� �����͸� ��ȯ

	fprintf(fp, "%s %d\n", "Hello", 100);	// ������ �����Ͽ� ���ڿ��� ���Ͽ� ����

	fclose(fp);		//���� ������ �ݱ�

	return 0;
}

//Project8 ������ �ؽ�Ʈ ���Ϸ� �����.