// ǥ�� �Է����� �޸� �ּҰ� �Էµ˴ϴ�. ���� �ҽ� �ڵ帣�ξȼ��Ͽ� �Էµ� �޸� �ּҿ��� ���������� 6����Ʈ, 10����Ʈ ��ŭ ������ �޸� �ּҰ� �� �ٿ� ��µǰ� ���弼��.

#define _CRT_SECUR_NO_WARNINGS
#include <stdio.h>

int main()
{
	short* numPtrA;
	short* numPtrB;
	short* numPtrC;

	scanf("%p", &numPtrA);

	numPtrB = numPtrA + 3;
	numPtrC = numPtrA + 5;

	printf("%x\n", numPtrB);
	printf("%x\n", numPtrC);

	return 0;
}