#include <stdio.h>

int main()
{
	/*다음 소스 코드를 완ㅅ어하여 1부터 100까지의 숫자를 출력하면서 2의 배수일 때는 "Fizz", 7의 배수일 때는 "Buzz", 2와 7의 공배수일 때는 "FizzBuzz"를
	출력되게 만드세요.*/

	for (int i = 0; i <+ 100; i++)
	{
		if (i % 2 == 0 && i % 7 == 0)
			printf("FizzBuzz\n");
		else if (i % 2 == 0)
			printf("Fizz\n");
		else if (i % 7 == 0)
			printf("Buzz\n");
		else
			printf("%d\n", i);
	}

	return 0;
}