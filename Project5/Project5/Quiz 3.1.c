/*1.d
2.4
3.e
4.c*/

//다음 소스 코드를 완성하여 3이 출력되게 만드세요.

#include <stdio.h>

enum DEVICE_TYPE {
	DEVICE_PCI_EX = 2,
	DEVICE_IEEE1394,
	DEVICE_USB
};

int main()
{
	enum DEVICE_TYPE type;

	type = DEVICE_IEEE1394;

	printf("%d\n", type);

	return 0;
}