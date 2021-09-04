#include <stdio.h>

int main()
{
	char c1 = 'a';
	char c2 = 'b';
	char lineFeed1 = '\n';
	char lineFeed2 = '\t';

	printf("%c%c%c%c", c1, lineFeed1, c2, lineFeed1);
	printf("%c%c%c%C", c1, lineFeed2, c2, lineFeed2);

	return 0;
}