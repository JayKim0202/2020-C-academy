#include <stdio.h>

int main()
{
	char name0[30];
	char name1[30];
	char name2[30];
	int age0;
	int age1;
	int age2;
	char address0[100];
	char address1[100];
	char address2[100];
	int x;

	printf("�̸�, ����, �ּ� ������ �Է��Ͻÿ�.\n");
	gets(name0);
	scanf("%d", &age0);
	scanf("%d", &x);				//���� + ���ڸ� �Է½� ���� �ڿ� �ӽú����� �־������.
	gets(address0);
	printf("�̸�, ����, �ּ� ������ �Է��Ͻÿ�.\n");
	gets(name1);
	scanf("%d", &age1);
	scanf("%d", &x);
	gets(address1);
	printf("�̸�, ����, �ּ� ������ �Է��Ͻÿ�.\n");
	gets(name2);
	scanf("%d", &age2);
	scanf("%d", &x);
	gets(address2);


	printf("�̸�: %s ����: %d �ּ�: %s ", name0, age0, address0);
	printf("�̸�: %s ����: %d �ּ�: %s ", name1, age1, address1);
	printf("�̸�: %s ����: %d �ּ�: %s ", name2, age2, address2);

	return 0;
}