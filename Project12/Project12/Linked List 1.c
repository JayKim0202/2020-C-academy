#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
	int num;
	char s[100];
	struct Data* ptr;
};

int main()
{
	struct Data d1;
	struct Data d2;
	struct Data d3;
	struct Data d4;
	struct Data d5;
	struct Data* d;

	d1.num = 10;
	strcpy(d1.s, "test1");

	d2.num = 20;
	strcpy(d2.s, "test2");

	d3.num = 30;
	strcpy(d3.s, "test3");

	d4.num = 40;
	strcpy(d4.s, "test4");

	d5.num = 50;
	strcpy(d5.s, "test5");
	
	d = &d1;
	printf("%d %s\n", d->num, d->s);

	d = &d2;
	printf("%d %s\n", d->num, d->s);

	d = &d3;
	printf("%d %s\n", d->num, d->s);

	d = &d4;
	printf("%d %s\n", d->num, d->s);

	d = &d5;
	printf("%d %s\n", d->num, d->s);

	return 0;
}