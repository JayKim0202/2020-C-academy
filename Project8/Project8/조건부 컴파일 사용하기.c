#include <stdio.h>

#define DEBUG

int main()
{
#ifdef DEBUG		//DEBUG ��ũ�ΰ� ���ǵǾ� �ִٸ� #ifdef, #endif ������ �ڵ带 ������
	printf("DebugL %s %s %s%d\n", __DATE__, __TIME__, __FILE__, __LINE__);
#endif

	return 0;
}