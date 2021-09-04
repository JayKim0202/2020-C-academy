#define _CRT_SUCURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_MAX 100

typedef struct treeNode
{
	int c;
	char str[NUM_MAX];
	struct treeNode* prev;
	struct treeNode* next;
}NODE;

NODE* memory_alloc();
NODE* enqueue();
NODE* dequeue();

NODE* front;
NODE* rear;
int check_empty;

int main()
{
	front = memory_alloc();
	rear = front;
	check_empty = 0;

	int menu;

	while (1)
	{
		printf("\n1.입력 2.출력 및 삭제 3. 종료\n");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			rear->next = enqueue();
			rear = rear->next;
			break;
		case 2:
			front->next = dequeue();
			if (check_empty == 1)
			{
				front = front->next;
				rear = front;
				check_empty = 0;
			}
			break;
		case 3:
			exit(0);
		}
	}

	return 0;
}

NODE* memory_alloc()
{
	NODE* temp;
	temp = malloc(sizeof(NODE));

	temp->c = 0;
	memset(temp->str, 0, NUM_MAX);
	temp->prev = NULL;
	temp->next = NULL;

	return temp;
}

NODE* enqueue()
{
	NODE* temp;
	temp = memory_alloc();

	printf("숫자 : ");
	scanf("%d", &temp->c);
	getchar();
	printf("문장 : ");
	gets(temp->str);

	temp->prev = rear;

	return temp;
}

NODE* dequeue()
{
	NODE* fixed_node;
	NODE* current_node;
	NODE* next_node;
	fixed_node = front->next;

	if (fixed_node == NULL)
	{
		printf("Queue is empty\n");
		check_empty = 1;
		return memory_alloc();
	}

	current_node = fixed_node;
	next_node = fixed_node->next;

	printf("%d\t%s\n", current_node->c, current_node->str);

	free(current_node);

	if (next_node != NULL)
		next_node->prev = front;
	else
	{
		check_empty = 1;
		return memory_alloc();
	}


	return next_node;
}