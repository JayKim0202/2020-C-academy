//getSum 함수에는 10진수로 된 문자열과 정수가 들어갑니다. 다음 소스 코드를 완성하여 getSum 함수에 지정된 값의 합이 출력되게 만드세요.

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

long long getSum(char* types, ...)
{
	va_list ap;
	int i = 0;
	long long result = 0;

	va_start(ap, types);
	while (types[i] != '\0')
	{
		switch (types[i])
		{
		case 's':
			result += atoi(va_arg(ap, char*));
			break;
		case 'i':
			result += va_arg(ap, int);
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
	printf("%lld\n", getSum("siis", "12", 30000, 500000, "300"));
	printf("%lld\n", getSum("ssi", "150", "150", 100));

	return 0;
}