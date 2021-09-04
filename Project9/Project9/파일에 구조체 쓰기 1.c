#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#pragma pack(push, 1)	// 1바이트 크기로 정렬
struct Data
{
	short num1;		// 2바이트
	short num2;		// 2바이트
	short num3;		// 2바이트
	short num4;		// 2바이트
};
#pragma pack(pop)	// 정렬 설정을 이전 상태(기본값)로 되돌림

int main()
{
	struct Data d1;

	d1.num1 = 100;
	d1.num2 = 200;
	d1.num3 = 300;
	d1.num4 = 400;

	FILE* fp = fopen("data.bin", "wb");

	fwrite(&d1, sizeof(d1), 1, fp);

	fclose(fp);

	return 0;
}