#include <stdio.h>
#include <string.h> //strcmp �Լ��� ����� �������

int main()
{
	//strcmp(���ڿ�1, ���ڿ�2)==���ڿ� �� ����� ��ȯ
	char s1[10] = "Hello";
	char* s2 = "Hello";

	int ret = strcmp(s1, s2);

	printf("%d\n", ret);

	return 0;
}