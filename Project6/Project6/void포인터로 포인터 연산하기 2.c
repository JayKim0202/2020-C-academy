#include <stdio.h>
#include <stdlib.h>

int main()
{
	void* ptr = malloc(100);

	printf("%p\n", ptr);			//메모리 주소.
	printf("%p\n", (int*)ptr + 1);	//다른 포인터로 변환한 뒤 포인터 연산
	printf("%p\n", (int*)ptr - 1);	

	void* ptr2 = ptr;				//메모리 주소를 변환 시킬 때는 다른 포인터에 보관
	printf("%p\n", ++(int*)ptr2);
	printf("%p\n", --(int*)ptr2);

	printf("%p\n", ((int*)ptr2)++);	
	printf("%p\n", ((int*)ptr2)--);

	free(ptr);

	return 0;
}