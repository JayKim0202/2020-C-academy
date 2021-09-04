#include <stdio.h>
#include <string.h>

int main()
{
	char s[100];
	int num;

	scanf("%s", &s); //왜

	num =strlen(s);

	printf("%d\n", num); //2: 한글은 한글자를 2로 판단

	return 0;
}