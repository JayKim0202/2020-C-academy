#include "Q2_append.h"
#include "Q2_print.h"

int main()
{
	DATA data = { 0, };

	append(&data, "The", "Little Prince");
	print(&data);

	return 0;
}