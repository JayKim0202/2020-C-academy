//ǥ�� �Է����� ���� 30������ � ���ڿ��� �Էµ˴ϴ�. ���� �ҽ� �ڵ带 �ϼ��Ͽ� �� printf�� ���� ���ڿ��� ����ϰ� ���弼��.

#include <stdio.h>
#include <string.h>

int main()
{
	char s1[31];
	char s2[31];

	gets(s1);

	strcpy(s2, s1);

	printf("%s\n", s1);
	printf("%s\n", s2);

	return 0;
}