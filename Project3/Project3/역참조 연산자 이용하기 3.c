#include <stdio.h>

int main()
{
	int *numPtr;
	int num1 = 10;

	numPtr = num1; //컴파일 경고, numPtr은 int 포인터형이고 num1은 int형이라 자료형이 일치하지 않음.

	*numPtr = num1; //numPtr은 int형이고 num1도 int형이라 자료형이 일치함

	numPtr = &num1; //numPtr은 int 포인터형이고, &num1 은 int형 변수의 주소이므로 자료형이 일치함
	                //numPtr은 pointer to int, &num1은 address of int이므로 자료형이 일치함

	/* num1 == 변수는 메모리 주소를 몰라도 값을 가져오거나 저장할 수 있다.
	  &num1 == 주소 연산자(&)는 변수의 메모리 주소를 구한다.
	*numPtr == 역참조 연산자(*)는 메모리에 저장된 값에 접근할 수 있다.
			   즉, 메모리 주소에 접근하여 값을 가져오고 저장한다.
	 numPtr == 포인터는 변수의 메모리 주소만 가리킨다.*/
}