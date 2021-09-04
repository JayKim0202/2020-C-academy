#include <stdio.h>

#define DEBUG

int main()
{
#ifdef DEBUG		//DEBUG 매크로가 정의되어 있다면 #ifdef, #endif 사이의 코드를 컴파일
	printf("DebugL %s %s %s%d\n", __DATE__, __TIME__, __FILE__, __LINE__);
#endif

	return 0;
}