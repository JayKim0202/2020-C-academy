/*ǥ�� �Է����� 5���� ���� ������ �Էµ˴ϴ�(Ȧ�� ��°�� �̸�, ¦�� ��°�� ����).
���� �ҽ� �ڵ带 �ϼ��Ͽ� �Էµ� ��� �߿��� ���̰� ���� ���� ����� �̸��� ��µǰ� ���弼��.*/\

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char name[30];
	int age;
};

int main()
{
	struct Person* p[5];

	char x;
	char oldest[30];

	for (int i = 0; i < sizeof(p) / sizeof(struct Person *); i++)
	{
		p[i] = malloc(sizeof(struct Person));
	}

	for (int i = 0; i < sizeof(p) / sizeof(struct Person *); i++)
	{
		printf("�̸��� �Է¼���: ");
		gets(p[i]->name);
		printf("���̸� �Է��ϼ���: ");
		scanf("%d", &p[i]->age);
		scanf("%c", &x);
	}

	int j = 0;
	int oldestAge = p[0]->age;

	while (1)
	{
		if (p[j]->age > oldestAge)
		{
			oldestAge = p[j]->age;
			strcpy(oldest, p[j]->name);
		}
		j++;

		if (j == sizeof(p) / sizeof(struct Person *) -1)
		{
			break;
		}
	}


	printf("%s\n", oldest);

	for (int i = 0; i < sizeof(p) / sizeof(struct Perosn *); i++)
	{
		free(p[i]);
	}

	return 0;
}