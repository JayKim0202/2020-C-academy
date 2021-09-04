#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
	int num;
	char s[100];
};

int size = 1;

struct Data* MemoryAlloc(int psize);
void addData(struct Data* d);
void deleteData(struct Data* d, int count);
void changeData(struct Data* d, int count);
void insertData(struct Data* d, int count);
void printData(struct Data* d, int count);
struct Data* increaseMemory(struct Data* d);
struct Data* decreaseMemory(struct Data* d);


int main()
{
	struct Data* d;
	int menu;
	char empty = 0;
	int count = 0;
	d = MemoryAlloc(size);

	while (1)
	{
		printf("1.추가\t2.삭제\t3.수정\t4.삽입\t5.출력\t6.종료\n");
		printf("메뉴를 선택하세요 :");
		scanf("%d", &menu);
		scanf("%c", &empty);

		switch (menu)
		{
		case 1:
			addData(&d[count]);
			count++;
			if (size == count)
				d = increaseMemory(d);
			break;
		case 2:
			deleteData(d, count);
			count--;
			if (size > 5 || count + 1 == size)
				d = decreaseMemory(d);
			break;
		case 3:
			changeData(d, count);
			break;
		case 4:
			insertData(d, count);
			count++;
			break;
		case 5:
			printData(d, count);
			break;
		case 6:
			exit(0);
		}
	}

	free(d);

	return 0;
}

struct Data* increaseMemory(struct Data* d)
{
	struct Data* temp;

	size++;
	temp = malloc(sizeof(struct Data) * size);
	
	for (int i = 0; i < size; i++)
	{
		temp[i].num = d[i].num;
		strcpy(temp[i].s, d[i].s);
	}

	free(d);

	return temp;
}

struct Data* decreaseMemory(struct Data* d)
{
	struct Data* temp;

	size--;
	temp = malloc(sizeof(struct Data) * size);

	for (int i = 0; i < size; i++)
	{
		temp[i].num = d[i].num;
		strcpy(temp[i].s, d[i].s);
	}

	free(d);

	return temp;
}

struct Data* MemoryAlloc(int psize)
{
	struct Data* temp;

	temp = malloc(sizeof(struct Data) * psize);
	memset(temp, 0, sizeof(struct Data) * psize);

	return temp;
}

void addData(struct Data* d)
{
	printf("숫자를 입력해 주세요: ");
	scanf("%d", &d->num);
	getchar();
	printf("문장을 입력해 주세요: ");
	gets(d->s);
}

void deleteData(struct Data* d, int count)
{
	int num;

	printData(d, count);
	printf("삭제할 번호를 선택하세요: ");
	scanf("%d", &num);
	getchar();

	for (int i = num; i < count; i++)
	{
		d[i] = d[i + 1];
	}

	printf("삭제가 완료되었습니다.\n");
}

void changeData(struct Data* d, int count)
{
	int num;
	printData(d, count);
	printf("수정할 번호를 선택하세요: ");
	scanf("%d", &num);
	getchar();

	addData(&d[num]);
	printf("수정이 완료되었습니다.\n");
}

void insertData(struct Data* d, int count)
{
	int num;

	printData(d, count);
	printf("삽입할 장소의 번호를 선택하세요: ");
	scanf("%d", &num);
	getchar();

	count++;
	for (int i = count; i >= num; i--)
	{
		d[i] = d[i - 1];
	}

	addData(&d[num]);

	printf("삽입이 완료되었습니다\n ");
}

void printData(struct Data* d, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("번호: %d | %d %s\n", i, d[i].num, d[i].s);
	}
}