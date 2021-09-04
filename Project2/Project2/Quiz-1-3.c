#include <stdio.h>

int main()
{
	/*표준 입력으로 삼각형의 높이가 입력됩니다.(입력 값의 범위는 3~10). 입력된 높이칸큼 산 모양으로 변을 출력하는 프로그램을 만드세요.
	이때 출력 결과는 예제와 정확히 일치해야 합니다. 모양이 같더라도 공백이나 빈 줄이 더 들어가면 틀린 것으로 처리됩니다.*/

	int i;
	int j;
	int height; 

	scanf("%d", &height);

	for (i = 0; i < height; i++) 
	{
		for (j = 0; j <= (10 / 2) - i; j++)
		{
			printf(" ");
		}
		for (j = 10 / 2 - i; j <= (10 / 2) + i; j++)
		{
			printf("*");
		}

		printf("\n");
	}

	return 0;
}

/*for (j = 0; j <= height ; j++)
		{
			if (j )
				printf(" ");
			else if
				printf("*");
			else if
				printf(" ");
		}
		
		
		length = height + 2 * i*/