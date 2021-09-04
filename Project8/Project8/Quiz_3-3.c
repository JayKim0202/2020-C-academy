//다음 소스 코드를 완성하면서 hello1.txt 파일의 내용을 출력하면서 hello2.txt 파일로 복사되게 만드세요.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int count;
	char buffer[5] = { 0, };

	FILE* src = fopen("hello1.txt", "r");
	FILE* dest = fopen("hello2.txt", "w");

	while (feof(src) == 0)
	{
		count = fread(buffer, sizeof(char), 4, src);
		printf("%s", buffer);
		fwrite(buffer, sizeof(char), count, dest);
		memset(buffer, 0, 5);
	}

	fclose(dest);
	fclose(src);

	return 0;
}