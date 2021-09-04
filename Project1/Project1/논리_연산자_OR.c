#include <stdio.h>

int main()
{
	//|| = OR(논리합), 양쪽 중 한쪽만 참이라도 참
	printf("%d\n", 1 || 1);
	printf("%d\n", 1 || 0);
	printf("%d\n", 0 || 1);
	printf("%d\n", 0 || 0);

	printf("%d\n", 2 || 3);

	return 0;
}