/*1.d
2.e
3.a,b,d*/

//다음 소스 코드를 완성항 RectangleFileFormat 구조체의 내용을 rect.bin 파일에 저장하세요.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#pragma pack(push, 1)
struct Point2D {
	float x;
	float y;
};

struct RectangleFileFormat {
	short magic;
	int version;
	struct Point2D p1;
	struct Point2D p2;
	char desc[30];
};
#pragma pack(pop)

int main()
{
	struct RectangleFileFormat rf;
	memset(&rf, 0, sizeof(rf));

	rf.magic = 're';
	rf.version = '1';
	rf.p1.x = 4.5f;
	rf.p1.y = 2.1f;
	rf.p2.x = 9.2f;
	rf.p2.y = 8.7f;
	strcpy(rf.desc, "Rectangle File Format");
	
	FILE* fp = fopen("rect.bin", "wb");

	fwrite(&rf, sizeof(rf), 1, fp);
	
	fclose(fp);

	return 0;
}