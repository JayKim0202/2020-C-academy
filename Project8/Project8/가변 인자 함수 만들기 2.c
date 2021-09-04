#include <stdio.h>
#include <stdarg.h>		// va_list, va_start, va_arg, va_end�� ���ǵ� ��� ����

void printNumbers(int args, ...)	// ���� ������ ������ ����, ...���� ���� ���� ����
{
	va_list ap;		// ���� ���� ��� ������

	va_start(ap, args);			// ���� ���� ��� ������ ����
	for (int i = 0; i < args; i++)		// ���� ���� ������ŭ �ݺ�
	{
		int num = va_arg(ap, int);		// int ũ�⸸ŭ ���� ���� ��� ���̆����� ���� ������
										// ap�� int ũ�⸸ŭ ���������� �̵�
		printf("%d ", num);				// ���� ���� �� ���
	}
	va_end(ap);		// ���� ���� ��� �����͸� NULL�� �ʱ�ȭ

	printf("\n");	// �ٹٲ�
}

int main()
{
	printNumbers(1, 10);
	printNumbers(2, 10, 20);
	printNumbers(3, 10, 20, 30);
	printNumbers(4, 10, 20, 30, 40);

	return 0;
}

/*
va_list: ���� ���� ���, ���� ������ �޸� �ּҸ� �����ϴ� �������Դϴ�.
va_start: ���� ���ڸ� ������ �� �ֵ��� �����͸� �����մϴ�.
va_arg: ���� ���� �����Ϳ��� Ư�� �ڷ��� ũ�⸸ŭ ���� �����ɴϴ�.
va_end: ���� ���� ó���� ������ �� �����͸� NULL�� �ʱ�ȭ�մϴ�.
*/