//�߰� ���� ���� ���, ���� ����, ����� ��ũ�帮��Ʈ
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
NODE* add(NODE* head);
void print(NODE* head);
NODE* edit(NODE* head);
NODE* insert(NODE* head);

int main()
{
	NODE* node;
	node = memory_alloc();

	int menu;

	while (1)
	{
		printf("1.�Է�\t2.���\t3.����\t4.����\t5.����\t6.����");
		printf("\n�޴� : ");
		scanf("%d", &menu);
		getchar();

		switch (menu)
		{
		case 1:
			node = add(node);
			break;
		case 2:
			print(node);
			break;
		case 3:
			node = edit(node);
			break;
		case 4:
			node = insert(node);
			break;
		case 6:
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

NODE* add(NODE* head)
{
	NODE* start;
	start = head;
	NODE* current_node;

	NODE* temp;
	temp = memory_alloc();

	printf("����: ");
	scanf("%d", &temp->num);
	getchar();
	printf("����: ");
	gets(temp->str);

	// ù���� NULL, �ι�° ������ �Է�
	if (head->next == NULL)	// head->next == �ι�° ���
	{
		head->next = temp;	// temp->next == NULL, temp->prev == NULL
	}
	else
	{
		while (1)
		{
			current_node = head->next;
			head = head->next;
			// head == �ι�° ���, head->next == ����° ���
			// current_ndoe == �ι��� ���
			if (head->next == NULL)break; // ����° ��尡 NULL == break;
		}
		head->next = temp; // ����° ��忡 temp����
		head->next->prev = current_node;	// ����° ��� prev�� �ι�° ��� �ּ� ����
	}

	return start;
}

void print(NODE* head)
{
	// ������
	NODE* start;
	start = head;
	int i = 1;

	head = head->next;
	while (1)
	{
		printf("%d|\t%d %s\n", i, head->num, head->str);
		head = head->next;
		i++;
		if (head == NULL) break;
	}
}

NODE* edit(NODE* head)
{
	NODE* start;
	start = head;
	NODE* temp;
	int edit_num;
	int count = 0;

	print(head);

	printf("������ȣ : ");
	scanf("%d", &edit_num);

	while (1)
	{
		if (count == edit_num - 1) break;
		head = head->next;
		count++;
	}

	temp = memory_alloc();

	printf("����: ");
	scanf("%d", &temp->num);
	getchar();
	printf("����: ");
	gets(temp->str);
	temp->prev = head->next->prev;
	if (head->next->next != NULL)
		temp->next = head->next->next;

	if (head->next->next->prev != NULL)
		head->next->next->prev = temp;
	head->next = temp;

	return start;
}

NODE* insert(NODE* head)
{
	NODE* start;
	start = head;
	NODE* temp;

	int insert_num;
	int count = 0;

	print(head);

	printf("���Թ�ȣ : ");
	scanf("%d", &insert_num);

	temp = memory_alloc();

	printf("����: ");
	scanf("%d", &temp->num);
	getchar();
	printf("����: ");
	gets(temp->str);

	while (1)
	{
		if (count = insert_num) break;
		head = head->next;
		count++;
	}

	return start;
}