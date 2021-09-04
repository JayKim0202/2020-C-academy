#include <stdio.h>

int main()
{
	int score;

	scanf("%d", &score);

	if (score >= 90)
		printf("A\n");
	else if (score >= 80 && score < 90)
		printf("B\n");
	else if (score >= 70 && score < 80)
		printf("C\n");
	else
		printf("Àç½ÃÇè\n");

	return 0;
}