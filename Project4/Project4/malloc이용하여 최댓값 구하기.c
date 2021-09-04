#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* numPtr = malloc(sizeof(int) * 5);
	int largestNumber;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &numPtr[i]);
	}

	/*scanf("%d", &numPtr[0]);
	scanf("%d", &numPtr[1]);
	scanf("%d", &numPtr[2]);
	scanf("%d", &numPtr[3]);
	scanf("%d", &numPtr[4]);
	*/


	largestNumber = numPtr[0];

	for (int i = 0; i < 5; i++)
	{
		if (numPtr[i] > largestNumber)
		{
			largestNumber = numPtr[i];
		}
	}

	printf("%d", largestNumber);

	free(numPtr);

	return 0;
}