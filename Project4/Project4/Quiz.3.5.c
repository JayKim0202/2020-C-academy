//ǥ�� �Է����� ���� 30 ������ ���ڿ� �� ���� �Էµ˴ϴ�. �� ���ڿ��� ������ �ٸ��� �� ����� ������ ����ϴ� ���α׷��� ���弼��.

#include <stdio.h>
#include <string.h>

int main()
{
	char s1[30];
	char s2[30];

	printf("���ڿ��� �� �� �Է��ϼ���: ");
	gets(s1);
	gets(s2);

	printf("%d\n", strcmp(s1, s2));

	return 0;
}