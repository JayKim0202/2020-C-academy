/*
24비트 비트맵 파일 sample.bmp가 주어집니다(최대 파일 크기 200KB 이하, 최대 해상도 200x200 이하).
비트맵 파일을 아스키 아트로 출력하는 프로그램을 완성하세요
결과는 파일 쓰기 함수로 stdout에 저장하거나 표준 출력 함수를 사용하여 출력하면 됩니다.
사용해야 할 ASCII 문자의 배열은 다음과 같습니다.
픽셀당 ASCII 문자를 하나만 출력하세요.
또한, RGB값의 평균값을 ASCII 문자로 대웅 시키세요*/

//char ascii[] = { '9', '8', '7', '6', '5', '4', '3', '2', '1', '0', ' ' };


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)

#pragma pack(push, 1)

typedef struct _BITMAPFILEHEADER
{
	unsigned short bfType;
	unsigned int bfSize;
	unsigned short bfReserved1;
	unsigned short bfReseved2;
	unsigned int bfOffBits;
} BITMAPFILEHEADER;

typedef struct _BITMAPINFOHEADER
{
	unsigned int biSize;
	int biWidth;
	int biHeight;
	unsigned short biPlanes;
	unsigned short biBitCount;
	unsigned int biCompression;
	unsigned int biSizeImage;
	int biXPelsPerMeter;
	int biYPersPerMeter;
	unsigned int biClrUsed;
	unsigned int biClrImportnat;
} BITMAPINFOHEADER;

typedef struct _RGBTRIPLE
{
	unsigned char rgbtBlue;
	unsigned char rgbGreen;
	unsigned char rgbtRed;
} RGBTRIPLE;

#pragma pack(pop)

#define PIXEL_SIZE 3
#define PIXEL_ALIGN 4

int main()
{
	FILE* fpBmp;
	FILE* fpTxt;
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;

	unsigned char* image;
	int size;
	int width, height;
	int padding;

	char ascii[] = { '9', '8', '7', '6', '5', '4', '3', '2', '1', '0', ' ' };

	fpBmp = fopen("Peppers80x80.bmp", "rb");
	if (fpBmp == NULL)
		return 0;

	if (fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fpBmp) < 1)
	{
		fclose(fpBmp);
		return 0;
	}

	if (fileHeader.bfType != 'MB')
	{
		fclose(fpBmp);
		return 0;
	}

	if (fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fpBmp) < 1)
	{
		fclose(fpBmp);
		return 0;
	}

	if (infoHeader.biBitCount != 24)
	{
		fclose(fpBmp);
		return 0;
	}

	size = infoHeader.biSizeImage;
	width = infoHeader.biWidth;
	height = infoHeader.biHeight;

	padding = (PIXEL_ALIGN - ((width * PIXEL_SIZE) % PIXEL_ALIGN)) % PIXEL_ALIGN;

	if (size == 0)
	{
		size = (width * PIXEL_SIZE + padding) * height;
	}

	image = malloc(size);

	fseek(fpBmp, fileHeader.bfOffBits, SEEK_SET);

	if (fread(image, size, 1, fpBmp) < 1)
	{
		fclose(fpBmp);
		return 0;
	}

	fclose(fpBmp);

	fpTxt = fopen("ascii3.txt", "w");
	if (fpTxt == NULL)
	{
		free(image);
		return 0;
	}

	for (int y = height - 1; y >= 0; y--)
	{
		for (int x = 0; x < width; x++)
		{
			int index = (x * PIXEL_SIZE) + (y * (width * PIXEL_SIZE)) + (padding * y);

			RGBTRIPLE* pixel = (RGBTRIPLE*)&image[index];

			unsigned char blue = pixel->rgbtBlue;
			unsigned char green = pixel->rgbGreen;
			unsigned char red = pixel->rgbtRed;

			unsigned char gray = (red + green + blue) / PIXEL_SIZE;

			char c = ascii[gray * sizeof(ascii) / 256];

			fprintf(fpTxt, "%c%c", c, c);
		}

		fprintf(fpTxt, "\n");
	}

	fclose(fpTxt);

	free(image);

	return 0;
}
