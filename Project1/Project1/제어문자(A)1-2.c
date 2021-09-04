#include <stdio.h>

int main()
{
	char lineFeed1 = '\n';
	char lineFeed2 = '\t';

	printf("%d 0x%x\n", lineFeed1, lineFeed1);
	printf("%d 0x%x\n", lineFeed2, lineFeed2);

	return 0;
}