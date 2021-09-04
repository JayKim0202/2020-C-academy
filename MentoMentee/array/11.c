#include <stdio.h>

void merge(int* A, int* B, int* C, int size);

int main()
{
	int A[] = { 2,5,7,8 };
	int B[] = { 1,3,4,6 };
	int C[8] = { 0 };
	int size = sizeof(A) / sizeof(A[0]);

	printf("A[] = 2 5 7 8\n");
	printf("B[] = 1 3 4 6\n");
	merge(A, B, C, size);
	printf("C[] =");
	for (int i = 0; i < size * 2; i++)
	{
		printf(" %d", C[i]);
	}

	return 0;
}

void merge(int* A, int* B, int* C, int size)
{
	//	int a = b = c = 0;	// �ĺ��� "b"��(��) ���ǵǾ� ���� �ʽ��ϴ� // �ĺ��� "c"��(��) ���ǵǾ� ���� �ʽ��ϴ�
	int a, b, c;
	a = b = c = 0;

	while (a < size && b < size)
	{
		if (A[a] > B[b])
		{
			C[c] = B[b];
			c++; b++;
		}
		else if (A[a] < B[b])
		{
			C[c] = A[a];
			c++; a++;
		}
	}

	while (c < size * 2)
	{
		if (a > b)
		{
			C[c] = B[b];
			c++, b++;
		}
		else
		{
			C[c] = A[a];
			c++, a++;
		}
	}
}