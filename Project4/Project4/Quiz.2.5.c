#include <stdio.h>
#include <stdlib.h>

int main()
{
	//ǥ�� �Է����� � ���ڿ� �� ���� �Էµ˴ϴ�(�� ���ڿ��� ���̴� 30����). ���ڿ� �� ���� ���� ���پ� ����ϴ� ���α׷��� ���弼��.
	
	char* s1 = malloc(sizeof(char) * 30);
	char* s2 = malloc(sizeof(char) * 30);
	char* s3 = malloc(sizeof(char) * 30);
	char* s4 = malloc(sizeof(char) * 30);

	printf("���ڿ��� �Է��ϼ���: ");
	gets(s1);
	gets(s2);
	gets(s3);
	gets(s4);

	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%s\n", s3);
	printf("%s\n", s4);

	free(s1);
	free(s2);
	free(s3);
	free(s4);
	
	return 0;
}