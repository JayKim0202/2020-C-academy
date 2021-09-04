#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char* s1 = "Hello, world!";

	FILE* fp = fopen("hello.txt", "w");		// hello.txt 팡일을 쓰기 모드(w)로 열기
											// 파일 포일터를 반환

	fwrite(s1, strlen(s1), 1, fp);			//strlen으로 문자열의 길이를 구함.
											//문자열의 길이만큼 1번 파일에 저장

	fclose(fp);

	return 0;
}