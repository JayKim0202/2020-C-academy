//ǥ�� �Է����� ���� 30 ������ � ���ڿ��� �Էµ˴ϴ�. �Էµ� ���ڿ��� ���̸� ����ϴ� ���α׷��� ���弼��.

#include <stdio.h>
#include <string.h>

int main()
{
	char s1[30];
	int ret;

	printf("���ڿ��� �Է��ϼ���: ");
	gets(s1);

	ret = strlen(s1);

	printf("%d\n", ret);

	return 0;
}