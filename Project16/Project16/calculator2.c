#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX 400

typedef struct stack
{
	char element;
	struct stack* prev;
	struct stack* next;
} stack;

typedef struct num
{
	char element_n[40];
	struct num* prev_n;
	struct num* next_n;
} num;

stack* memory_alloc_op();
num* memory_alloc_num();
void input();
void infix_to_postfix();
int calculate();

char infix[MAX];
char postfix[MAX];
stack* operator_node;
num* temp_num;

int main()
{
	operator_node = memory_alloc_op();
	temp_num = memory_alloc_num();

	input();
	infix_to_postfix();
	calculate();

	return 0;
}

stack* memory_alloc_op()
{
	stack* temp = malloc(sizeof(stack));
	temp->element = NULL;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

num* memory_alloc_num()
{
	num* temp = malloc(sizeof(num));
	memset(temp->element_n, 0, 40);
	temp->prev_n = NULL;
	temp->next_n = NULL;
	return temp;
}

void input()
{
	int i = 0;
	char temp;

	printf("수식을 입력하세요\n");

	while (1)
	{
		temp = getch();
		if (temp == 61 || temp == '\r') break; // '='등호 또는 '\r'엔터 입력 시 중지
		if (temp == 8)
		{
			--i;
			printf("\b \b");
			infix[i] = '\0';
		}
		else
		{
			printf("%c", temp);
			infix[i++] = temp;
		}
	}
	printf("\n");

	printf("수식 = %s\n", infix);

	return;
}

void infix_to_postfix()
{
	stack* op_tail;
	op_tail = operator_node;
	
	int i = 0;
	int p = 0;
	int lm = 0; // num len
	char num_temp[40] = { 0 };
	char temp;
	int b = 0; // break
	int bracket = 0;

	while (1)
	{
		while (1)
		{
			temp = infix[i];

			if (temp == '\0') b = 1;
			if (temp == '\0' || temp == '+' || temp == '-' || temp == '*' || temp == '/')
			{
				if (bracket == 0)
				{
					postfix[p++] = lm;
					strcat(postfix, num_temp);
					memset(num_temp, 0, 40);
					p += lm;
					lm = 0;
					i++;
					break;
				}
				else if (bracket == 1)
				{
					i++;
					bracket = 0;
					break;
				}
			}
			else if (temp == '(')
			{
				i++;
				break;
			}
			else if (temp == ')')
			{
				postfix[p++] = lm;
				strcat(postfix, num_temp);
				memset(num_temp, 0, 40);
				p += lm;
				lm = 0;
				i++;
				bracket = 1;
				break;
			}
			num_temp[lm] = temp;
			i++;
			lm++;
		}
		switch (temp)
		{
		case '+':
			if (op_tail->element == '+' || op_tail->element == '-' || op_tail->element == '*' || op_tail->element == '/')
			{
				while (1)
				{
					if (op_tail->prev == NULL) break;
					postfix[p++] = op_tail->element;
					op_tail = op_tail->prev;
				}
				free(operator_node);
				operator_node = memory_alloc_op();
				op_tail = operator_node;
			}
			op_tail->next = memory_alloc_op();
			op_tail->next->prev = op_tail;
			op_tail = op_tail->next;
			op_tail->element = temp;
			break;
		case '-':
			if (op_tail->element == '+' || op_tail->element == '-' || op_tail->element == '*' || op_tail->element == '/')
			{
				while (1)
				{
					if (op_tail->prev == NULL) break;
					postfix[p++] = op_tail->element;
					op_tail = op_tail->prev;
				}
				free(operator_node);
				operator_node = memory_alloc_op();
				op_tail = operator_node;
			}
			op_tail->next = memory_alloc_op();
			op_tail->next->prev = op_tail;
			op_tail = op_tail->next;
			op_tail->element = temp;
			break;
		case '*':
			if (op_tail->element == '*' || op_tail->element == '/')
			{
				while (1)
				{
					if (op_tail->prev == NULL) break;
					postfix[p++] = op_tail->element;
					op_tail = op_tail->prev;
				}
				free(operator_node);
				operator_node = memory_alloc_op();
				op_tail = operator_node;
			}
			op_tail->next = memory_alloc_op();
			op_tail->next->prev = op_tail;
			op_tail = op_tail->next;
			op_tail->element = temp;
			break;
		case '/':
			if (op_tail->element == '*' || op_tail->element == '/')
			{
				while (1)
				{
					if (op_tail->prev == NULL) break;
					postfix[p++] = op_tail->element;
					op_tail = op_tail->prev;
				}
				free(operator_node);
				operator_node = memory_alloc_op();
				op_tail = operator_node;
			}
			op_tail->next = memory_alloc_op();
			op_tail->next->prev = op_tail;
			op_tail = op_tail->next;
			op_tail->element = temp;
			break;
		case '(':
			op_tail->next = memory_alloc_op();
			op_tail->next->prev = op_tail;
			op_tail = op_tail->next;
			op_tail->element = temp;
			break;
		case ')':
			while (1)
			{
				postfix[p++] = op_tail->element;
				op_tail = op_tail->prev;
				if (op_tail->element == '(') break;
			}



			if (operator_node->next->element != '(')
			{
				stack* temp_operator = operator_node;
				while (1)
				{
					temp_operator = temp_operator->next;
					if (temp_operator->next->element == '(') break;
				}
				temp_operator->next = NULL;
				op_tail = temp_operator;
			}
			else
			{
				free(operator_node);		// (전에 연산 기호가 있으며 실행되면 안됨
				operator_node = memory_alloc_op();
				op_tail = operator_node;
			}

			break;
		}

		if (b == 1) break;
	}

	while (1)
	{
		if (op_tail->prev == NULL) break;
		postfix[p++] = op_tail->element;
		op_tail = op_tail->prev;
	}

	printf("후위 변환식 : %s\n", postfix);	// 12 + 345 = 2123345+
}


int calculate()
{
	num* num_tail;
	num_tail = temp_num;
	int p = 0;
	int a, b;
	char temp[30] = { 0 };
	int result;
	int num_len;
	char op;

	// free하기 위한 함수들
	num* current_node;
	num* prev_node;

	while (1)
	{
		while (1)
		{
			if (postfix[p] == '+' || postfix[p] == '-' || postfix[p] == '*' || postfix[p] == '/')
			{
				op = postfix[p++];
				break;
			}

			num_tail->next_n = memory_alloc_num();
			num_tail->next_n->prev_n = num_tail;
			num_tail = num_tail->next_n;
			num_len= postfix[p++];
			for (int i = 0; i < num_len; i++)
			{
				num_tail->element_n[i] = postfix[p++];
			}
			if (postfix[p] == '+' || postfix[p] == '-' || postfix[p] == '*' || postfix[p] == '/')
			{
				op = postfix[p++];
				break;
			}
		}
		a = atoi(num_tail->prev_n->element_n);
		b = atoi(num_tail->element_n);
		if (op == '+')
		{
			for (int i = 0; i < 2; i++)
			{
				current_node = num_tail;
				prev_node = num_tail->prev_n;
				num_tail = num_tail->prev_n;
				free(current_node);
				current_node = NULL;
			}
			num_tail->next_n = memory_alloc_num();
			num_tail->next_n->prev_n = num_tail;
			num_tail = num_tail->next_n;
			sprintf(temp, "%d", a + b);
			strcpy(num_tail->element_n, temp);
		}
		else if (op == '-')
		{
			for (int i = 0; i < 2; i++)
			{
				current_node = num_tail;
				prev_node = num_tail->prev_n;
				num_tail = num_tail->prev_n;
				free(current_node);
				current_node = NULL;
			}
			num_tail->next_n = memory_alloc_num();
			num_tail->next_n->prev_n = num_tail;
			num_tail = num_tail->next_n;
			sprintf(temp, "%d", a - b);
			strcpy(num_tail->element_n, temp);
		}
		else if (op == '*')
		{
			for (int i = 0; i < 2; i++)
			{
				current_node = num_tail;
				prev_node = num_tail->prev_n;
				num_tail = num_tail->prev_n;
				free(current_node);
				current_node = NULL;
			}
			num_tail->next_n = memory_alloc_num();
			num_tail->next_n->prev_n = num_tail;
			num_tail = num_tail->next_n;
			sprintf(temp, "%d", a * b);
			strcpy(num_tail->element_n, temp);
		}
		else if (op == '/')
		{
			for (int i = 0; i < 2; i++)
			{
				current_node = num_tail;
				prev_node = num_tail->prev_n;
				num_tail = num_tail->prev_n;
				free(current_node);
				current_node = NULL;
			}
			num_tail->next_n = memory_alloc_num();
			num_tail->next_n->prev_n = num_tail;
			num_tail = num_tail->next_n;
			sprintf(temp, "%d", a / b);
			strcpy(num_tail->element_n, temp);
		}

		if (postfix[p] == '\0') break;
	}

	result = atoi(num_tail->element_n);

	printf("값 : %d", result);
	
	return result;
}