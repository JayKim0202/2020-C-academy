/*1.c
2.e
3.a
*/

//다음 소스 코드를 완성하여 printStrings 함수에 지정된 문자열이 출력되게 만드세요.

#include <stdio.h>
#include <stdarg.h>

void printString(int args, ...)
{
	va_list ap;

	va_start(ap, args);
	for (int i = 0; i < args; i++)
	{
		char* str = va_arg(ap, char*);
		printf("%s ", str);
	}
	va_end(ap);

	printf("\n");
}

int main()
{
	printString(2, "C", "Language");
	printString(3, "The", "Little", "Prince");

	return 0;
}