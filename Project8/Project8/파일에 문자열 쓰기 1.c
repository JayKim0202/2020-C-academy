#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp = fopen("hello.txt", "w");		// hello.txt 파일을 쓰기 모드(w)로 열기
											// 파일 포인터를 반환
	fputs("Hello, world!", fp);		// 파일에 문자열 저장

	fclose(fp);

	return 0;
}