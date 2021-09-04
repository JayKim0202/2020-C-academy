#include <stdio.h>

int main()
{
	/*표준 입력으로 정수 두 개가 입력됩니다.(첫 번째 입력 값의 범위는 1~200, 두 번째 입력 값의 범위는 10~200이며,
	첫 번째 입력 값은 두 번째 입력 값보다 항상 작습니다).
	다음 소스 코드를 완성하여 첫 번째 정수와 두 번째 정수 사이의 숫자 중 7로 끝나지 않는 숫자가 출력되게 만드세요.*/

	int num1;
	int num2;
	int i;
	
	scanf("%d %d", &num1, &num2);

	i = num1;

	while (1)
	{
		if (i % 10 == 7)
		{
			i++;
			continue;
		}

		if (i > num2)
			break;


		printf("%d ", i);
		i++;
	}

	return 0;
}