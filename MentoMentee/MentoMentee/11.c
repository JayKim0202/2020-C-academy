#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print_reverse(char* str, int wc);
int count_word(char* s);

int main()
{
	char str[100] = { 0 };

	printf("문자열을 입력하시오: ");
	scanf("%[^\n]s", str);

	print_reverse(str, count_word(str));
}

void print_reverse(char* str, int wc)
{
	char reverse_s[20][100] = { 0 };
	char* token;
	char seps[] = " .,\n\t";

	token = strtok(str, seps);
	for (int i = wc - 1; token != NULL; i--)
	{
		strcpy(reverse_s[i], token);
		token = strtok(NULL, seps);
	}

	for (int i = 0; i <= wc; i++)
	{
		printf("%s ", reverse_s[i]);
	}
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