#include <stdio.h>

int main()
{
	/*ǥ�� �Է����� ���� �� ���� �Էµʺ��.(ù ��° �Է� ���� ������ 1~1000, �ι�° �Է� ���� ������ 10~1000�̸� ô��° �Է� ���� �� ��° �Է� ������ �׻� �۽��ϴ�).
	ù ��° �������� �ι�° �������� ���ڸ� ����ϸ鼭 5�� ��� �϶��� "Fizz", 11�� ��� �϶��� "Buzz", 5�� 11�� ������� ���� "FizzBuzz"�� ����ϴ� ���α׷��� ���弼��.*/

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