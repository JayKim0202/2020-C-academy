#include <stdio.h>

int binary_search(int arr[], int size, int key)
{
	int low = 0;
	int high = size - 1;
	int middle;

	while (low <= high)
	{
		middle = (low + high) / 2;

		if (arr[middle] == key)
			return middle;
		else if (arr[middle] > key)
			high = middle - 1;
		else
			low = middle + 1;
	}

	return -1;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int key = 8;
	int index;

	index = binary_search(arr, sizeof(arr) / sizeof(arr[0]), key);

	printf("%d가 들어있는 인덱스는 %d입니다.", key, index);

	return 0;
}