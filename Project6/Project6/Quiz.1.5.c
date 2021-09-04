//표준 입력으로 실수가 입력됩니다. 다음 소스 코드를 완성하여 입력된 실수에서 소수점 이하를 버림 결과가 출력되게 만드세요.
//단, 컴파일 경고가 발생하지 않아야 합니다.

#include <stdio.h>

int main()
{
	float num1;
	int num2;

	scanf("%f", &num1);

	num2 = (int)num1;

	printf("%d\n", num2);

	return 0;
}