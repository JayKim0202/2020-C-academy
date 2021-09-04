#include <stdio.h>

int main()
{
	char linefeed1 = '\n'; //제어문자 \n할당
	char linefeed2 = '\t'; //제어문자 \t할당

	printf("%d 0x%x\n", linefeed1, linefeed1); //10 0xa: 제어문자의 ASCII코드 출력
	printf("%d 0x%x\n", linefeed2, linefeed2); //9 0x9: 제어문자의 ASCII코드 출력
	
}