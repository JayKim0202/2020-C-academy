#include <stdio.h>
#include <time.h>

typedef struct card {
	int value;
	char suit;
}CARD;


int main()
{
	CARD card[52];
	int count = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 14; j++)
		{
			card[count].value = j;
			switch (i)
			{
			case 0:
				card[count].suit = 'c';
				break;
			case 1:
				card[count].suit = 'd';
				break;
			case 2:
				card[count].suit = 'h';
				break;
			case 3:
				card[count].suit = 's';
				break;
			}
			count++;
		}
	}
	
	for (int i = 0; i < 52; i++)
	{
		printf("%d:%c ", card[i].value, card[i].suit);
	}
	return 0;
}