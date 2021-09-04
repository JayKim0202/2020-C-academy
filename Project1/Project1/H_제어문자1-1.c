#include <stdio.h>

int main()
{
	char c1 = 'a';				//문자 a 할당
	char c2 = 'b';				//문자 b 할당
	char linefeed1 = '\n';		//제어문자 \n할당
	char linefeed2 = '\t';		//제어문자 \t할당

	printf("%c%c%c%c", c1, linefeed1, c2, linefeed1);	//제어문자도 %c로 출력할 수 있음
	printf("%c%c%C%C", c1, linefeed2, c2, linefeed1);

	return 0;
}