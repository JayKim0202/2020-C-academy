//ǥ�� �Է����� ���� 30 ������ � ���ڿ��� �Էµ˴ϴ�. ���� �ҽ� �ڵ带�ϼ��Ͽ� �Էµ� ���ڿ� �ڿ� "th"�� �پ ��µǰ� ���弼��.

#include <stdio.h>
#include <string.h>

int main()
{
	char s1[40];

	gets(s1);

	strcat(s1, "th");

	printf("%s\n", s1);

	return 0;
}