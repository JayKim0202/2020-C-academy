#include <stdio.h>
#include <stdlib.h>

int main()
{
	//표준 입력으로 어떤 문자열 네 개가 입력됩니다(각 문자열의 길이는 30이하). 문자열 네 개를 각가 한줄씩 출력하는 프로그램을 만드세요.
	
	char* s1 = malloc(sizeof(char) * 30);
	char* s2 = malloc(sizeof(char) * 30);
	char* s3 = malloc(sizeof(char) * 30);
	char* s4 = malloc(sizeof(char) * 30);

	printf("문자열을 입력하세요: ");
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