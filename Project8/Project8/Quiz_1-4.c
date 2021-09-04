//표준 입력으로 정수 세 개가 입력됩니다. 다음 소스 코드를 완성하여 getSum 함수에 들어간 가변 인자 중에서 정수의 합을 구하도록 만드세요.

/*125 291 443*/
/*
135
291
63
2612
*/

#define _CRT_SECURE_NO_WANINGS
#include <stdio.h>
#include <stdarg.h>

int getSum(char* types, ...)
{
	va_list ap;
	int result = 0;
	int i = 0;
	char* str;
	double d;
	int num = 0;

	va_start(ap, types);
	while (types[i] != '\0')
	{
		switch (types[i])
		{
		case 'i':
			num = va_arg(ap, int);
			result += num;
			break;
		case 's':
			str = va_arg(ap, char*);
			break;
		case 'd':
			d = va_arg(ap, double);
			break;
		default:
			break;
		}
		i++;
	}
	va_end(ap);

	return result;
}

int main()
{
	int num1, num2, num3;

	scanf("%d %d %d", &num1, &num2, &num3);

	printf("%d\n", getSum("isi", num1, "C", 10));
	printf("%d\n", getSum("sdsi", "Hello, world!", 5.3, "A", num2));
	printf("%d\n", getSum("iiss", 25, 38, "k", "R"));
	printf("%d\n", getSum("sidii", "Hello, C", num3, 2.234567, 878, 1291));

	return 0;
}