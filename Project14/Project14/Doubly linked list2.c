#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int num;
	char str[500];
	struct node* next;
	struct node* prev;
}NODE;

NODE* memory_alloc();
NODE* add(NODE* tail);
void view(NODE* head, int mode);
NODE* modify(NODE* head);
NODE* insert(NODE* head, NODE*tail);
NODE* del(NODE* head, NODE*tail);

int main()
{
	NODE* head;
	NODE* tail;
	head = memory_alloc();
	tail = memory_alloc();
	int menu;

	head = tail;

	while (1)
	{
		printf("1.�Է�\t2.���(������)\t3.���(������)\t4.����\t5.����\t6.����\t7.����");
		printf("\n�޴� : ");
		scanf("%d", &menu);
		getchar();

		switch (menu)
		{
		case 1:
			tail = add(tail);
			break;
		case 2:
			view(head, 1);
			break;
		case 3:
			view(tail, 2);
			break;
		case 4:
			head = modify(head);
			break;
		case 5:
			tail = insert(head, tail);
			break;
		case 6:
			tail = del(head, tail);
			break;
		case 7:
			exit(0);
		}
	}
}

NODE* memory_alloc()
{
	NODE* temp;
	temp = malloc(sizeof(NODE));

	temp->num = 0;
	memset(temp->str, NULL, sizeof(temp->str));
	temp->next = NULL;
	temp->prev = NULL;

	return temp;
}

NODE* add(NODE* tail)
{
	NODE* new_node;
	new_node = memory_alloc();

	printf("����: ");
	scanf("%d", &new_node->num);
	getchar();
	printf("����: ");
	gets(new_node->str);

	tail->next = new_node;
	new_node->prev = tail;

	return new_node;
}

void view(NODE* temp, int mode)
{
	if (mode == 1)
	{
		while (1)
		{
			temp = temp->next;
			if (temp == NULL) break;
			printf("%d %s\n", temp->num, temp->str);
		}
	}
	else if (mode == 2)
	{
		while (1)
		{
			if (temp->prev == NULL) break;
			printf("%d %s\n", temp->num, temp->str);
			temp = temp->prev;
		}
	}

	return;
}

NODE* modify(NODE* head)
{
	NODE* fixed_node;
	fixed_node = head;
	int i = 1;
	int modify_num;
	int count = 0;

	while (1)
	{
		head = head->next;
		if (head == NULL) break;
		printf("%d| %d %s\n", i, head->num, head->str);
		i++;
	}
	head = fixed_node;

	printf("���� ��ȣ : ");
	scanf("%d", &modify_num);

	while (1)
	{
		if (count == modify_num) break;
		head = head->next;
		count++;
	}

	printf("����: ");
	scanf("%d", &head->num);
	getchar();
	printf("����: ");
	gets(head->str);

	return fixed_node;
}

NODE* insert(NODE* head, NODE* tail)
{
	NODE* fixed_node;
	fixed_node = head;

	int i = 1;

	while (1)
	{
		head = head->next;
		if (head == NULL) break;
		printf("%d| %d %s\n", i, head->num, head->str);
		i++;
	}
	head = fixed_node;

	NODE* new_node;
	new_node = memory_alloc();
	NODE* next_node;
	NODE* prev_node;
	int modify_num;
	int count = 0;

	printf("���� ��ȣ : ");
	scanf("%d", &modify_num);

	printf("����: ");
	scanf("%d", &new_node->num);
	getchar();
	printf("����: ");
	gets(new_node->str);

	while (1)
	{
		if (count == modify_num) break;
		head = head->next;
		count++;
	}

	next_node = head->next;
	prev_node = head;

	new_node->next = next_node;
	new_node->prev = prev_node;

	if (next_node != NULL)
	{
		head->next->prev = new_node;
		head->next = new_node;
	}
	else
	{
		head->next = new_node;
		tail = tail->next;
	}

	return tail;
}

NODE* del(NODE* head, NODE* tail)
{
	NODE* fixed_node;
	fixed_node = head;

	int i = 1;

	while (1)
	{
		head = head->next;
		if (head == NULL) break;
		printf("%d| %d %s\n", i, head->num, head->str);
		i++;
	}
	head = fixed_node;

	int del_num;
	int count = 0;

	printf("���� ��ȣ : ");
	scanf("%d", &del_num);
	getchar();

	while (1)
	{
		if (count == del_num - 1) break; // head == ������ ����� �� ���
		head = head->next;
		count++;
	}

	NODE* free_node;
	free_node = head->next;

	head = head->next; // ������ ���
	
	if (head->next != NULL)
	{
		// ������ �� ����� next == ������ ����� next
		head->prev->next = head->next;
		// ������ ����� ���� ����� prev == ������ ����� prev
		head->next->prev = head->prev;
		free(free_node);
	}
	else
	{
		// ������ ��尡 ������ ����� ���
		// ������ ����� �� ��� next == NULL
		head->prev->next = NULL;
		tail = tail->prev;
		free(free_node);
	}

	return tail;
}