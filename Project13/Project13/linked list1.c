#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	int num1;
	struct Node* ptr;
};

struct Node* memoryAlloc();
struct Node* add(struct Node* head);
void print(struct Node* head);

int main()
{
	struct Node* d = NULL;
	for (int i = 0; i < 3; i++)
	{
		d = add(d);
	}
	print(d);

	return 0;
}

struct Node* memoryAlloc()
{
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));

	temp->num1 = 0;
	temp->ptr = NULL;

	return temp;
}

struct Node* add(struct Node* head)
{
	struct Node* temp;
	struct Node* start;
	temp = memoryAlloc();
	start = head;

	scanf("%d", &temp->num1);

	if (head == NULL)
		return temp;
	else
	{
		while (1) {
			if (head->ptr == NULL) break;
			head = head->ptr;
		}
		head->ptr = temp;
	}
	return start;
}

void print(struct Node* head)
{
	while (1)
	{
		printf("%d", head->num1);
		if (head->ptr == NULL) break;
		head = head->ptr;
	}
	return;
}