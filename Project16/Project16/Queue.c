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
		printf(" 1. 예약번호 추가 2. 예약번호 출력 3. 종료");
		printf("선택 : ");
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
		printf("예약번호 : ");
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
		printf("예약번호 : %d\n", Queue[front]);
		front = (front + 1) % 5;
	}
}