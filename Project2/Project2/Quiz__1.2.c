#include <stdio.h>

int main()
{
	/*다음 소스 코드를 완성하여 문자 'q'를 입력하면 프로그램이 종료되게 만드세요.*/

	char c1;

	do
	{
		scanf("%c", &c1);
	} while (c1 != 'q');

	printf("프로그램 종료\n");

	return 0;
}