#include <stdio.h>
#include <ctype.h>

int count_word(char* s);

int main()
{
	int wc = count_word("I am a boy.");
	printf("wc : %d", wc);
	
	return 0;
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