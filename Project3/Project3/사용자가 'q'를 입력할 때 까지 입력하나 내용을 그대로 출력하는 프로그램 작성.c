#include <stdio.h>

int main()
{
	/*사용자가 'q'를 입력할 때 까지 입력한 내용을 그대로 출력하는 프로그램 작성*/

	char c1;

	do
	{
		scanf("%c", &c1);
		printf("%c", c1);
		
	} while (c1 != 'q');

	

	return 0;
}