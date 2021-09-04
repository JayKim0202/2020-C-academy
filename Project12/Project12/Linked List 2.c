#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct Data {
	int num;
	char s[100];
	struct Data* p;
} Data;

int main()
{
	Data d1;
	Data d2;
	Data d3;
	Data d4;
	Data d5;

	d1.num = 10;
	strcpy(d1.s, "test1");
	d1.p = NULL;

	d2.num = 20;
	strcpy(d2.s, "test2");
	d2.p = NULL;

	d3.num = 30;
	strcpy(d3.s, "test3");
	d3.p = NULL;

	d4.num = 40;
	strcpy(d4.s, "test4");
	d4.p = NULL;

	d5.num = 50;
	strcpy(d5.s, "test5");
	d5.p = NULL;

	d1.p = &d2;
	d2.p = &d3;
	d3.p = &d4;
	d4.p = &d5;

	printf("%d %s\n", d1.num, d1.s);
	printf("%d %s\n", d1.p->num, d1.p->s);
	printf("%d %s\n", d2.p->num, d2.p->s);
	printf("%d %s\n", d3.p->num, d3.p->s);
	printf("%d %s\n", d4.p->num, d4.p->s);
	printf("\n");

	printf("%d %s\n", d1.num, d1.s);
	printf("%d %s\n", d1.p->num, d1.p->s);
	printf("%d %s\n", d1.p->p->num, d1.p->p->s);
	printf("%d %s\n", d1.p->p->p->num, d1.p->p->p->s);
	printf("%d %s\n", d1.p->p->p->p->num, d1.p->p->p->p->s);
	printf("\n");
	
	Data* ptr;

	ptr = &d1;
	printf("%d %s\n", ptr->num, ptr->s);
	ptr = d1.p;
	printf("%d %s\n", ptr->num, ptr->s);
	ptr = d2.p;
	printf("%d %s\n", ptr->num, ptr->s);
	ptr = d3.p;
	printf("%d %s\n", ptr->num, ptr->s);
	ptr = d4.p;
	printf("%d %s\n", ptr->num, ptr->s);
	printf("\n");

	ptr = &d1;
	printf("%d %s\n", ptr->num, ptr->s);
	ptr = ptr->p;
	printf("%d %s\n", ptr->num, ptr->s);
	ptr = ptr->p;
	printf("%d %s\n", ptr->num, ptr->s);
	ptr = ptr->p;
	printf("%d %s\n", ptr->num, ptr->s);
	ptr = ptr->p;
	printf("%d %s\n", ptr->num, ptr->s);
	printf("\n");

	ptr = &d1;
	printf("%d %s\n", ptr->num, ptr->s);
	while (1)
	{
		ptr = ptr->p;
		printf("%d %s\n", ptr->num, ptr->s);

		if (ptr->p == NULL)
			break;
	}

	return 0;
}