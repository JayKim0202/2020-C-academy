#include <stdio.h>

extern int num1;	//�ٸ� �ҽ� ����(�ܺ�)�� �ִ� ���� ���� num1�� ���
extern void printNumber();

int main()
{
	printf("%d\n", num1);
	printNumber();

	return 0;
}

//extern main�� ����Ϸ��� extern print�� ���忡 �߰��ؾ� �Ѵ�.