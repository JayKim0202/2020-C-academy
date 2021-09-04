#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char* str);

int main()
{
	char str[100] = { 0 };

	printf("문자열을 입력하시오: ");
	scanf("%[^\n]s", str);

	if (is_palindrome(str))
	{
		printf("회문입니다.");
	}
	else
	{
		printf("회문이 아닙니다.");
	}



	return 0;
}

int is_palindrome(char* str)
{
	int j, k;
	int length;
	char* token;
	char newStr[100] = { 0 };
	char seps[] = " .,\n\t";
	int is_same_count = 0;
	int count = 1;

	for (int i = 0; str[i] != NULL; i++)
	{
		if (isupper(str[i]))
		{
			str[i] = tolower(str[i]);
		}
	}

	token = strtok(str, seps);
	while (token != NULL)
	{
		strcat(newStr, token);
		token = strtok(NULL, seps);
	}

	length = strlen(newStr) - 1;
	
	for (j = 0, k = length; j < length / 2; j++, k--)
	{
		if (newStr[j] == newStr[k])
			is_same_count++;
	}

	if (is_same_count == length / 2)
		return 1;
	else
		return 0;
}