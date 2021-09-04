/*표준 입력으로 5명의 인적 정보가 입력됩니다(홀수 번째는 이름, 짝수 번째는 니이).
다음 소스 코드를 완성하여 입력된 사람 중에서 나이가 가장 많은 사람의 이름이 출력되게 만드세요.*/\

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
		printf("이름을 입력세요: ");
		gets(p[i]->name);
		printf("나이를 입력하세요: ");
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