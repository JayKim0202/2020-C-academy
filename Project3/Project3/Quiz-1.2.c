#include <stdio.h>

int main()
{
	/*���� �ҽ� �ڵ带 �Ϥ����Ͽ� 1���� 100������ ���ڸ� ����ϸ鼭 2�� ����� ���� "Fizz", 7�� ����� ���� "Buzz", 2�� 7�� ������� ���� "FizzBuzz"��
	��µǰ� ���弼��.*/

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