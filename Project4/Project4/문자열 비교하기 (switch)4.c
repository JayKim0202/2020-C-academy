#include <stdio.h>
#include <string.h>

int main()
{
	char s1[20];
	char s2[20];

	printf("���ڿ� �� ���� �Է��ϼ���: ");
	gets(s1);
	gets(s2);

	int ret = strcmp(s1, s2);

	switch (ret)
	{
	case 0 :
		printf("�� ���ڿ��� ����\n");
		break;
	case 1:
		printf("%s���� %s�� ŭ\n", s2, s1);
		break;
	case -1:
		printf("%s���� %s�� ŭ\n", s1, s2);
		break;
	}

	return 0;
}