// ㅂ + 한자키 (한문자당 두칸)

#include <stdio.h>
#include <Windows.h>

int main()
{
	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 8;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("┌");

	for (int i = 0; i < 100; i++)
	{
		printf("─");
	}

	printf("┐");


	coord.X = 8;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 15; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("└");

	for (int i = 0; i < 100; i++)
	{
		printf("─");
	}

	coord.X = 109;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 15; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("┘");

	return 0;
}