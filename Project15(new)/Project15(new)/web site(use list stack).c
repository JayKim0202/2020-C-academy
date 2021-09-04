// 1. 웹사이트 입력 2.뒤로 3.히스토리 4. 종료
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2000

typedef struct WEB
{
	char website_address[MAX];
	struct WEB* prev;
	struct WEB* next;
}WEB;

WEB* memory_alloc();
WEB* push();
WEB* pop();
WEB* linked(WEB* current_node);
//WEB* linked_history();
void history_pop();

WEB* head;
WEB* tail;

int main()
{
	int menu;
	head = memory_alloc();
	tail = head;

	while (1)
	{
		printf("1.웹사이트 입력 2.뒤로 3.히스토리 4.종료\n");
		scanf("%d", &menu);
		getchar();

		switch (menu)
		{
		case 1:
			tail = push();
			break;
		case 2:
			pop();
			break;
		case 3:
			history_pop();
			break;
		case 4:
			exit(0);
		}
	}

	return 0;
}

WEB* memory_alloc()
{
	WEB* temp;

	temp = malloc(sizeof(struct WEB));

	memset(temp->website_address, NULL, MAX);
	temp->next = NULL;
	temp->prev = NULL;

	return temp;
}

WEB* linked(WEB* current_node)
{
	tail->next = current_node;
	current_node->prev = tail;
}

WEB* push()
{
	WEB* temp;
	temp = memory_alloc();

	printf(" Website Address : ");
	gets(temp->website_address);
	
	linked(temp);

	return temp;
}

WEB* pop()
{
	if (tail->website_address[0] == '\0')
	{
		printf("비어있음\n");
		return;
	}
	else if (tail->prev->website_address[0] == '\0')
	{
		printf("비어있음\n");
		return;
	}
	else
	{
		tail = tail->prev;
		printf("%s\n", tail->website_address);
		return;
	}
}

/*WEB* linked_history()
{
	WEB* temp;
	temp = memory_alloc();

	strcpy(temp->website_address, tail->prev->website_address);
	temp->prev = tail;
	tail->next = temp;

	return tail->next;
}*/

void history_pop()
{
	WEB* temp;
	temp = head;

	while (1)
	{
		temp = temp->next;
		printf("%s\n", temp->website_address);
		if (temp->next == NULL) break;
	}
	return;
}