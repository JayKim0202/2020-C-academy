//���̳ʸ� �������� �� x820.bin ������ �־����ϴ�. X850Firmware ����ü�� �����Ͽ� x850.bin�� ����� ���� ����ϴ� ���α׷��� ���弼��.
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