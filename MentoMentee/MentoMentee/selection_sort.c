#include <stdio.h>

void selection_sort(int arr[], int size) {
	int temp;
	int least;

	for (int i = 0; i < size - 1; i++)
	{
		least = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[least])
				least = j;
		}
		temp = arr[i];
		arr[i] = arr[least];
		arr[least] = temp;
	}
}

int main()
{
	int arr[] = { 5,4,7,8,6,9,2,3 };

	selection_sort(arr, sizeof(arr) / sizeof(arr[0]));

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		printf("%d ", arr[i]);

	return 0;
}