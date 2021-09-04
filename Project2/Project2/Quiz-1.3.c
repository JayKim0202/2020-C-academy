#include <stdio.h>

int main()
{
	//표준 입력으로 문자 하나가 입력됩니다. 입력된 문자부터 Z까지 순서대로 출력하는 프로그램을 만드세요.

	char i;

	scanf("%c", &i);

	for ( i; i <= 'z'; i++)
	{
		printf("%c", i);
	}
	
	return 0;
}