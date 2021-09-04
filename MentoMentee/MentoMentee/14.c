#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print_change_str(char* str, char* find, char* change);
int count_word(char* s);

int main()
{
	char str[80] = { 0 };
	char find[50] = { 0 };
	char change[50] = { 0 };

	printf("문자열을 입력하시오: ");
	scanf("%[^\n]s", str);

	printf("찾을 문자열: ");
	scanf("%s", find);
	
	printf("바꿀 문자열: ");
	scanf("%s", change);

	print_change_str(str, find, change);

	return 0;
}

void print_change_str(char* str, char* find, char* change)
{
	char* token;
	char newStr[20][100] = { 0 };
	char seps[] = " .,\n\t";
	int wc = count_word(str);

	token = strtok(str, seps);
	for (int i = 0; token != NULL; i++)
	{
		strcpy(newStr[i], token);
		token = strtok(NULL, seps);
	}

	printf("수정된 문자열: ");
	for (int i = 0; i < wc; i++)
	{
		if (strcmp(newStr[i], find) == 0)
		{
			strcpy(newStr[i], change);
		}
		printf("%s ", newStr[i]);
	}
	printf("\b.");
}

int count_word(char* s)
{
	int wc = 0;
	int waiting = 1;

	for (int i = 0; s[i] != NULL; i++)
	{
		if (isalpha(s[i]))
		{
			if (waiting)
			{
				wc++;
				waiting = 0;
			}
		}
		else
			waiting = 1;
	}
	return wc;
}