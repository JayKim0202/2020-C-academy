//다음 소스 코드를 완성하여 1 1이 출력되게 만드세요.
#include <stdio.h>
#include <stdlib.h>

union Data {
	short num1;
	int num2;
};

int main()
{
	union Data* d1 = malloc(sizeof(union Data));

	d1->num2 = 1;

	printf("%d %d\n", d1->num1, d1->num2);

	free(d1);

	return 0;
}