#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* s1 = malloc(sizeof(char) * 10);
	char* s2 = malloc(sizeof(char) * 10);
	char* s3 = malloc(sizeof(char) * 10);

	printf("���ڿ��� �� �� �Է��ϼ���: ");
	gets(s1);
	gets(s2);
	gets(s3);

	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%s\n", s3);
	
	free(s1);
	free(s2);
	free(s3);

	return 0;
}