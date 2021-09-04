#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Alphabet { A, B, C, D };

typedef struct Algraph {
	char value;
	struct Algraph* next_node;
	struct Algraph* next_line;
}Algraph;

Algraph* memory_alloc();
void add_new_node();
void print_graph();

Algraph* arr[4] = { 0 };

int main()
{
	for (int i = 0; i < 4; i++)
	{
		arr[i] = memory_alloc();
	}

	for (int i = 0; i < 3; i++)
	{
		arr[i]->next_line = arr[i + 1];
	}
	
	for (int i = 0; i < 5; i++)
	{
		add_new_node();
	}

	print_graph();

	return 0;
}

Algraph* memory_alloc()
{
	Algraph* temp;
	temp = malloc(sizeof(Algraph));

	temp->value = NULL;
	temp->next_node = NULL;
	temp->next_line = NULL;

	return temp;
}

// 출발 정점, 마지막 정점
// 전역 변수 대신 지역 변수 활용
void add_new_node()
{
	char temp_alphabet;
	Algraph* arr_head;
	Algraph* arr_tail;
	arr_tail = arr[0];
	int i = 0;
	int al;

	scanf("%c", &temp_alphabet);
	getchar();

	// 인덱스랑 next_node랑 별도의 반복문 만들기
	while (1)
	{
		if (arr_tail->value == NULL) break;

		else if (arr_tail->value == 'D' || arr_tail->value == temp_alphabet)
		{
			arr_tail = arr_tail->next_line;
			i++;
		}
		else
		{
			if (arr_tail->next_node == NULL)
				arr_tail->next_node = memory_alloc();
			arr_tail = arr_tail->next_node;
			if (arr_tail->next_line == NULL)
				arr_tail->next_line = arr[i + 1];
		}
	}

	arr_tail->value = temp_alphabet;

	switch (temp_alphabet)
	{
	case 'A':
		al = 0;
		break;
	case 'B':
		al = 1;
		break;
	case 'C':
		al = 2;
		break;
	case 'D':
		al = 3;
		break;
	}

	// 쌍방연결
	arr_head = arr[al];
	
	while (1)
	{
		if (arr_head->value == NULL) break;
		else
		{
			if (arr_head->next_node == NULL)
				arr_head->next_node = memory_alloc();
			arr_head = arr_head->next_node;
			if (arr_head->next_line = NULL)
				arr_head->next_line = arr[al + 1];
		}
	}
	
	switch (i)
	{
	case 0:
		arr_head->value = 'A';
		break;
	case 1:
		arr_head->value = 'B';
		break;
	case 2:
		arr_head->value = 'C';
		break;
	case 3:
		arr_head->value = 'D';
		break;
	}
}

void print_graph()
{
	char al;

	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			al = 'A';
			break;
		case 1:
			al = 'B';
			break;
		case 2:
			al = 'C';
			break;
		case 3:
			al = 'D';
			break;
		}

		printf("%c :", al);

		while (1)
		{

			printf("\t%c", arr[i]->value);
			if (arr[i]->next_node == NULL) break;

			arr[i] = arr[i]->next_node;;
		}
		printf("\n");
	}
}

//헤더는 베열
//value, next 2개;