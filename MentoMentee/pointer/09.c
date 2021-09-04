#include <stdio.h>

int search(int* A, int size, int search_value);

int main()
{
	int A[] = { 300, 200, 100, 400 };
	int size = sizeof(A) / sizeof(A[0]);
	int search_value = 200;
	printf("월금이 200만원인 사람의 인덱스=%d", search(A, size, search_value));

	return 0;
}

int search(int* A, int size, int search_value)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (A[i] == search_value)
			return i;
	}
}