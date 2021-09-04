#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Data {
	int num1;
	int num2;
};

int main()
{
	void* ptr = malloc(sizeof(struct Data) * 3);
	struct Data d[3];

	((struct Data*)ptr)->num1 = 10;
	((struct Data*)ptr)->num2 = 20;

	((struct Data*)ptr + 1)->num1 = 30;
	((struct Data*)ptr + 1)->num2 = 40;

	((struct Data*)ptr + 2)->num1 = 50;
	((struct Data*)ptr + 2)->num2 = 60;

	memcpy(d, ptr, sizeof(struct Data) * 3);

	printf("%d %d\n", d[1].num1, d[1].num2);	//30 40
	printf("%d %d\n", ((struct Data*)ptr + 2)->num1, ((struct Data*)ptr + 2)->num2);	//50 60

	free(ptr);

	return 0;
}