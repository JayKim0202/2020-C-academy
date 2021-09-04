#include <stdio.h>

int main()
{
	/*표준 입력으로 문자가 입력됩니다. 입력된 문자기 a이면 "a입니다."를 출력하고, a가 아니면 "a가 아닙니다."를 출력하는 프롤그램을 만드세요.*/

	char c1;

	scanf("%c", &c1);

	if (c1 == 'a')
		printf("a입니다.\n");
	else
		printf("a가 아닙니다.\n");

	return 0;
}