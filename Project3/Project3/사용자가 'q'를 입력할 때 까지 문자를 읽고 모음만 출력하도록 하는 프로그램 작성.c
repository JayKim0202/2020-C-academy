#include <stdio.h>

int main()
{
	char c1;

	do
	{
		scanf("%c", &c1);

		if (c1 == 'a')
			printf("%c\n", c1);
		else if (c1 == 'e')
			printf("%c\n", c1);
		else if (c1 == 'i')
			printf("%c\n", c1);
		else if (c1 == 'o')
			printf("%c\n", c1);
		else if (c1 == 'u')
			printf("%c\n", c1);
		else
			printf("");

		/*if (c1 == 'a' || c1 == 'e' || c1 == 'i' || c1 == 'o' || c1 == 'u')
			printf("%c\n", c1);
		else
			printf("");*/

	} while (c1 != 'q');
}