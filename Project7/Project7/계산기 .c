//��Ģ����, �����ư

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int a)
{
	int b;
	int empty;

	printf("���ڸ� �Է��ϼ���: ");
	scanf("%d", &b);
	scanf("%c", &empty);

	return a + b;
}

int subtraction(int a)
{
	int b;
	int empty;

	printf("���ڸ� �Է��ϼ���(�տ� �Է��� ���ں��� ���� ���� �Է��ϼ���): ");
	scanf("%d", &b);
	scanf("%c", &empty);

	return a - b;
}

int multiplication(int a)
{
	int b;
	int empty;

	printf("���ڸ� �Է��ϼ���: ");
	scanf("%d", &b);
	scanf("%c", &empty);

	return a * b;
}

float division(int a)
{
	int b;
	int empty;

	printf("���ڸ� �Է��ϼ���: ");
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
		printf("���ڸ� �Է��ϼ���: ");
		scanf("%d", &num1);
		scanf("%c", &empty);

		printf("+,-,*,/ �� �ϳ��� ������: ");
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

		printf("�����Ͻðڽ��ϱ�? (y/n)\n");
		scanf("%c", &answer);

		if (answer == 'y')
		{	
			break;
		}

	}

	return 0;
}