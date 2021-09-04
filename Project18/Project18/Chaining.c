#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _empInfo
{
	int empNum;		// 직원의 고유번호
	int age;		// 직원의 나이
} EmpInfo;

typedef struct node
{
	EmpInfo *ptr;
	struct node* next;
} NODE;

int get_hash_value(int empNum);
NODE* add_arr(EmpInfo emp);
EmpInfo *search(int emp);

NODE empInfoArr[100];

int main()
{
	EmpInfo emp1 = { 20120003, 42 };
	EmpInfo emp2 = { 20130003, 33 };
	EmpInfo emp3 = { 20170003, 27 };
	EmpInfo emp4 = { 20200003, 24 };

	EmpInfo r1, r2, r3, r4;

	empInfoArr[get_hash_value(emp1.empNum)] = *add_arr(emp1);
	empInfoArr[get_hash_value(emp2.empNum)] = *add_arr(emp2);
	empInfoArr[get_hash_value(emp3.empNum)] = *add_arr(emp3);
	empInfoArr[get_hash_value(emp4.empNum)] = *add_arr(emp4);

	r1 = *search(20120003);
	r2 = *search(20130003);
	r3 = *search(20170003);
	r4 = *search(20200003);

	printf("%d %d\n", r1.empNum, r1.age);
	printf("%d %d\n", r2.empNum, r2.age);
	printf("%d %d\n", r3.empNum, r3.age);
	printf("%d %d\n", r4.empNum, r4.age);
	return 0;
}

int get_hash_value(int empNum)
{
	return empNum % 100;
}

NODE* add_arr(EmpInfo emp)
{
	NODE* head = malloc(sizeof(NODE));
	NODE* tail;
	head->next = &empInfoArr[get_hash_value(emp.empNum)];
	tail = head;

	while (1)
	{
		if (tail->ptr == NULL || tail->next == NULL)break;
		tail = tail->next;
	}
	if (tail->ptr == NULL)
	{
		tail->ptr = malloc(sizeof(EmpInfo));
		tail->ptr->empNum = emp.empNum;
		tail->ptr->age = emp.age;
		tail->next = NULL;
	}
	else
	{
		tail->next = malloc(sizeof(NODE));
		tail = tail->next;
		tail->ptr = malloc(sizeof(EmpInfo));
		tail->ptr->empNum = emp.empNum;
		tail->ptr->age = emp.age;
		tail->next = NULL;
	}

	return head->next;
}

EmpInfo *search(int emp)
{
	while (1)
	{
		if (empInfoArr[get_hash_value(emp)].ptr->empNum == emp)
			return empInfoArr[get_hash_value(emp)].ptr;
		else
			empInfoArr[get_hash_value(emp)] = *empInfoArr[get_hash_value(emp)].next;
	}

}