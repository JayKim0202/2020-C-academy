#include <stdio.h>

int main()
{
	char ans1;
	char ans2;
	int count = 0;

	scanf("%c %c", &ans1, &ans2);

	if (ans1 == 'a')
		count++;
	else if (ans1 == 'b')
		count = count;
	else if (ans1 == 'c')
		count = count;
	else if (ans1 == 'd')
		count = count;
	else if (ans1 == 'e')
		count++;
	else
		printf("a,b,c,d,e 중 선택하시오.\n");

	if (ans2 == 'a')
		count++;
	else if (ans2 == 'b')
		count = count;
	else if (ans2 == 'c')
		count = count;
	else if (ans2 == 'd')
		count = count;
	else if (ans2 == 'e')
		count++;
	else
		printf("a,b,c,d,e 중 선택하시오.\n");

	if (count == 2)
		printf("정답입니다.\n");
	else
		printf("오답입니다.\n");

	return 0;
}