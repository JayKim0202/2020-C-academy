#include <stdio.h>		// printf �Լ��� ����� ��� ����
#include "print.h"		// CALC_DATA ����ü�� ����ϱ� ���� print.h ��� ���� ����
						// print.h�� clacdata.h�� �����ϰ� ����

void print(CALC_DATA* data)		// ��� ��� �Լ� ����
{
	printf("%d %c %d = %d\n",
		data->operand1,
		data->operate,
		data->operand2,
		data->result
	);
}