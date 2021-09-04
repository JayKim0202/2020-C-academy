//수식입력
//후위식 변환
//후위식 출력
//종료
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct equation
{
	char element;
	struct equation* next;
};

struct stack
{
	char operator_ch;
	struct stack* next;
	struct stack* prev;
};

struct equation* input();
void infix_to_postfix();
struct equation* memory_alloc_equation();
struct stack* memory_alloc_stack();
int check_operator(char op);
char check_num(char eq);
struct stack* push(char eq, struct stack* tail);
//struct equation* pop(struct	stack* op);
struct equation* operator_precedence_comparison(struct stack* op_tail, struct equation* post_tail);

struct equation* infix;
struct equation* postfix;
struct stack* operator_ptr;


int main()
{
	int menu = 0;
	infix = memory_alloc_equation();
	postfix = memory_alloc_equation();
	operator_ptr = memory_alloc_stack();

	while (1)
	{
		printf("1.수식 입력 2. 후위식 변환 3. 후위식 출력 4. 종료\n");
		scanf("%d", &menu);
		getchar();

		switch (menu)
		{
		case 1:
			infix = input();
			break;
		case 2:
			infix_to_postfix();
			break;
		case 3:
			break;
		case 4:
			exit(0);
		}
	}
}

struct equation* memory_alloc_equation()
{
	struct equation* temp;
	temp = malloc(sizeof(struct equation));

	temp->element = NULL;
	temp->next = NULL;

	return temp;
}

struct stack* memory_alloc_stack()
{
	struct stack* temp;
	temp = malloc(sizeof(struct stack));

	temp->operator_ch = NULL;
	temp->next = NULL;
	temp->prev = NULL;

	return temp;
}

struct equation* input()
{
	char temp;
	int i = 0;
	struct equation* infix_tail;
	infix_tail = infix;

	printf("수식을 입력하세요\n");

	while (1)
	{
		temp = getch();
		if (temp == 61 || temp == '\r') break; // '='등호 또는 '\r'엔터 입력 시 중지
		printf("%c", temp);

		infix_tail->next = memory_alloc_equation();
		infix_tail = infix_tail->next;
		infix_tail->element = temp;
	}
	printf("\n");

	return infix;
}

int check_operator(char op)
{
	switch (op)
	{
	case 43:	// +
		return 1;
	case 45:	// -
		return 2;
	case 42:	// *
		return 3;
	case 47:	// /
		return 4;
	case 40:	// (
		return 5;
	case 41:	// )
		return 6;
	default:
		exit(1);
	}
}

char check_num(char eq)
{
	switch (eq)
	{
	case 48:
		return 0;
	case 49:
		return 1;
	case 50:
		return 2;
	case 51:
		return 3;
	case 52:
		return 4;
	case 53:
		return 5;
	case 54:
		return 6;
	case 55:
		return 7;
	case 56:
		return 8;
	case 57:
		return 9;
	default:
		return NULL;
	}
}

struct stack* push(char eq, struct stack* tail)
{
	struct stack* temp;
	temp = memory_alloc_stack();

	temp->operator_ch = eq;
	temp->prev = tail;
	temp->next = NULL;
	return temp;
}

/*struct equation* pop(struct stack* op)
{
	return op;
}*/

struct equation* operator_precedence_comparison(struct stack* op_tail, struct equation* post_tail)
{
	struct stack* op_head;
	op_head = operator_ptr;
	op_head = op_head->next;
	operator_ptr = operator_ptr->next;

	if (op_tail->operator_ch == '*' || op_tail->operator_ch == '/')
	{
		while (1)
		{
			post_tail->next = memory_alloc_equation();
			post_tail = post_tail->next;
			post_tail->element = operator_ptr->operator_ch;
			operator_ptr = operator_ptr->next;
			if (operator_ptr->next == NULL) break;
		}
		//free(op_head); (반복)
		return post_tail;
	}

	
	
}

void infix_to_postfix()
{
	int op_num;
	int eq_num;

	struct equation* read_infix;
	read_infix = infix->next;
	struct equation* postfix_tail;
	postfix_tail = postfix;

	struct stack* operator_ptr_tail;
	operator_ptr_tail = operator_ptr;

	while (1)
	{
		op_num = check_num(read_infix->element);

		if (op_num == NULL)
		{
			eq_num = check_operator(read_infix->element);

			operator_ptr_tail->next = memory_alloc_equation();

			switch (eq_num)
			{
			case 1: // +
				postfix_tail = operator_precedence_comparison(operator_ptr_tail, postfix_tail);
				operator_ptr_tail->next = push(read_infix->element, operator_ptr_tail);
				operator_ptr_tail = operator_ptr_tail->next;
				break;
			case 2:	// -
				operator_ptr_tail->next = push(read_infix->element, operator_ptr_tail);
				operator_ptr_tail = operator_ptr_tail->next;
				break;
			case 3:	// *
				operator_ptr_tail->next = push(read_infix->element, operator_ptr_tail);
				operator_ptr_tail = operator_ptr_tail->next;
				
				break;
			case 4:	// /
				operator_ptr_tail->next = push(read_infix->element, operator_ptr_tail);
				operator_ptr_tail = operator_ptr_tail->next;
				break;
			case 5:	// (
				operator_ptr_tail->next = push(read_infix->element, operator_ptr_tail);
				operator_ptr_tail = operator_ptr_tail->next;
				break;
			case 6:	// )
				//pop();
				break;
			}
		}
		else
		{
			postfix_tail->next = memory_alloc_equation();
			postfix_tail = postfix_tail->next;
			postfix_tail->element = read_infix->element;
		}
		
		read_infix = read_infix->next;
		if (read_infix == NULL) break;
	}

	return;
}

// + : 43		1
// - : 45		2
// * : 42		3
// / : 47		4
// ( : 40		5
// ) : 41		6
// = : 61

// 5 + 2 / 7 = 5 2 7 / +

// ( 1 + 2 ) * 7 = 1 2 + 7 *

// 1 + 2 * 7 = 1 2 7 * +

// 1 + 2 - 1 = 1 2 + 1 -

// ( 4 + 6 - 2 ) / 2 = 4 6 + 2 - 2 /

// 1 + 2 * 3 + 4 = 1 2 3 * + 4 +


/*
	0 = 48
	1 = 49
	2 = 50
	3 = 51
	4 = 52
	5 = 53
	6 = 54
	7 = 55
	8 = 56
	9 = 57
*/

// pop으로 꺼내서 비교 후 다시 push