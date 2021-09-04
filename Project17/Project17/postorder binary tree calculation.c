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

typedef struct tree_stack
{
	void* ptr;
	struct tree_stack* prev;
	struct tree_stack* next;
}tree_stack;

stack* memory_alloc_stack();
tree* memory_alloc_tree();
tree_stack* memory_alloc_tree_stack();
void input();
void infix_to_postfix();
char operator_precedence_comparison(stack* oper);
void make_tree();
tree* add_tree(tree_stack* tree_s, char postfix);
int num_conversion(char c);
int calculate(tree* root_c);

char infix[MAX];
char postfix[MAX];
stack* operator_node;
tree_stack* tree_s;
tree* root;
int result;
int temp[2] = { 0 };
int i = 0;

int main()
{
	operator_node = memory_alloc_stack();
	tree_s = memory_alloc_tree_stack();
	root = memory_alloc_tree();

	input();
	infix_to_postfix();
	make_tree();
	result = calculate(root);

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
	tree* temp = malloc(sizeof(tree));

	temp->c = NULL;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

tree_stack* memory_alloc_tree_stack()
{
	tree_stack* temp = malloc(sizeof(tree_stack));
	temp->ptr = NULL;
	temp->prev = NULL;
	temp->next = NULL;
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

tree* add_tree(tree_stack* tree_s, char postfix)
{
	tree* new_node;
	new_node = memory_alloc_tree();
	new_node->left = memory_alloc_tree();
	new_node->right = memory_alloc_tree();

	new_node->c = postfix;
	if (tree_s->prev != NULL)
		new_node->left->c = *(char*)tree_s->ptr;
	else
		new_node->left = tree_s->ptr;
	new_node->right->c = *(char*)tree_s->next->ptr;

	return new_node;

}

void make_tree()
{
	tree_stack* tree_s_tail;
	tree_s_tail = tree_s;

	/*tree_stack* free_node1;
	tree_stack* free_node2;*/

	tree* temp_root1, *temp_root2, *temp_root3, *temp_root4;
	temp_root1 = NULL;
	temp_root2 = NULL;
	temp_root3 = NULL;
	temp_root4 = NULL;

	int final_node = 0;

	int p = 0;

	while (1)
	{
		if (postfix[p] == '\0') break;

		switch (postfix[p++])
		{
		case '+':
			tree_s = tree_s->next;
			temp_root1 = add_tree(tree_s, postfix[p - 1]);
			/*free_node1 = tree_s;
			free_node2 = tree_s->next;
			free(free_node1);
			free(free_node2);
			free_node1 = NULL;
			free_node2 = NULL;
			tree_s = NULL;*/
			tree_s = tree_s->next->next;
			tree_s = memory_alloc_tree_stack();
			tree_s_tail = tree_s;
			tree_s_tail->next = memory_alloc_stack();
			tree_s_tail = tree_s_tail->next;
			tree_s_tail->ptr = temp_root1;
			/*switch (final_node)
			{
			case 1:
				temp_root1 = NULL;
				break;
			case 2:
				temp_root2 = NULL;
				break;
			case 3:
				temp_root3 = NULL;
				break;
			case 4:
				temp_root4 = NULL;
				break;
			default:
				break;
			}*/
			final_node = 1;
			break;
		case '-':
			tree_s = tree_s->next;
			temp_root2 = add_tree(tree_s, postfix[p - 1]);
			/*free_node1 = tree_s;
			free_node2 = tree_s->next;
			free(free_node1);
			free(free_node2);
			free_node1 = NULL;
			free_node2 = NULL;
			tree_s = NULL;*/
			tree_s = tree_s->next->next;
			tree_s = memory_alloc_tree_stack();
			tree_s_tail = tree_s;
			tree_s_tail->next = memory_alloc_stack();
			tree_s_tail = tree_s_tail->next;
			tree_s_tail->ptr = temp_root2;
			/*switch (final_node)
			{
			case 1:
				temp_root1 = NULL;
				break;
			case 2:
				temp_root2 = NULL;
				break;
			case 3:
				temp_root3 = NULL;
				break;
			case 4:
				temp_root4 = NULL;
				break;
			default:
				break;
			}*/
			final_node = 2;
			break;
		case '*':
			tree_s = tree_s->next;
			temp_root3 = add_tree(tree_s, postfix[p - 1]);
			/*free_node1 = tree_s;
			free_node2 = tree_s->next;
			free(free_node1);
			free(free_node2);
			free_node1 = NULL;
			free_node2 = NULL;
			tree_s = NULL;*/
			tree_s = tree_s->next->next;
			tree_s = memory_alloc_tree_stack();
			tree_s_tail = tree_s;
			tree_s_tail->next = memory_alloc_stack();
			tree_s_tail = tree_s_tail->next;
			tree_s_tail->ptr = temp_root3;
			/*switch (final_node)
			{
			case 1:
				temp_root1 = NULL;
				break;
			case 2:
				temp_root2 = NULL;
				break;
			case 3:
				temp_root3 = NULL;
				break;
			case 4:
				temp_root4 = NULL;
				break;
			default:
				break;
			}*/
			final_node = 3;
			break;
		case '/':
			tree_s = tree_s->next;
			temp_root4 = add_tree(tree_s, postfix[p - 1]);
			/*free_node1 = tree_s;
			free_node2 = tree_s->next;
			free(free_node1);
			free(free_node2);
			free_node1 = NULL;
			free_node2 = NULL;
			tree_s = NULL*/
			tree_s = tree_s->next->next;
			tree_s = memory_alloc_tree_stack();
			tree_s_tail = tree_s;
			tree_s_tail->next = memory_alloc_stack();
			tree_s_tail = tree_s_tail->next;
			tree_s_tail->ptr = temp_root4;
			/*switch (final_node)
			{
			case 1:
				temp_root1 = NULL;
				break;
			case 2:
				temp_root2 = NULL;
				break;
			case 3:
				temp_root3 = NULL;
				break;
			case 4:
				temp_root4 = NULL;
				break;
			default:
				break;
			}*/
			final_node = 4;
			break;
		default:
			tree_s_tail->next = memory_alloc_tree_stack();
			tree_s_tail->next->prev = tree_s_tail;
			tree_s_tail = tree_s_tail->next;
			tree_s_tail->ptr = &postfix[p - 1];
			break;
		}

	}

	switch (final_node)
	{
	case 1:
		root = temp_root1;
		break;
	case 2:
		root = temp_root2;
		break;
	case 3:
		root = temp_root3;
		break;
	case 4:
		root = temp_root4;
	}

	return;
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

int calculate(tree* root_c)
{
	if (root_c == NULL)
		return temp[0];

	if (root_c ->left != NULL)
		calculate(root_c ->left);

	switch (root_c->c)
	{
	case '+':
		if (temp[0] == 0)
			temp[0] = num_conversion(root_c->left->c);
		temp[1] = num_conversion(root_c->right->c);
		temp[0] = temp[0] + temp[1];
		temp[1] = 0;
		break;
	case '-':
		if (temp[0] == 0)
			temp[0] = num_conversion(root_c->left->c);
		temp[1] = num_conversion(root_c->right->c);
		temp[0] = temp[0] - temp[1];
		temp[1] = 0;
		break;
	case '*':
		if (temp[0] == 0)
			temp[0] = num_conversion(root_c->left->c);
		temp[1] = num_conversion(root_c->right->c);
		temp[0] = temp[0] * temp[1];
		temp[1] = 0;
		break;
	case '/':
		if (temp[0] == 0)
			temp[0] = num_conversion(root_c->left->c);
		temp[1] = num_conversion(root_c->right->c);
		temp[0] = temp[0] / temp[1];
		temp[1] = 0;
		break;
	}

	if (root_c ->right != NULL)
		calculate(root_c ->right);

	return temp[0];
}