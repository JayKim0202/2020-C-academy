#include <stdio.h>
#include <stdlib.h>

int* ten()
{
	int* numPtr = malloc(sizeof(int));

	*numPtr = 10;

	return numPtr;	//������ ��ȯ, malloc���� �޸𸮸� �Ҵ��ϸ� �Լ��� ������ ������� ����
}

int main()
{
	int* numPtr;
	
	numPtr = ten();

	printf("%d\n", *numPtr);	//10 : �޸𸮸� �����ϱ� ������ ������

	free(numPtr);		//�ٸ� �Լ����� �Ҵ��� �޸�� �ݵ�� �����ؾ� ��.

	return 0;
}