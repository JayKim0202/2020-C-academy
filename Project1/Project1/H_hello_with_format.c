#include <stdio.h>

int main()
{

	printf("%s %s\n", "Hello", "1234"); //Hello 1234
	printf("%s %s\n", "Hello,", "1234"); //Hello, 1234
	printf("%s, %s\n", "Hello", "1234"); //Hello, 1234
	printf("%s, %s\n", "Hello,", "1234"); //Hello,, 1234
	printf("%s%s\n", "Hello", "1234"); //Hello1234
	printf("%s%s\n", "Hello ", "1234"); //Hello 1234
	printf("%s%s\n", "Hello", " 1234"); //Hello 1234
	printf("Hello, %s\n", "1234"); //Hello, 1234
	printf("%s1234", "Hello, "); //HEllo,1234

	return 0;
}