/*1.d
2.c
3.b
4.e*/

//다음 소스 코드를 완성하여 두 값 중 작은 값과 큰 값이 출력되게 만드세요.
//MIN, MAX매크로 정의하기
#include <stdio.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main()
{
	printf("%d\n", MIN(10, 20));
	printf("%d\n", MAX(4 & 4, 2 & 2));

	return 0;
}