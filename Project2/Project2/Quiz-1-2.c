#include <stdio.h>

int main()
{
	//다음 소스코드를 완성하여 역삼각형 모양으로 별이 출력되게 만드세요.

	int i;
	int j;
	
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (j < i)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}

	return 0;
}