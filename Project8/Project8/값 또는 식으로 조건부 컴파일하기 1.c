#include <stdio.h>

#define DEBUG_LEVEL 2	//2�� DEBUG_LEVE�� ����

int main()
{
	
// DEBUG_LEVEL�� 2���� ũ�ų� ������ #if, #endif ������ �ڵ带 ������
#if DEBUG_LEVEL >= 2
	printf("Debug Level 2\n");
#endif

#if 1	//������ �׻� ���̹Ƿ� #if, #endif ������ �ڵ带 ������
	printf("1\n");
#endif

#if 0	//������ �׻� �����̹Ƿ� #if, #endif ������ �ڵ带 ������ ���� ����.
	printf("0\n");
#endif

	return 0;
}