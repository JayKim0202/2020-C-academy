#include <stdio.h>

int main()
{
	char ans;

	printf("���� �� switch�� �Ǻ��� �� ���� �ڷ����� ��� ������.\n");
	printf("a. float\n");
	printf("b. int\n");
	printf("c. long long\n");
	printf("d. char\n");
	printf("e. double\n");

	scanf("%c", &ans);

	switch (ans)
	{
	case 'a':
		printf("����\n");
		break;
	case 'b':
		printf("����\n");
		break;
	case 'c':
		printf("����\n");
		break;
	case 'd':
		printf("����\n");
		break;
	case 'e':
		printf("����\n");
		break;
	}

	return 0;
}