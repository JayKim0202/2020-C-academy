#include <stdio.h>

int main()
{
	char ans1;
	char ans2;
	int count = 0;

	printf("���� �� switch�� �Ǻ��� �� ���� �ڷ����� ��� ������.\n");
	printf("a. float\n");
	printf("b. int\n");
	printf("c. long long\n");
	printf("d. char\n");
	printf("e. double\n");

	scanf("%c", &ans1);
	scanf("%c", &ans2);
	scanf("%c", &ans2);

	switch (ans1)
	{
	case 'a':
		printf("����, ");
		count++;
		break;
	case 'b':
		printf("����, ");
		break;
	case 'c':
		printf("����, ");
		break;
	case 'd':
		printf("����, ");
		break;
	case 'e':
		printf("����, ");
		count++;
		break;
	default:
		printf("a,b,c,d,e �߿����� �����Ͻÿ�.");
		break;
	}

	switch (ans2)
	{
	case 'a':
		printf("����\n");
		count++;
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
		count++;
		break;
	default:
		printf("a,b,c,d,e �߿����� �����Ͻÿ�.");
		break;
	}

	if (count == 2)
		printf("�����Դϴ�.");
	else
		printf("�����Դϴ�.");

	return 0;
}