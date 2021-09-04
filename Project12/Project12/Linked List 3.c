#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Data {
	int num;
	char str[100];
	struct Data* ptr;
};

int main()
{
	struct Data* d1 = malloc(sizeof(struct Data));
	struct Data* d2 = malloc(sizeof(struct Data));
	struct Data* d3 = malloc(sizeof(struct Data));
	struct Data* d4 = malloc(sizeof(struct Data));
	struct Data* d5 = malloc(sizeof(struct Data));
	struct Data* Ptr;

	d1->num = 10;
	strcpy(d1->str, "test1");
	d1->ptr = NULL;

	d2->num = 20;
	strcpy(d2->str, "test2");
	d2->ptr = NULL;

	d3->num = 30;
	strcpy(d3->str, "test3");
	d3->ptr = NULL;

	d4->num = 40;
	strcpy(d4->str, "test4");
	d4->ptr = NULL;

	d5->num = 50;
	strcpy(d5->str, "test5");
	d5->ptr = NULL;

	d1->ptr = d2;
	d2->ptr = d3;
	d3->ptr = d4;
	d4->ptr = d5;

	Ptr = d1;
	printf("%d %s", Ptr->num, Ptr->str);

	while (1)
	{
		Ptr = Ptr->ptr;
		printf("%d %s", Ptr->num, Ptr->str);

		if (Ptr->ptr == NULL)
			break;
	
	}


	free(d1);
	free(d2);
	free(d3);
	free(d4);
	free(d5);
	return 0;
}