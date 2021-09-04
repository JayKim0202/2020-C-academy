#include <stdio.h>

int main()
{
	char linefeed1;
	char linefeed2;
	char linefeed3;

	linefeed1 = '\t';
	linefeed2 = '\n';
	linefeed3 = '\t';

	printf("Hello%cworld%cHello%cworld%c", linefeed1, linefeed2, linefeed3, linefeed2);
	//Hello		world
	//Hello		world

	return 0;
}