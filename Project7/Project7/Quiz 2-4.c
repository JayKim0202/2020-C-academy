//ǥ�� �Է����� ���� 30 ������ ���� �̸� ���ڿ��� �ΰ� �Էµ˴ϴ�.
//���� �ҽ� �ڵ带�ϼ��Ͽ� ��ü �̸��� ��µǰ� ���弼��(���� �̸��� �ٿ��� ���).

//�� �浿
//��浿

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char printFullName(char *fn, char *gf)
{
	printf("%s%s", fn, gf);
}

int main()
{
	char familyName[31];
	char givenName[31];

	scanf("%s %s", familyName, givenName);

	printFullName(familyName, givenName);

	return 0;
}