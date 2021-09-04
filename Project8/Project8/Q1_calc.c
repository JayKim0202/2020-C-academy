#include "Q1_calc.h"

void mul(CALC_DATA* data)
{
	data->operate = '*';

	data->result = data->operand1 * data->operand2;
}