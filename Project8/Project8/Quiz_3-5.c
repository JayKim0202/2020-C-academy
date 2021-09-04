//문자열이 저장된 hello1.txt 파일이 주어집니다.
//파일 처음부터 순방향으로 7바이트 지점에서 4바이트만큼 읽고, 파일 끝에서 역방향으로 6바이트 지점에서 2바이트만큼 읽은 값을 출력하는 프로그램을 만드세요.
//단, 읽은 문자열은 공백으로 띄우지 않고 붙여서 출력합니다.

//worlwo

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char buffer[30] = { 0, };

	FILE* fp = fopen("hello1.txt", "r");

	fseek(fp, 7, SEEK_SET);
	fread(buffer, 4, 1, fp);

	printf("%s", buffer);

	memset(buffer, 0, 30);

	fseek(fp, -6, SEEK_END);
	fread(buffer, 2, 1, fp);

	printf("%s\n", buffer);

	fclose(fp);

	return 0;
}