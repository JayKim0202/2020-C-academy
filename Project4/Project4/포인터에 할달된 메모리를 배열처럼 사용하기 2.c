#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numArr[10];								//int�� ��� 10���� ���� �迭 ����
	int* numPtr = malloc(sizeof(int) * 10);		//int 10�� ũ�⸸ŭ �޸� �Ҵ�

	numArr[0] = 10;		//�迭�� �ε����� �����Ͽ� �� �Ҵ�
	numArr[0] = 10;		//�����͸� �ε����� �����Ͽ� �� �Ҵ�

	free(numPtr);		//�޸� ����

	return 0;
}