#include <stdio.h>

int main()
{
	int num1 = 1;
	int num2;

	num2 = ++num1; //변수를 먼저 평가하고 앞에 있는 ++를 먼저 계산

	printf("%d\n", num2);

	/*num5 = num4 = num3 = num2 = num1 = 10 ;
	오른쪽에서 왼쪽으로 차례차례 할당 : num5 = 10*/

	return 0;
}