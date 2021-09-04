#include "calc-H.h"

void add(CALC_DATA* data)
{
	data->operate = '+';

	data->result = data->operand1 + data->operand2;
}

void suv(CALC_DATA* data)
{
	data->operate = '-';

	data->result = data->operand1 - data->operand2;
}