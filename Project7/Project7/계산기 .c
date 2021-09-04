//사칙연산, 종료버튼

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int a)
{
	int b;
	int empty;

	printf("숫자를 입력하세요: ");
	scanf("%d", &b);
	scanf("%c", &empty);

	return a + b;
}

int subtraction(int a)
{
	int b;
	int empty;

	printf("숫자를 입력하세요(앞에 입력한 숫자보다 작은 수를 입력하세요): ");
	scanf("%d", &b);
	scanf("%c", &empty);

	return a - b;
}

int multiplication(int a)
{
	int b;
	int empty;

	printf("숫자를 입력하세요: ");
	scanf("%d", &b);
	scanf("%c", &empty);

	return a * b;
}

float division(int a)
{
	int b;
	int empty;

	printf("숫자를 입력하세요: ");
	scanf("%d", &b);
	scanf("%c", &empty);
	

	return a / b;
}


int main()
{
	int num1;
	char arithmeticSymbol;
	char empty;
	char answer;

	while (1)
	{
		printf("숫자를 입력하세요: ");
		scanf("%d", &num1);
		scanf("%c", &empty);

		printf("+,-,*,/ 중 하나를 고르세요: ");
		scanf("%c", &arithmeticSymbol);


		switch (arithmeticSymbol)
		{
		case'+':
		{
			printf("%d\n", sum(num1));
			break;
		}
		case'-':
		{
			printf("%d\n", subtraction(num1));
			break;
		}
		case'*':
		{
			printf("%d\n", multiplication(num1));
			break;
		}
		case'/':
		{
			printf("%f\n", division(num1));
			break;
		}
		}

		printf("종료하시겠습니까? (y/n)\n");
		scanf("%c", &answer);

		if (answer == 'y')
		{	
			break;
		}

	}

	return 0;
}