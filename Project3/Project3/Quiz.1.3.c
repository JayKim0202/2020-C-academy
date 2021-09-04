#include <stdio.h>

int main()
{
	//다음 소스 코드를 완성하여 배열에 저장된 2진수가 10진수로 출력되게 만드세요. 2진수는 배열에 순서대로 저장되어 있습니다.

	int decimal = 0;
	int binary[4] = { 1, 1, 0, 1 };
	int temp;
	
	for (int i = 3; i >= 0; i--) //4번 반복
	{
		temp = 1;

		for (int j = 0; j <= i-1; j++) //3번 반복
		{
			temp *= 2;                 //i = 3 : temp = 8,  i = 2: temp = 4, i = 1: temp = 2; i = 0: temp = 1
		}
		decimal += temp * binary[i]; //i = 3: 8 * 1, i = 2: 4 * 1, i = 1: 2 * 0, i = 0: 1 * 1;
	}


	printf("%d\n", decimal);

	return 0;
}



/*13

13 % 2 = 1
13 / 2 = 6

6 % 2 = 0
6 / 2 = 3

3 % 2 = 1
3 / 2 = 1

1 % 1 = 0
1 / 1 = 1

{ 1, 1, 0, 1}
*/

/*
1 1 0 1 = 1 * 2^3 + 1 * 2^2 + 0 * 2^1 + 1 * 2^0
*/