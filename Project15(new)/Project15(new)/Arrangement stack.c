#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>

int push();
int pop(int tp);

int stack[10];
int bp;
int sp;

int main()
{
	int menu;

	bp = 0;
	sp = bp;

	while (1)
	{
		printf("1.스택 저장 2.출력 3.종료\n");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			stack[sp++] = push();
			break;
		case 2:
			pop(sp);
			break;
		case 3:
			exit(0);
		}

	}

	return 0;
}

int push()
{
	int temp = 0;

	if (sp >= 10)
	{
		printf("stack overflow\n");
		return;
	}

	scanf("%d", &temp);

	return temp;
}

int pop(int tp)
{
	if (sp == 0)
	{
		printf("stack underflow\n");
		return 0;
	}
	else
	{
		printf("top : %d\n", stack[tp - 1]);
	}

	return sp++;
}