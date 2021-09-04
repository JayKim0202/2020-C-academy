//최대 길이 100자 미만의 문자열이 저장된 words.txt 파일이 주어집니다. 다음 소스 코드를 완성하여 words.txt에서 문자열을 읽도록 만드세요.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char* s1 = "This speech caused a remarkable sensation among the party.";

	FILE* fp = fopen("words.txt", "w");

	fwrite(s1, strlen(s1), 1, fp);

	fclose(fp);

	return 0;
}