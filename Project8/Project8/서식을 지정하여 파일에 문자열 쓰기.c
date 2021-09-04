#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp = fopen("Hello.txt", "w");		// hello.txt 파일을 쓰기 모드(w)로 열기, 파일 포인터를 반환

	fprintf(fp, "%s %d\n", "Hello", 100);	// 서식을 지정하여 문자열을 파일에 저장

	fclose(fp);		//파일 포인터 닫기

	return 0;
}

//Project8 폴더에 텍스트 파일로 저장됨.