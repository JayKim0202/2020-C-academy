//다음 소스 코드를 완성하여 0x3344가 출력되게 만드세요.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* numPtr1 = malloc(sizeof(int));
	short* numPtr2;

	*numPtr1 = 0x11223344;

	numPtr2 = (short *)numPtr1;

	printf("0x%x\n", *numPtr2);

	free(numPtr1);

	return 0;
}