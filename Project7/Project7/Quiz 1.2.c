//다음 소스 코드를 완성하여 "Saturn"과 "192.168.10.6"이 각 줄에 출력되게 만드세요.

#include <stdio.h>

void printHostname();
void printIPAddress();

int main()
{
	printHostname();
	printIPAddress();

	return 0;
}

void printHostname()
{
	printf("Saturn\n");
}

void printIPAddress()
{
	printf("192.168.10.6\n");
}