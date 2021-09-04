#include <stdio.h>

int main()
{
	int numArr[5] = { 11, 22, 33, 44, 55 };
	void* ptr = &numArr[2];	//세 번째 요소의 메모리 주소

	printf("%d\n", *(int*)ptr);			//33: 포인터 연산을 하지 않은 상태에서 역참조

	printf("%d\n", *((int*)ptr + 1));	//44
	printf("%d\n", *((int*)ptr - 1));	//22

	printf("%d\n", *(++(int*)ptr));		//44
	printf("%d\n", *(--(int*)ptr));		//33
	
	printf("%d\n", *(((int*)ptr)++));	//33
	printf("%d\n", *(((int*)ptr)--));	//44

	return 0;

}