#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 4000

typedef struct stack
{
	char element;
	struct stack* prev;
	struct stack* next;
} stack;

typedef struct tree
{
	char c;
	struct tree* left;
	struct tree* right;
}tree;

stack* memory_alloc_stack();
tree* memory_alloc_tree();
void input();
void infix_to_postfix();
char operator_precedence_comparison(stack* oper);
tree* make_tree();

char infix[MAX];
char postfix[MAX];
stack* operator_node;
stack* tree_stack;
tree* root;

int main()
{
	operator_node = memory_alloc_stack();
	tree_stack = memory_alloc_stack();
	root = memory_alloc_tree();

	input();
	infix_to_postfix();
	make_tree();

	return 0;
}

stack* memory_alloc_stack()
{
	stack* temp = malloc(sizeof(stack));
	temp->element = NULL;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

tree* memory_alloc_tree()
{
	tree* temp;
	temp = malloc(sizeof(tree));

	temp->c = NULL;
	temp->left = NULL;
	temp->right = NULL;

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
				operator_node = memory_alloc_stack();
				op_tail = operator_node;
			}
			op_tail->next = memory_alloc_stack();
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
				operator_node = memory_alloc_stack();
				op_tail = operator_node;
			}
			op_tail->next = memory_alloc_stack();
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
				operator_node = memory_alloc_stack();
				op_tail = operator_node;
			}
			op_tail->next = memory_alloc_stack();
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
				operator_node = memory_alloc_stack();
				op_tail = operator_node;
			}
			op_tail->next = memory_alloc_stack();
			op_tail->next->prev = op_tail;
			op_tail = op_tail->next;
			op_tail->element = temp;
			break;
		case '(':
			op_tail->next = memory_alloc_stack();
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
			operator_node = memory_alloc_stack();
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

	printf("후위 변환식 : %s\n", postfix);
}

tree* make_tree()
{
	stack* tree_stack_tail;
	tree_stack_tail = tree_stack;

	stack* free_node1;
	stack* free_node2;

	char temp;
	int p = 0;

	while (1)
	{
		temp = postfix[p++];
		if (temp == '\0') break;

		switch (temp)
		{
		case '+':
			root->c = '+';
			root->left = memory_alloc_tree();
			root->left->c = tree_stack->next->element;
			free_node1 = tree_stack->next;
			root->right = memory_alloc_tree();
			root->right->c = tree_stack->next->next->element;
			free_node2 = tree_stack->next->next;
			free(free_node1);
			free(free_node2);
			tree_stack = NULL;
			tree_stack = memory_alloc_stack();
			tree_stack_tail = tree_stack;
			tree_stack_tail->next = root;
			tree_stack_tail = tree_stack_tail->next;
			break;
		case '-':
			root->c = '-';
			root->left = memory_alloc_tree();
			root->left->c = tree_stack->next->element;
			free_node1 = tree_stack->next;
			root->right = memory_alloc_tree();
			root->right->c = tree_stack->next->next->element;
			free_node2 = tree_stack->next->next;
			free(free_node1);
			free(free_node2);
			tree_stack = NULL;
			tree_stack = memory_alloc_stack();
			tree_stack_tail = tree_stack;
			tree_stack_tail->next = root;
			tree_stack_tail = tree_stack_tail->next;
			break;
		case '*':
			root->c = '*';
			root->left = memory_alloc_tree();
			root->left->c = tree_stack->next->element;
			free_node1 = tree_stack->next;
			root->right = memory_alloc_tree();
			root->right->c = tree_stack->next->next->element;
			free_node2 = tree_stack->next->next;
			free(free_node1);
			free(free_node2);
			tree_stack = NULL;
			tree_stack = memory_alloc_stack();
			tree_stack_tail = tree_stack;
			tree_stack_tail->next = root;
			tree_stack_tail = tree_stack_tail->next;
			break;
		case '/':
			root->c = '/';
			root->left = memory_alloc_tree();
			root->left->c = tree_stack->next->element;
			free_node1 = tree_stack->next;
			root->right = memory_alloc_tree();
			root->right->c = tree_stack->next->next->element;
			free_node2 = tree_stack->next->next;
			free(free_node1);
			free(free_node2);
			tree_stack = NULL;
			tree_stack = memory_alloc_stack();
			tree_stack_tail = tree_stack;
			tree_stack_tail->next = root;
			tree_stack_tail = tree_stack_tail->next;
			break;
		default: // 숫자가 나올 때
			tree_stack_tail->next = memory_alloc_stack();
			tree_stack_tail->next->prev = tree_stack_tail;
			tree_stack_tail = tree_stack_tail->next;
			tree_stack_tail->element = temp;
			break;
		}
	}
}