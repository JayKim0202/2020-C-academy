#include <stdio.h>
#include <stdlib.h>

int main()
{
	void* ptr = malloc(100); //100��ŭ �޸� �Ҵ�

	printf("%p\n", ptr);

	printf("%p\n", ptr + 1); //������ ����. void �����ʹ� ������ ������ �� �� ����.

	free(ptr);

	return 0;
}