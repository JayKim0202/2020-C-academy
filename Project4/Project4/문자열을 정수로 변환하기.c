#include <stdio.h>
#include <stdlib.h> //atoi �Լ��� ����� ��� ���� == ASCII string to integer

int main()
{
	char* s1 = "283";
	int num1;
	num1 = atoi(s1);

	printf("%d\n", num1);

	return 0;
}