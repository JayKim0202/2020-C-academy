#include <stdio.h>

int main()
{
	/*표준 입력으로 정수 두 개가 입력됨빈다.(첫 번째 입력 값의 범위는 1~1000, 두번째 입력 값의 범위는 10~1000이며 척번째 입력 값은 두 번째 입력 값보다 항상 작습니다).
	첫 번째 정수부터 두번째 정수까지 숫자를 출력하면서 5의 배수 일때는 "Fizz", 11의 배수 일때는 "Buzz", 5와 11의 공배수일 떄는 "FizzBuzz"를 출력하는 프로그램을 만드세요.*/

	int num1;
	int num2;

	scanf("%d %d", &num1, &num2);

	for (int i = num1; i <= num2; i++)
	{
		if (i % 5 == 0 && i % 11)
			printf("FizzBuzz\n");
		else if (i % 5 == 0)
			printf("Fizz\n");
		else if (i % 11 == 0)
			printf("Buzz\n");
		else
			printf("%d\n", i);
	}

	return 0;
}