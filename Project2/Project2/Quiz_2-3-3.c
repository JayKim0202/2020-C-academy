#include <stdio.h>

int main()
{
	printf("���� �� switch�� �Ǻ��� �� ���� �ڷ����� ��� ������.\n");
	printf("a. float\n");
	printf("b. int\n");
	printf("c. long long\n");
	printf("d. char\n");
	printf("e. double\n");

	char ans1;
	char ans2;
	int count = 0;

	scanf("%c", &ans1);
	scanf("%c", &ans2);
	scanf("%c", &ans2);
	
	switch (ans1)
	{
	case 'a':
		count++;
		break;
	case 'b':
		break;
	case 'c':
		break;
	case 'd':
		break;
	case 'e':
		count++;
		break;
	default:
		printf("a,b,c,d,e �� �����Ͻÿ�.\n");
		break;
	}

	switch (ans2)
	{
	case 'a':
		count++;
		break;
	case 'b':
		break;
	case 'c':
		break;
	case 'd':
		break;
	case 'e':
		count++;
		break;
	default:
		printf("a,b,c,d,e �� �����Ͻÿ�.\n");
		break;
	}

	if (count == 2)
		printf("�����Դϴ�.\n");
	else
		printf("�����Դϴ�.\n");

	return 0;
}