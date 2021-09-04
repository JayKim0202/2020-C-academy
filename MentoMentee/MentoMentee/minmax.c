#include <stdio.h>

void MinMax(int* a, int* max, int* min, int size);

int main()
{
	int arr[] = { 2, 7, 8, 3, 9, 5, 0 };
	int min, max;
	int size = sizeof(arr) / sizeof(arr[0]);

	MinMax(&arr, &max, &min, size);

	printf("MAX = %d\n", max);
	printf("MIN = %d\n", min);

	return 0;
}

void MinMax(int* a, int* max, int* min, int size)
{
	*max = *a;
	for (int i = 1; i < size; i++)
		if (*max < *(a + i))
			*max = *(a + i);

	*min = *a;
	for (int i = 1; i < size; i++)
		if (*min > *(a + i))
			*min = *(a + i);
}