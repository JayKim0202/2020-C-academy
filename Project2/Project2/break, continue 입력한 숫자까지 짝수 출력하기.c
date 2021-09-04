#include <stdio.h>

int main()
{
	int count;

	scanf("%d", &count);

	for (int i = 1; i <= count; i++)
	{
		if (i % 2 != 0)
			continue; //i를 2로 나누었을 때 나머지가 0이 아니면 즉, 홀수이면 아래 코드를 실행하지 않고 건너뜀

			printf("%d\n", i);
	}

	return 0;
}