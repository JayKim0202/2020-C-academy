//다음 소스 코드를 오나성하여 "Mercury"와 87.969002 115.877602가 각 줄에 출력되게 만드세요.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* allocMemory()
{
	void* ptr = malloc(100);

	return ptr;
}


int main()
{
	char* name;
	float* stats;

	name = allocMemory();
	strcpy(name, "Mercury");
	printf("%s\n", name);
	free(name);

	stats = allocMemory();
	stats[0] = 87.969f;
	stats[1] = 115.8776f;
	printf("%f %f\n", stats[0], stats[1]);
	free(stats);

	return 0;
}