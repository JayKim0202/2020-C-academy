#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListBaseQueue.h"

#define MAX 10
#define BUCKET_NUM 10

void reset();
void bubble_sort();
void selection_sort();
void insertion_sort();
void merge_sort(int merge_arr[], int left, int right);
void merge_two_area(int merge_arr[], int left,int mid, int right);
void swap(int quick_arr[], int idx1, int idx2);
int partition(int quick_arr[], int left, int right);
void quick_sort(int quick_arr[], int left, int right);
void radix_sort(int radix_arr[], int num, int maxLen);


int arr[MAX] = { 0 };
int bubble_arr[MAX] = { 0 };
int selection_arr[MAX] = { 0 };
int insertion_arr[MAX] = { 0 };

int main()
{
	int menu;
	int merge_arr[MAX] = { 0 };
	int quick_arr[MAX] = { 0 };
	int radix_arr[MAX] = { 0 };

	while (1)
	{
		printf("1.�ʱ�ȭ 2.���� ���� 3.���� ���� 4.���� ���� 5.���� ���� 6.�� ���� 7.��� ���� 8.����\t");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			reset();
			break;
		case 2:
			bubble_sort();
			break;
		case 3:
			selection_sort();
			break;
		case 4:
			insertion_sort();
			break;
		case 5:
			for (int i = 0; i < MAX; i++)
				merge_arr[i] = arr[i];
			merge_sort(merge_arr, 0, sizeof(merge_arr)/sizeof(int) - 1);
			for (int k = 0; k < MAX; k++)
				printf("%d\n", merge_arr[k]);
			break;
		case 6:
			for (int i = 0; i < MAX; i++)
				quick_arr[i] = arr[i];
			quick_sort(quick_arr, 0, sizeof(quick_arr) / sizeof(int) - 1);
			for (int k = 0; k < MAX; k++)
				printf("%d\n", quick_arr[k]);
			break;
		case 7:
			for (int i = 0; i < MAX; i++)
				radix_arr[i] = arr[i];
			radix_sort(radix_arr, sizeof(radix_arr) / sizeof(int), 5);
			for (int k = 0; k < MAX; k++)
				printf("%d\n", radix_arr[k]);
			break;
		case 8:
			exit(0);
		}
	}
}

void reset()
{
	srand(time(NULL)); // �ʱ�ȭ

	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 1000;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}

	return;
}

void bubble_sort()
{
	int temp;

	for (int i = 0; i < MAX; i++)
	{
		bubble_arr[i] = arr[i];
	}

	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = 0; j < MAX - 1; j++)
		{
			if (bubble_arr[j] > bubble_arr[j + 1])
			{
				temp = bubble_arr[j];
				bubble_arr[j] = bubble_arr[j + 1];
				bubble_arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < MAX; i++)
	{
		printf("%d\n", bubble_arr[i]);
	}

	return;
}

void selection_sort()
{
	int temp;

	for (int i = 0; i < MAX; i++)
	{
		selection_arr[i] = arr[i];
	}

	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = 1; j < MAX; j++)
		{
			if (selection_arr[i] > selection_arr[j] && j > i)
			{
				temp = selection_arr[i];
				selection_arr[i] = selection_arr[j];
				selection_arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < MAX; i++)
	{
		printf("%d\n", selection_arr[i]);
	}

	return;
}

void insertion_sort()
{
	int insData;
	int i, j;

	for (int i = 0; i < MAX; i++)
	{
		insertion_arr[i] = arr[i];
	}

	for (i = 1; i < MAX; i++)
	{
		insData = insertion_arr[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (insertion_arr[j] > insData)
				insertion_arr[j + 1] = insertion_arr[j];
			else
				break;
		}
		insertion_arr[j + 1] = insData;
	}

	for (int i = 0; i < MAX; i++)
	{
		printf("%d\n", insertion_arr[i]);
	}

	return;
}

// ���� ����
void merge_sort(int merge_arr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		merge_sort(merge_arr, left, mid);
		merge_sort(merge_arr, mid + 1, right);

		merge_two_area(merge_arr, left, mid, right);
	}
}
void merge_two_area(int merge_arr[], int left, int mid, int right)
{
	int f_idx = left;
	int r_idx = mid + 1;
	int i;

	int* sort_arr = (int*)malloc(sizeof(int) * (right + 1));
	int s_idx = left;

	while (f_idx <= mid && r_idx <= right)
	{
		if (merge_arr[f_idx] <= merge_arr[r_idx])
			sort_arr[s_idx] = merge_arr[f_idx++];
		else
			sort_arr[s_idx] = merge_arr[r_idx++];

		s_idx++;
	}

	if (f_idx > mid)
	{
		for (i = r_idx; i <= right; i++, s_idx++)
			sort_arr[s_idx] = merge_arr[i];
	}
	else
	{
		for (i = f_idx; i <= mid; i++, s_idx++)
			sort_arr[s_idx] = merge_arr[i];
	}

	for (i = left; i <= right; i++)
		merge_arr[i] = sort_arr[i];


	free(sort_arr);
}

// �� ����
void swap(int quick_arr[], int idx1, int idx2)
{
	int temp = quick_arr[idx1];
	quick_arr[idx1] = quick_arr[idx2];
	quick_arr[idx2] = temp;
}
int partition(int quick_arr[], int left, int right)
{
	int pivot = quick_arr[left];	// �ǹ��� ��ġ�� ���� ����
	int low = left + 1;
	int high = right;

	while (low <= high)	// �������� ���� ������ �ݺ�
	{
		// �ǹ����� ū ���� ã�� ����
		while (pivot >= quick_arr[low] && low <= right)
			low++;		// low�� ���������� �̵�

		// �ǹ����� ���� ���� ã�� ����
		while (pivot <= quick_arr[high] && high >= (left + 1))
			high--;		// high�� �������� �̵�

		// �������� ���� ���¶�� swap ����
		if (low <= high)
			swap(quick_arr, low, high);
	}

	swap(quick_arr, left, high);	// �ǹ��� high�� ����Ű�� ��� ��ȯ
	return high;
}
void quick_sort(int quick_arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = partition(quick_arr, left, right);	// �ѷ� ������
		quick_sort(quick_arr, left, pivot - 1);			// ���� ������ ����
		quick_sort(quick_arr, pivot + 1, right);		// ������ ������ ����
	}
}

void radix_sort(int radix_arr[], int num, int maxLen)
{
	// �Ű����� maxLen���� ���Ĵ�� �� ���� �� �������� ���� ������ ����
	Queue buckets[BUCKET_NUM];
	int bi;
	int pos;
	int di;
	int divfac = 1;
	int radix;

	// �� 10���� ��Ŷ �ʱ�ȭ
	for (bi = 0; bi < BUCKET_NUM; bi++)
		QueueInit(&buckets[bi]);

	//���� �� �������� ���̸�ŭ �ݺ�
	for (pos = 0; pos < maxLen; pos++)
	{
		// ���Ĵ���� ����ŭ �ݺ�
		for (di = 0; di < num; di++)
		{
			// N��° �ڸ��� ���� ����
			radix = (radix_arr[di] / divfac) % 10;

			// ������ ���ڸ� �ٰŷ� ��Ŷ�� ������ ����
			Enqueue(&buckets[radix], radix_arr[di]);
		}

		for (int i = 0; i < MAX; i++)
			radix_arr[i] = 0;

		// ��Ŷ ����ŭ �ݺ�
		for (bi = 0, di = 0; bi < BUCKET_NUM; bi++)
		{
			// ��Ŷ�� ����� �� ������� �� ������ �ٽ� ridix_arr�� ����
			while (!QIsEmpty(&buckets[bi]))
				radix_arr[di++] = Dequeue(&buckets[bi]);
		}

		// N��° �ڸ��� ���� ������ ���� �������� ����
		divfac *= 10;
	}
}