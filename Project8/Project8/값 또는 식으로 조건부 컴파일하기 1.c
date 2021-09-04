#include <stdio.h>

#define DEBUG_LEVEL 2	//2를 DEBUG_LEVE로 정의

int main()
{
	
// DEBUG_LEVEL이 2보다 크거나 같으면 #if, #endif 사이의 코드를 컴파일
#if DEBUG_LEVEL >= 2
	printf("Debug Level 2\n");
#endif

#if 1	//조건이 항상 참이므로 #if, #endif 사이의 코드를 컴파일
	printf("1\n");
#endif

#if 0	//조건이 항상 거짓이므로 #if, #endif 상이의 코드를 컴파일 하지 않음.
	printf("0\n");
#endif

	return 0;
}