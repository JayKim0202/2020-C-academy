#include <stdio.h>
#include "Q1_print.h"

void print(CALC_DATA* data)
{
	printf("%d %c %d = %d\n",
		data->operand1,
		data->operate,
		data->operand2,
		data->result
	);
}