#include <stdio.h>

int main()
{
	int num1;

	scanf("%d", &num1);

	switch (num1)
	{
	case 1: //=if
		printf("1�Դϴ�.");
		break;
	case 2: //=else if
		printf("2�Դϴ�.\n");
		break;
	default: //else
		printf("defualt\n");
		break;
	}

	return 0;
}