#include <stdio.h>

int main()
{
	int num1;
	int num2;

	scanf("%d %d", &num1, &num2);

	printf("%s\n", num1 && num2 ? "��" : "����");
	printf("%s\n", num1 || num2 ? "��" : "����");
	printf("%s\n", !num1 ? "��" : "����");

	return 0;
}