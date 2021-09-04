//다음 소스 코드를 완성하여 X820Firmware 구조체의 내용을 stdout에 쓰도록 만드세요.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#pragma pack(push, 1)
struct X820Firmware {
	int serial;
	char desc[13];
	short tag;
	char mode;
};
#pragma pack(pop)

int main()
{
	struct X820Firmware x1;
	memset(&x1, 0, sizeof(x1));

	FILE* fp = stdout;

	x1.serial = 1800891002;
	strcpy(x1.desc, "X820 Firmware");
	x1.tag = 8512;
	x1.mode = '-';

	fwrite(&x1, sizeof(x1), 1, fp);

	fclose(fp);

	return 0;
}