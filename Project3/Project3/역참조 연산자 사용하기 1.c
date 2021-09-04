#include <stdio.h>

int main()
{
	//*포인터 == 포인터에 저장된 주소의 값

	int* numPtr; //포인터 변수 선언
	int num1 = 10; //정수형 변수를 선언하고 10 저장

	numPtr = &num1;//num1의 메모리 주소를 포인터 변수에 저장

	printf("%d\n", *numPtr); //10: 역참조 연산자로 num1의 메모리 주소에 접근하여 값을 가져옴

	/*int *numPtr == 포인터. 포인터를 선언할때
	printf("%d\n", *numPtr) == 역참조. 포인터에 사용할떄*/

	return 0;
}