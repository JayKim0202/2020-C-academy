#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX 4000

typedef struct stack
{
	char element;
	struct stack* prev;
	struct stack* next;
} stack;

stack* memory_alloc();
void input();
void infix_to_postfix();
char operator_precedence_comparison(stack* oper);
int calculate();
int num_conversion(char c);

char infix[MAX];
char postfix[MAX];
stack* operator_node;
stack* num;
int result;

int main()
{
	int menu = 0;
	operator_node = memory_alloc();

	while (1)
	{
		printf("1.���� �Է� 2. ������ ��ȯ / ��� 3. ��갪 ��� 4. ����\n");
		scanf("%d", &menu);
		getchar();

		switch (menu)
		{
		case 1:
			input();
			break;
		case 2:
			infix_to_postfix();
			break;
		case 3:
			result = calculate();
			break;
		case 4:
			exit(0);
		}
	}
}

stack* memory_alloc()
{
	stack* temp = malloc(sizeof(stack));
	temp->element = NULL;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

void input()
{
	int i = 0;
	char temp;
	
	printf("������ �Է��ϼ���\n");

	while (1)
	{
		temp = getch();
		if (temp == 61 || temp == '\r') break; // '='��ȣ �Ǵ� '\r'���� �Է� �� ����
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

	printf("���� = %s\n", infix);

	return;
}

char operator_precedence_comparison(stack* oper)
{
	char temp;

	temp = oper->element;
	return temp;
}

void infix_to_postfix()
{
	char temp;
	int i = 0;
	int j = 0;
	stack* op_tail;
	op_tail = operator_node;

	while (1)
	{
		temp = infix[i++];

		if (temp == '\0') break;

		switch (temp)
		{
		case '+':
			if (op_tail->element == '+' || op_tail->element == '-' || op_tail->element == '*' || op_tail->element == '/')
			{
				while (1)
				{
					if (op_tail->prev == NULL) break;
					postfix[j++] = operator_precedence_comparison(op_tail);
					op_tail = op_tail->prev;
				}
				free(operator_node);
				operator_node = memory_alloc();
				op_tail = operator_node;
			}
			op_tail->next = memory_alloc();
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
					postfix[j++] = operator_precedence_comparison(op_tail);
					op_tail = op_tail->prev;
				}
				free(operator_node);
				operator_node = memory_alloc();
				op_tail = operator_node;
			}
			op_tail->next = memory_alloc();
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
					postfix[j++] = operator_precedence_comparison(op_tail);
					op_tail = op_tail->prev;
				}
				free(operator_node);
				operator_node = memory_alloc();
				op_tail = operator_node;
			}
			op_tail->next = memory_alloc();
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
					postfix[j++] = operator_precedence_comparison(op_tail);
					op_tail = op_tail->prev;
				}
				free(operator_node);
				operator_node = memory_alloc();
				op_tail = operator_node;
			}
			op_tail->next = memory_alloc();
			op_tail->next->prev = op_tail;
			op_tail = op_tail->next;
			op_tail->element = temp;
			break;
		case '(':
			op_tail->next = memory_alloc();
			op_tail->next->prev = op_tail;
			op_tail = op_tail->next;
			op_tail->element = temp;
			break;
		case ')':
			while (1)
			{
				postfix[j++] = operator_precedence_comparison(op_tail);
				op_tail = op_tail->prev;
				if (op_tail->element == '(') break;
			}free(operator_node);
			operator_node = memory_alloc();
			op_tail = operator_node;
			break;
		default:
			postfix[j++] = temp;
			break;
		}
	}

	while (1)
	{
		if (op_tail->prev == NULL) break;
		postfix[j++] = op_tail->element;
		op_tail = op_tail->prev;
	}

	printf("���� ��ȯ�� : %s\n", postfix);
}

int num_conversion(char c)
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
	case '4':
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

int calculate()
{
	stack* num_tail;
	int j = 0;
	int postfix_len;
	int a, b, temp;

	postfix_len = strlen(postfix);

	num = memory_alloc();
	num_tail = num;

	// free�ϱ� ���� �Լ���
	stack* current_node;
	stack* prev_node;

	while (1)
	{
		while (1)
		{
			if (postfix[j] != '+' && postfix[j] != '-' && postfix[j] != '*' && postfix[j] != '/')
			{
				num_tail->next = memory_alloc();
				num_tail->next->prev = num_tail;
				num_tail = num_tail->next;
				num_tail->element = postfix[j];
				j++;
			}
			else
				break;
		}
		a = num_conversion(num_tail->prev->element);
		b = num_conversion(num_tail->element);
		if (postfix[j] == '+')
		{
			for (int i = 0; i < 2; i++)
			{
				current_node = num_tail;
				prev_node = num_tail->prev;
				num_tail = num_tail->prev;
				free(current_node);
				current_node = NULL;
			}
			num_tail->next = memory_alloc();
			num_tail->next->prev = num_tail;
			num_tail = num_tail->next;
			temp = a + b;
			num_tail->element = temp;
		}
		else if (postfix[j] == '-')
		{
			for (int i = 0; i < 2; i++)
			{
				current_node = num_tail;
				prev_node = num_tail->prev;
				num_tail = num_tail->prev;
				free(current_node);
				current_node = NULL;
			}
			num_tail->next = memory_alloc();
			num_tail->next->prev = num_tail;
			num_tail = num_tail->next;
			temp = a - b;
			num_tail->element = temp;
		}
		else if (postfix[j] == '*')
		{
			for (int i = 0; i < 2; i++)
			{
				current_node = num_tail;
				prev_node = num_tail->prev;
				num_tail = num_tail->prev;
				free(current_node);
				current_node = NULL;
			}
			num_tail->next = memory_alloc();
			num_tail->next->prev = num_tail;
			num_tail = num_tail->next;
			temp = a * b;
			num_tail->element = temp;
		}
		else if (postfix[j] == '/')
		{
			for (int i = 0; i < 2; i++)
			{
				current_node = num_tail;
				prev_node = num_tail->prev;
				num_tail = num_tail->prev;
				free(current_node);
				current_node = NULL;
			}
			num_tail->next = memory_alloc();
			num_tail->next->prev = num_tail;
			num_tail = num_tail->next;
			temp = a / b;
			num_tail->element = temp;
		}

		if (j == postfix_len - 1)
			break;
		else
			j++;
	}

	result = num_conversion(num_tail->element);


	printf("����� �� :%d\n", result);

	return result;
}