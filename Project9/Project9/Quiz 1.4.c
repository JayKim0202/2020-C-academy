//바이너리 형식으로 된 x820.bin 파일이 주어집니다. X850Firmware 구조체를 참조하여 x850.bin에 저장된 값을 출력하는 프로그램을 만드세요.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#pragma pack(push, 1)
struct X820Firmware {
	int serial;
	char mode;
	char desc[20];
	int version;
};
#pragma pack(pop)

int main()
{
	struct X820Firmware x1;

	FILE* fp = fopen("x850.bin", "rb");

	fread(&x1, sizeof(x1), 1, fp);
	
	printf("%d\n%c\n%s\n%d\n", x1.serial, x1.mode, x1.desc, x1.version);

	fclose(fp);

	return 0;
}