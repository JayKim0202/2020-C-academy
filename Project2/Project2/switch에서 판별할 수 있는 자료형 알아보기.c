#include <stdio.h>

int main()
{
	char c1;

	scanf("%c", &c1);

	switch (c1)
	{
	case 'a':
		printf("a�Դϴ�.\n");
		break;
	case 'b':
		printf("b�Դϴ�.\n");
		break;
	default:
		printf("default\n");
		break;
	}

	return 0;
}