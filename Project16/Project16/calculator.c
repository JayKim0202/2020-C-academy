#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX 4000

//연산자 저장 스택
typedef struct stack
{
	char element;
	struct stack* prev;
	struct stack* next;
} stack;

typedef struct temp_num_stack
{
	char element[10];
	int digit;
	struct temp_num_stack* prev;
	struct temp_num_stack* next;
} temp_num_stack;

char infix[MAX];
char postfix[MAX];
stack* operator_node;
temp_num_stack* temp_num;
stack* operator_node_tail;

stack* memory_alloc_op();
stack* memory_alloc_num();
void input();
void save_postfix();
stack* infix_to_postfix(char c, int j);
int ctoi(char c);

int main()
{

	temp_num = memory_alloc_num();
	operator_node = memory_alloc_op();

	input();
}

stack* memory_alloc_op()
{
	stack* temp = malloc(sizeof(stack));

	temp->element = NULL;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

temp_num_stack* memory_alloc_num()
{
	temp_num_stack* temp = malloc(sizeof(temp_num_stack));

	memset(temp->element, 0, 10);
	temp->digit = NULL;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

void input()
{
	int t = 1;
	int i = 0;
	char temp[20] = { 0 };
	int num_len;
	char unit;

	printf("수식을 입력하세요\n");

	while (1)
	{
		unit = getch();

		if (unit == 61 || unit == '\r') // '='등호 또는 '\r'엔터 입력 시 중지
		{
			num_len = t - 1;
			temp[0] = num_len;
			for (int j = 0; j < num_len + 1; j++)
			{
				infix[i++] = temp[j];
			}
			t = 1;
			memset(temp, 0, 20);
			break;
		}
		else if (unit == '+' || unit == '-' || unit == '*' || unit == '/')
		{
			num_len = t - 1;
			temp[0] = num_len;
			for (int j = 0; j < num_len + 1; j++)
			{
				infix[i++] = temp[j];
			}
			t = 1;
			memset(temp, 0, 20);
			infix[i++] = unit;
		}
		else // 숫자 입력 시 실행
			temp[t++] = unit;

		if (temp == 8)
			printf("\b \b");
		else
			printf("%c", unit);
	}

	//printf("\n수식 = %s", infix);

	return;
}

int ctoi(char c)
{
	switch (c)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case' 4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	}
}

void save_postfix()
{
	temp_num_stack* temp_num_tail;
	temp_num_tail = temp_num;
	temp_num_tail->next = memory_alloc_num();
	temp_num_tail = temp_num_tail->next;
	
	int num_len;
	int i = 0;
	int count = 1;
	char temp;

	while (1)
	{
		if (infix[i] == '\0') break;

		temp = infix[i++];

		switch (temp)
		{
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
			infix_to_postfix(temp, i);
			break;
		default:
			continue;
		}

		switch (count)
		{
		case 1:
			num_len = ctoi(infix[i++]);
			count = 2;
			break;
		case 2:

			for (int d = 0; d < num_len; d++)
			{
				temp_num_tail->element[d] = infix[i++];
			}
			temp_num_tail->next = memory_alloc_num();
			temp_num_tail = temp_num_tail->next;
			count = 1;
			break;
		}
	}
}

stack* infix_to_postfix(char c, int i)
{
	operator_node_tail = operator_node;
	operator_node_tail->next = memory_alloc_op;

	switch (c)
	{
	case '(':
	case ')':
	case '+':
		if (operator_node_tail->element == '+' || operator_node_tail->element == '-' || operator_node_tail->element == '*' || operator_node_tail->element == '/')
		{
			while (1)
			{
				if (operator_node_tail->prev == NULL) break;
				postfix[i] = operator_node_tail->prev->element;
				operator_node_tail = operator_node_tail->prev;
			}
			
		}
		operator_node_tail->next = memory_alloc();
		operator_node_tail->next->prev = operator_node_tail;
		operator_node_tail = operator_node_tail->next;
		operator_node_tail->element = c;
		break;
	case '-':
	case '*':
	case '/':
	}




	return operator_node_tail;
}