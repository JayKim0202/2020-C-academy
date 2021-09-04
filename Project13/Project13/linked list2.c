#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int num;
	char str[50];
	struct Node* ptr;
} Node;

Node* memory_alloc();
Node* add(Node* head);
void print(Node* head);
Node* reset_node(Node* head);
Node* insert_node(Node* head);
Node* edit_node(Node* head);
Node* delete_node(Node* head);

int main()
{
	Node* N = NULL;
	for (int i = 0; i < 3; i++)
	{
		N = add(N);
	}
	print(N);

	N = insert_node(N);
	print(N);
	
	N = edit_node(N);
	print(N);

	N = delete_node(N);
	print(N);

	reset_node(N);

	return 0;
}

Node* memory_alloc()
{
	struct Node* temp;
	temp = malloc(sizeof(struct Node));

	temp->num = 0;
	strcpy(temp->str, " ");
	temp->ptr = NULL;

	return temp;
}

Node* add(Node* head)
{
	Node* temp;
	Node* temp2;
	temp2 = head;

	temp = memory_alloc();
	printf("숫자: ");
	scanf("%d", &temp->num);
	getchar();
	printf("문장: ");
	gets(temp->str);


	if (head == NULL)
	{
		return temp;
	}
	else
	{
		while (1)
		{
			if (head->ptr == NULL)
				break;
			head = head->ptr;
		}
		head->ptr = temp;
	}

	return temp2;
}

void print(Node* head)
{
	while (1)
	{
		printf("%d %s\n", head->num, head->str);
		if (head->ptr == NULL)
			break;
		head = head->ptr;
	}

	return;
}

Node* reset_node(Node* head)
{
	Node* current_location;
	Node* next_location;


	next_location = head->ptr;


	while (1)
	{
		if (next_location == NULL)
			break;

		current_location = next_location;
		next_location = current_location->ptr;
		free(current_location);
	}

	current_location = head;
	free(current_location);

	return;
}

Node* insert_node(Node* head)
{
	Node* new_node;
	Node* temp;
	int num1 = 0;
	int num2 = 1;
	new_node = memory_alloc();
	temp = head;

	printf("삽입번호: ");
	scanf("%d", &num1);

	printf("숫자: ");
	scanf("%d", &new_node->num);
	getchar();
	printf("문장: ");
	gets(new_node->str);

	while (1)
	{
		if (num2 == num1)
		{
			new_node->ptr = head->ptr;
			head->ptr = new_node;
			break;
		}

		head = head->ptr;
		num2++;
	}

	return temp;
}

Node* edit_node(Node* head)
{
	Node* edit_node;
	Node* temp;
	int num1 = 0;
	int num2 = 1;
	edit_node = memory_alloc();
	temp = head;

	printf("수정번호: ");
	scanf("%d", &num1);

	printf("숫자: ");
	scanf("%d", &edit_node->num);
	getchar();
	printf("문장: ");
	gets(edit_node->str);

	while (1)
	{
		if (num2 == num1)
		{
			edit_node->ptr = head->ptr;
			break;
		}
		head = head->ptr;
		num2++;
	}
	
	head = temp;
	num2 = 1;
	while (1)
	{
		if (num1 == 1)
		{
			free(temp);
			temp = memory_alloc();
			head->num = edit_node->num;
			strcpy(head->str, edit_node->str);
			head->ptr = edit_node->ptr;
			return temp;
		}
		else if (num2 == num1 - 1)
		{
			head->ptr = edit_node;
			break;
		}
		head = head->ptr;
		num2++;
	}

	return temp;
}

Node* delete_node(Node* head)
{
	Node* temp1;
	Node* temp2;
	Node* save_temp;
	int num1 = 0;
	int num2 = 1;
	temp1 = head;
	save_temp = memory_alloc();

	printf("삭제번호: ");
	scanf("%d", &num1);
	getchar();

	while (1)
	{
		if (num1 == 1)
		{
			save_temp = head->ptr;
			free(head);
			return save_temp;
		}
		else if (num2 == num1- 1)
		{
			temp2 = head->ptr;
			head->ptr = head->ptr->ptr;
			free(temp2);
			break;
		}
		head = head->ptr;
		num2++;
	}

	return temp1;
}