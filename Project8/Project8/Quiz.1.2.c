//다음 소스 코드를완성하여 디버그 메시지가 출력되게 만드세요(소스 코드와 같은 경로 debug.h헤더 파일이 있습니다).

#include <stdio.h>

#ifndef DEBUG
#define DEBUG
#endif 

#include "debug.h"

int main()
{
#if defined DEBUG && defined ENABLE_DEBUG_MESSAGE
	printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
#endif

	return 0;
}