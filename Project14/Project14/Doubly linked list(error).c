//추가 삽입 삭제 출력, 숫자 문자, 양방형 링크드리스트
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
		printf("1.입력\t2.출력\t3.수정\t4.삽입\t5.삭제\t6.종료");
		printf("\n메뉴 : ");
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

	printf("숫자: ");
	scanf("%d", &temp->num);
	getchar();
	printf("문장: ");
	gets(temp->str);

	// 첫노드는 NULL, 두번째 노드부터 입력
	if (head->next == NULL)	// head->next == 두번째 노드
	{
		head->next = temp;	// temp->next == NULL, temp->prev == NULL
	}
	else
	{
		while (1)
		{
			current_node = head->next;
			head = head->next;
			// head == 두번째 노드, head->next == 세번째 노드
			// current_ndoe == 두번쩨 노드
			if (head->next == NULL)break; // 세번째 노드가 NULL == break;
		}
		head->next = temp; // 세번째 노드에 temp저장
		head->next->prev = current_node;	// 세번째 노드 prev에 두번째 노드 주소 저장
	}

	return start;
}

void print(NODE* head)
{
	// 정방향
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

	printf("수정번호 : ");
	scanf("%d", &edit_num);

	while (1)
	{
		if (count == edit_num - 1) break;
		head = head->next;
		count++;
	}

	temp = memory_alloc();

	printf("숫자: ");
	scanf("%d", &temp->num);
	getchar();
	printf("문장: ");
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

	printf("삽입번호 : ");
	scanf("%d", &insert_num);

	temp = memory_alloc();

	printf("숫자: ");
	scanf("%d", &temp->num);
	getchar();
	printf("문장: ");
	gets(temp->str);

	while (1)
	{
		if (count = insert_num) break;
		head = head->next;
		count++;
	}

	return start;
}