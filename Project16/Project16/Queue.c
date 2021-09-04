#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void enqueue(int a);
void dequeue();

int Queue[5];
int front = 0;
int rear = -1;

int main()
{
	int menu;
	int a = 0;

	while (1)
	{
		printf(" 1. �����ȣ �߰� 2. �����ȣ ��� 3. ����");
		printf("���� : ");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			enqueue(a);
			a = 1;
			break;
		case 2:
			dequeue();
			break;
		case 3:
			exit(0);
		}
	}

	return 0;
}

void enqueue(int a)
{
	int temp;
	if (a == 0)
		temp = 1;
	else
		temp = (rear + 1) % 5;

	if (temp == front)
	{
		printf("Queue is full\n");
	}
	else
	{
		rear = (rear + 1) % 5;
		printf("�����ȣ : ");
		scanf("%d", &Queue[rear]);
	}
}

void dequeue()
{
	if (front == rear)
	{
		printf("Queue is emty\n");
		exit(2);
	}
	else
	{
		printf("�����ȣ : %d\n", Queue[front]);
		front = (front + 1) % 5;
	}
}