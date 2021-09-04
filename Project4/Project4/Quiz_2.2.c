#include <stdio.h>

int main()
{
	char s1[20];
	
	sprintf(s1, "%dth %s", 9, "Symphony");

	printf("%s\n", s1);

	return 0;
}